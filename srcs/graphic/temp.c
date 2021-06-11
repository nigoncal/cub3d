
#include "../../includes/cub3d.h"
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


void draw(t_setup *setup)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < height)
	{
		while (x < width)
		{
			setup->img.data[y * width + x] = setup->game.buf[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(setup->mlx, setup->win, setup->img.img, 0, 0);
}
void tex_orientation(t_setup *setup)
{
	if (setup->game.side == 0 && setup->game.raydir_x < 0) //NO
		setup->game.texdir = 0;
	if (setup->game.side == 0 && setup->game.raydir_x >= 0) // S
		setup->game.texdir = 1;
	if (setup->game.side == 1 && setup->game.raydir_y < 0) // WE
		setup->game.texdir = 2;
	if (setup->game.side == 1 && setup->game.raydir_y >= 0) // EA
		setup->game.texdir = 3;
	if (setup->game.side == 0)
		setup->game.wall_x = setup->game.pos_y + setup->game.perpwalldist * setup->game.raydir_y;
	else
		setup->game.wall_x = setup->game.pos_x + setup->game.perpwalldist * setup->game.raydir_x;
	setup->game.wall_x -= floor((setup->game.wall_x)); // setup->game.wall_x = 15.3 devient setup->game.wall_x = 0.3
}
void calc(t_setup *setup)
{
	int x;
	int y;

	x = 0;
	while (x < width)
	{
		setup->game.camera_x = 2 * x / (double)width - 1;
		setup->game.raydir_x = setup->game.dir_x + setup->game.planeX * setup->game.camera_x;
		setup->game.raydir_y = setup->game.dir_y + setup->game.planeY * setup->game.camera_x;

		setup->game.map_x = (int)setup->game.pos_x;
		setup->game.map_y = (int)setup->game.pos_y;

		 setup->game.deltadist_x = fabs(1 / setup->game.raydir_x);
		 setup->game.deltadist_y = fabs(1 / setup->game.raydir_y);

		setup->game.hit = 0; //was there a wall hit?
		if (setup->game.raydir_x < 0)
		{
			setup->game.step_x = -1;
			setup->game.sidedist_x = (setup->game.pos_x - setup->game.map_x) * setup->game.deltadist_x;
		}
		else
		{
			setup->game.step_x = 1;
			setup->game.sidedist_x = (setup->game.map_x + 1.0 - setup->game.pos_x) * setup->game.deltadist_x;
		}
		if (setup->game.raydir_y < 0)
		{
			setup->game.step_y = -1;
			setup->game.sidedist_y = (setup->game.pos_y - setup->game.map_y) * setup->game.deltadist_y;
		}
		else
		{
			setup->game.step_y = 1;
			setup->game.sidedist_y = (setup->game.map_y + 1.0 - setup->game.pos_y) * setup->game.deltadist_y;
		}
		while (setup->game.hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (setup->game.sidedist_x < setup->game.sidedist_y)
			{
				setup->game.sidedist_x += setup->game.deltadist_x;
				setup->game.map_x += setup->game.step_x;
				setup->game.side = 0;
			}
			else
			{
				setup->game.sidedist_y += setup->game.deltadist_y;
				setup->game.map_y += setup->game.step_y;
				setup->game.side = 1;
			}
			//Check in map if ray has setup->game.hit a wall
			if (setup->map[setup->game.map_y][setup->game.map_x] != 'V')
				setup->game.hit = 1;
		}
		if (setup->game.side == 0)
			setup->game.perpwalldist = (setup->game.map_x - setup->game.pos_x + (1 - setup->game.step_x) / 2) / setup->game.raydir_x;
		else
			setup->game.perpwalldist = (setup->game.map_y - setup->game.pos_y + (1 - setup->game.step_y) / 2) / setup->game.raydir_y;
		//Calculate height of line to draw on screen
		setup->game.lineheight = (int)(height / setup->game.perpwalldist);
		setup->game.drawstart = -setup->game.lineheight / 2 + height / 2;
		if (setup->game.drawstart < 0)
			setup->game.drawstart = 0;
		//int drawEnd = setup->game.lineheight / 2 + height / 2;
		 setup->game.drawend = setup->game.lineheight / 2 + height / 2;
		if (setup->game.drawend >= height || setup->game.drawend < 0)
			setup->game.drawend = height - 1;
		// calculate value of setup->game.wall_x
		if (setup->game.side == 0)
			setup->game.wall_x = setup->game.pos_y + setup->game.perpwalldist * setup->game.raydir_y;
		else
			setup->game.wall_x = setup->game.pos_x + setup->game.perpwalldist * setup->game.raydir_x;
		setup->game.wall_x -= floor(setup->game.wall_x);
		// Choosing a texture in the texture tab
		tex_orientation(setup);
		// x coordinate on the texture
		int texX = (int)(setup->game.wall_x * (double)texWidth);
		if (setup->game.side == 0 && setup->game.raydir_x > 0)
			texX = texWidth - texX - 1;
		if (setup->game.side == 1 && setup->game.raydir_y < 0)
			texX = texWidth - texX - 1;
		// How much to increase the texture coordinate perscreen pixel
		double step = 1.0 * texHeight / setup->game.lineheight;
		// Starting texture coordinate
		double texPos = (setup->game.drawstart - height / 2 + setup->game.lineheight / 2) * step;
		y = setup->game.drawstart;
		while (y < setup->game.drawend)
		{
			y++;
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			int color = setup->game.texture[setup->game.texdir][texHeight * texY + texX];
			// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (setup->game.side == 1)
				color = (color >> 1) & 8355711;
			setup->game.buf[y][x] = color;
		}
		y = 0;
		while (y < setup->game.drawstart)
		{
			setup->game.buf[y][x] = 0x77b5fe;
			y++;
		}
		y = setup->game.drawend;
		while (y < height)
		{
			setup->game.buf[y][x] = 0x808000;
			y++;
		}
		x++;
	}
}
int main_loop(t_setup *setup)
{
	calc(setup);
	draw(setup);
	return (0);
}


int key_press(int key, t_setup *setup)
{
	if (key == K_W)
	{
		if (setup->map[(int)(setup->game.pos_y)][(int)(setup->game.pos_y + setup->game.dir_y * setup->game.movespeed)] == '0')
			setup->game.pos_y += setup->game.dir_y * setup->game.movespeed;
		if (setup->map[(int)(setup->game.pos_x + setup->game.dir_x * setup->game.movespeed)][(int)(setup->game.pos_y)] == '0')
			setup->game.pos_x += setup->game.dir_x * setup->game.movespeed;
	}
	//move backwards if no wall behind you
	if (key == K_S)
	{
		if (setup->map[(int)(setup->game.pos_y)][(int)(setup->game.pos_x - setup->game.dir_x * setup->game.movespeed)] == '0')
			setup->game.pos_x -= setup->game.dir_x * setup->game.movespeed;
		if (setup->map[(int)(setup->game.pos_y - setup->game.dir_y * setup->game.movespeed)][(int)(setup->game.pos_x)] == '0')
			setup->game.pos_y -= setup->game.dir_y * setup->game.movespeed;
	}
	//rotate to the right
	if (key == K_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = setup->game.dir_x;
		setup->game.dir_x = setup->game.dir_x * cos(-setup->game.rotspeed) - setup->game.dir_y * sin(-setup->game.rotspeed);
		setup->game.dir_y = oldDirX * sin(-setup->game.rotspeed) + setup->game.dir_y * cos(-setup->game.rotspeed);
		double oldPlaneX = setup->game.planeX;
		setup->game.planeX = setup->game.planeX * cos(-setup->game.rotspeed) - setup->game.planeY * sin(-setup->game.rotspeed);
		setup->game.planeY = oldPlaneX * sin(-setup->game.rotspeed) + setup->game.planeY * cos(-setup->game.rotspeed);
	}
	//rotate to the left
	if (key == K_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = setup->game.dir_x;
		setup->game.dir_x = setup->game.dir_x * cos(setup->game.rotspeed) - setup->game.dir_y * sin(setup->game.rotspeed);
		setup->game.dir_y = oldDirX * sin(setup->game.rotspeed) + setup->game.dir_y * cos(setup->game.rotspeed);
		double oldPlaneX = setup->game.planeX;
		setup->game.planeX = setup->game.planeX * cos(setup->game.rotspeed) - setup->game.planeY * sin(setup->game.rotspeed);
		setup->game.planeY = oldPlaneX * sin(setup->game.rotspeed) + setup->game.planeY * cos(setup->game.rotspeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}

void load_image(t_setup *setup, int *texture, char *path, t_img *img_)
{
	int y;
	int x;
	y = 0;
	x = 0;
	img_->img = mlx_xpm_file_to_image(setup->mlx, path, &img_->img_width, &img_->img_height);
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
	mlx_destroy_image(setup->mlx, img_->img);
}
void load_texture(t_setup *setup)
{
	t_img img;
	load_image(setup, setup->game.texture[0], "textures/eagle.xpm", &img);
	load_image(setup, setup->game.texture[1], "textures/redbrick.xpm", &img);
	load_image(setup, setup->game.texture[2], "textures/purplestone.xpm", &img);
	load_image(setup, setup->game.texture[3], "textures/greystone.xpm", &img);
}
int graph_main(t_setup *setup)
{
	//t_setup setup;
	setup->mlx = mlx_init();
	setup->game.dir_x = -1;
	setup->game.dir_y = 0.0;
	setup->game.planeX = 0.0;
	setup->game.planeY = 0.66;
	setup->game.movespeed = 0.05;
	setup->game.rotspeed = 0.05;



	if(!(alloc_storage(setup)))
		return(0);
	load_texture(setup);

	setup->win = mlx_new_window(setup->mlx, width, height, "mlx");

	setup->img.img = mlx_new_image(setup->mlx, width, height);
	setup->img.data = (int *)mlx_get_data_addr(setup->img.img, &setup->img.bpp, &setup->img.size_l, &setup->img.endian);

	mlx_loop_hook(setup->mlx, &main_loop, setup);
	mlx_hook(setup->win, X_EVENT_KEY_PRESS, 0, &key_press, setup);
	mlx_loop(setup->mlx);
	return (0);
}

int		alloc_storage(t_setup *setup)
{
	int j;
	int i;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			setup->game.buf[i][j] = 0;
			j++;
		}
		i++;
	}

	if (!(setup->game.texture = (int **)wrmalloc(sizeof(int *) * 4)))
       		 return (-1);
	i = 0;
	while (i < 4)
	{
		if (!(setup->game.texture[i] = (int *)wrmalloc(sizeof(int) * (texHeight * texWidth))))
			return (-1);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < texHeight * texWidth)
		{
			setup->game.texture[i][j] = 0;
			j++;
		}
		i++;
	}
	init_buf(setup);
	return(1);
}


void	init_buf(t_setup *setup)
{
	int j;
	int i;
	i = 0;
	
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			setup->game.buf[i][j] = 0;
			j++;
		}
		i++;
	}
}