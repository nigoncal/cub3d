
#include "../includes/cub3d.h"
//#include "mlx/mlx.h"
//#include "key_macros.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17
#define texWidth 64
#define texHeight 64
#define width 1280
#define height 720


void draw(t_info *info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < height)
	{
		while (x < width)
		{
			info->img.data[y * width + x] = info->game.buf[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}
void tex_orientation(t_info *info)
{
	if (info->game.side == 0 && info->game.raydir_x < 0) //NO
		info->game.texdir = 0;
	if (info->game.side == 0 && info->game.raydir_x >= 0) // S
		info->game.texdir = 1;
	if (info->game.side == 1 && info->game.raydir_y < 0) // WE
		info->game.texdir = 2;
	if (info->game.side == 1 && info->game.raydir_y >= 0) // EA
		info->game.texdir = 3;
	if (info->game.side == 0)
		info->game.wall_x = info->game.pos_y + info->game.perpwalldist * info->game.raydir_y;
	else
		info->game.wall_x = info->game.pos_x + info->game.perpwalldist * info->game.raydir_x;
	info->game.wall_x -= floor((info->game.wall_x)); // info->game.wall_x = 15.3 devient info->game.wall_x = 0.3
}
void calc(t_info *info)
{
	int x;
	int y;

	x = 0;
	while (x < width)
	{
		info->game.camera_x = 2 * x / (double)width - 1;
		info->game.raydir_x = info->game.dir_x + info->game.planeX * info->game.camera_x;
		info->game.raydir_y = info->game.dir_y + info->game.planeY * info->game.camera_x;

		info->game.map_x = (int)info->game.pos_x;
		info->game.map_y = (int)info->game.pos_y;

		 info->game.deltadist_x = fabs(1 / info->game.raydir_x);
		 info->game.deltadist_y = fabs(1 / info->game.raydir_y);

		info->game.hit = 0; //was there a wall hit?
		if (info->game.raydir_x < 0)
		{
			info->game.step_x = -1;
			info->game.sidedist_x = (info->game.pos_x - info->game.map_x) * info->game.deltadist_x;
		}
		else
		{
			info->game.step_x = 1;
			info->game.sidedist_x = (info->game.map_x + 1.0 - info->game.pos_x) * info->game.deltadist_x;
		}
		if (info->game.raydir_y < 0)
		{
			info->game.step_y = -1;
			info->game.sidedist_y = (info->game.pos_y - info->game.map_y) * info->game.deltadist_y;
		}
		else
		{
			info->game.step_y = 1;
			info->game.sidedist_y = (info->game.map_y + 1.0 - info->game.pos_y) * info->game.deltadist_y;
		}
		dda(info);
		if (info->game.side == 0)
			info->game.perpwalldist = (info->game.map_x - info->game.pos_x + (1 - info->game.step_x) / 2) / info->game.raydir_x;
		else
			info->game.perpwalldist = (info->game.map_y - info->game.pos_y + (1 - info->game.step_y) / 2) / info->game.raydir_y;
		//Calculate height of line to draw on screen
		info->game.lineheight = (int)(height / info->game.perpwalldist);
		info->game.drawstart = -info->game.lineheight / 2 + height / 2;
		if (info->game.drawstart < 0)
			info->game.drawstart = 0;
		//int drawEnd = info->game.lineheight / 2 + height / 2;
		 info->game.drawend = info->game.lineheight / 2 + height / 2;
		if (info->game.drawend >= height || info->game.drawend < 0)
			info->game.drawend = height - 1;
		// calculate value of info->game.wall_x
		if (info->game.side == 0)
			info->game.wall_x = info->game.pos_y + info->game.perpwalldist * info->game.raydir_y;
		else
			info->game.wall_x = info->game.pos_x + info->game.perpwalldist * info->game.raydir_x;
		info->game.wall_x -= floor(info->game.wall_x);
		// Choosing a texture in the texture tab
		tex_orientation(info);
		// x coordinate on the texture
		int texX = (int)(info->game.wall_x * (double)texWidth);
		if (info->game.side == 0 && info->game.raydir_x > 0)
			texX = texWidth - texX - 1;
		if (info->game.side == 1 && info->game.raydir_y < 0)
			texX = texWidth - texX - 1;
		// How much to increase the texture coordinate perscreen pixel
		double step = 1.0 * texHeight / info->game.lineheight;
		// Starting texture coordinate
		double texPos = (info->game.drawstart - height / 2 + info->game.lineheight / 2) * step;
		y = info->game.drawstart;
		while (y < info->game.drawend)
		{
			y++;
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			int color = info->game.texture[info->game.texdir][texHeight * texY + texX];
			// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (info->game.side == 1)
				color = (color >> 1) & 8355711;
			info->game.buf[y][x] = color;
		}
		y = 0;
		while (y < info->game.drawstart)
		{
			info->game.buf[y][x] = 0x77b5fe;
			y++;
		}
		y = info->game.drawend;
		while (y < height)
		{
			info->game.buf[y][x] = 0x808000;
			y++;
		}
		x++;
	}
}
int main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}


int key_press(int key, t_info *info)
{
	if (key == K_W)
	{
		if (info->map[(int)(info->game.pos_y)][(int)(info->game.pos_y + info->game.dir_y * info->game.movespeed)] == '0')
			info->game.pos_y += info->game.dir_y * info->game.movespeed;
		if (info->map[(int)(info->game.pos_x + info->game.dir_x * info->game.movespeed)][(int)(info->game.pos_y)] == '0')
			info->game.pos_x += info->game.dir_x * info->game.movespeed;
	}
	//move backwards if no wall behind you
	if (key == K_S)
	{
		if (info->map[(int)(info->game.pos_y)][(int)(info->game.pos_x - info->game.dir_x * info->game.movespeed)] == '0')
			info->game.pos_x -= info->game.dir_x * info->game.movespeed;
		if (info->map[(int)(info->game.pos_y - info->game.dir_y * info->game.movespeed)][(int)(info->game.pos_x)] == '0')
			info->game.pos_y -= info->game.dir_y * info->game.movespeed;
	}
	//rotate to the right
	if (key == K_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->game.dir_x;
		info->game.dir_x = info->game.dir_x * cos(-info->game.rotspeed) - info->game.dir_y * sin(-info->game.rotspeed);
		info->game.dir_y = oldDirX * sin(-info->game.rotspeed) + info->game.dir_y * cos(-info->game.rotspeed);
		double oldPlaneX = info->game.planeX;
		info->game.planeX = info->game.planeX * cos(-info->game.rotspeed) - info->game.planeY * sin(-info->game.rotspeed);
		info->game.planeY = oldPlaneX * sin(-info->game.rotspeed) + info->game.planeY * cos(-info->game.rotspeed);
	}
	//rotate to the left
	if (key == K_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->game.dir_x;
		info->game.dir_x = info->game.dir_x * cos(info->game.rotspeed) - info->game.dir_y * sin(info->game.rotspeed);
		info->game.dir_y = oldDirX * sin(info->game.rotspeed) + info->game.dir_y * cos(info->game.rotspeed);
		double oldPlaneX = info->game.planeX;
		info->game.planeX = info->game.planeX * cos(info->game.rotspeed) - info->game.planeY * sin(info->game.rotspeed);
		info->game.planeY = oldPlaneX * sin(info->game.rotspeed) + info->game.planeY * cos(info->game.rotspeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}

void load_image(t_info *info, int *texture, char *path, t_img *img_)
{
	int y;
	int x;
	y = 0;
	x = 0;
	img_->img = mlx_xpm_file_to_image(info->mlx, path, &img_->img_width, &img_->img_height);
	img_->data = (int *)mlx_get_data_addr(img_->img, &img_->bpp, &img_->size_l, &img_->endian);
	while (y < img_->img_height)
	{
		while (x < img_->img_width)
		{
			texture[img_->img_width * y + x] = img_->data[img_->img_width * y + x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(info->mlx, img_->img);
}
void load_texture(t_info *info)
{
	t_img img;
	load_image(info, info->game.texture[0], "textures/eagle.xpm", &img);
	load_image(info, info->game.texture[1], "textures/redbrick.xpm", &img);
	load_image(info, info->game.texture[2], "textures/purplestone.xpm", &img);
	load_image(info, info->game.texture[3], "textures/greystone.xpm", &img);
}
int graph_main(t_info *info)
{
	//t_info info;
	info->mlx = mlx_init();
	info->game.dir_x = -1;
	info->game.dir_y = 0.0;
	info->game.planeX = 0.0;
	info->game.planeY = 0.66;
	info->game.movespeed = 0.05;
	info->game.rotspeed = 0.05;



	if(!(alloc_storage(info)))
		return(0);
	load_texture(info);

	info->win = mlx_new_window(info->mlx, width, height, "mlx");

	info->img.img = mlx_new_image(info->mlx, width, height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);

	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &key_press, info);
	mlx_loop(info->mlx);
	return (0);
}

int		alloc_storage(t_info *info)
{
	int j;
	int i;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			info->game.buf[i][j] = 0;
			j++;
		}
		i++;
	}

	if (!(info->game.texture = (int **)wrmalloc(sizeof(int *) * 4)))
       		 return (-1);
	i = 0;
	while (i < 4)
	{
		if (!(info->game.texture[i] = (int *)wrmalloc(sizeof(int) * (texHeight * texWidth))))
			return (-1);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < texHeight * texWidth)
		{
			info->game.texture[i][j] = 0;
			j++;
		}
		i++;
	}
	init_buf(info);
	return(1);
}


void	init_buf(t_info *info)
{
	int j;
	int i;
	i = 0;
	
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			info->game.buf[i][j] = 0;
			j++;
		}
		i++;
	}
}