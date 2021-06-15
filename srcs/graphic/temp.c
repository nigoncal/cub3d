#include "../../includes/cub3d.h"


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
	if (info->game.side == 0 && info->game.raydir_x < 0)
		info->game.texdir = 0;
	if (info->game.side == 0 && info->game.raydir_x >= 0)
		info->game.texdir = 1;
	if (info->game.side == 1 && info->game.raydir_y < 0)
		info->game.texdir = 2;
	if (info->game.side == 1 && info->game.raydir_y >= 0)
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
		while (info->game.hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (info->game.sidedist_x < info->game.sidedist_y)
			{
				info->game.sidedist_x += info->game.deltadist_x;
				info->game.map_x += info->game.step_x;
				info->game.side = 0;
			}
			else
			{
				info->game.sidedist_y += info->game.deltadist_y;
				info->game.map_y += info->game.step_y;
				info->game.side = 1;
			}
			//Check in map if ray has info->game.hit a wall
			if (info->map[info->game.map_y][info->game.map_x] == '1')
				info->game.hit = 1;
		}
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
		info->game.tex_x = (int)(info->game.wall_x * (double)texWidth);
		if (info->game.side == 0 && info->game.raydir_x > 0)
			info->game.tex_x = texWidth - info->game.tex_x - 1;
		if (info->game.side == 1 && info->game.raydir_y < 0)
			info->game.tex_x = texWidth - info->game.tex_x - 1;
		// How much to increase the texture coordinate perscreen pixel
		info->game.step = 1.0 * texHeight / info->game.lineheight;
		// Starting texture coordinate
		info->game.tex_pos = (info->game.drawstart - height / 2 + info->game.lineheight / 2) * info->game.step;
		y = info->game.drawstart;
		while (y < info->game.drawend)
		{
			y++;
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			 info->game.tex_y = (int)info->game.tex_pos & (texHeight - 1);
			info->game.tex_pos += info->game.step;
			info->game.color = info->game.texture[info->game.texdir][texHeight * info->game.tex_y + info->game.tex_x];
		// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (info->game.side == 1)
				info->game.color = (info->game.color >> 1) & 8355711;
			info->game.buf[y][x] = info->game.color;
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

	if (key == MOVE_W)
	{
		if (info->map[(int)(info->game.pos_y)][(int)(info->game.pos_x + info->game.dir_x * info->game.movespeed)] == 'V')
			info->game.pos_x += info->game.dir_x * info->game.movespeed;
	
		if (info->map[(int)(info->game.pos_y + info->game.dir_y * info->game.movespeed)][(int)(info->game.pos_x)] == 'V')
			info->game.pos_y += info->game.dir_y * info->game.movespeed;
	}
	//move backwards if no wall behind you
	if (key == MOVE_S)
	{
		if (info->map[(int)(info->game.pos_y)][(int)(info->game.pos_x - info->game.dir_x * info->game.movespeed)] == 'V')
			info->game.pos_x -= info->game.dir_x * info->game.movespeed;
	
		if (info->map[(int)(info->game.pos_y - info->game.dir_y * info->game.movespeed)][(int)(info->game.pos_x)] == 'V')
			info->game.pos_y -= info->game.dir_y * info->game.movespeed;
	}
	//move to the right
	if (key == MOVE_D)
	{
		if (info->map[(int)(info->game.pos_y)][(int)(info->game.pos_x - info->game.dir_y * info->game.movespeed)] == 'V')
		{
			if (info->map[(int)(info->game.pos_y)][(int)(info->game.pos_x + info->game.dir_y * info->game.movespeed)] == 'V')
				info->game.pos_x += info->game.dir_y * info->game.movespeed;
		}
		if (info->map[(int)(info->game.pos_y - info->game.dir_x * info->game.movespeed)][(int)(info->game.pos_x)] == 'V')
		{
			if (info->map[(int)(info->game.pos_y - info->game.dir_x * info->game.movespeed)][(int)(info->game.pos_x)] == 'V')
				info->game.pos_y -= info->game.dir_x * info->game.movespeed;
		}
	}
	//move to the left
	if (key == MOVE_A)
	{
		if (info->map[(int)(info->game.pos_y)][(int)(info->game.pos_x - info->game.dir_y * info->game.movespeed)] == 'V')
		{
			if (info->map[(int)(info->game.pos_y)][(int)(info->game.pos_x - info->game.dir_y * info->game.movespeed)] == 'V')
				info->game.pos_x -= info->game.dir_y * info->game.movespeed;
		}
		if (info->map[(int)(info->game.pos_y + info->game.dir_x * info->game.movespeed)][(int)(info->game.pos_x)] == 'V')
		{
			if (info->map[(int)(info->game.pos_y + info->game.dir_x * info->game.movespeed)][(int)(info->game.pos_x)] == 'V')
				info->game.pos_y += info->game.dir_x * info->game.movespeed;
		}
	}
	//rotate to the right
	if (key == ROTATE_RIGHT)
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
	if (key == ROTATE_LEFT)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->game.dir_x;
		info->game.dir_x = info->game.dir_x * cos(info->game.rotspeed) - info->game.dir_y * sin(info->game.rotspeed);
		info->game.dir_y = oldDirX * sin(info->game.rotspeed) + info->game.dir_y * cos(info->game.rotspeed);
		double oldPlaneX = info->game.planeX;
		info->game.planeX = info->game.planeX * cos(info->game.rotspeed) - info->game.planeY * sin(info->game.rotspeed);
		info->game.planeY = oldPlaneX * sin(info->game.rotspeed) + info->game.planeY * cos(info->game.rotspeed);
	}
	if (key == EXIT_ESC)
		exit(0);
	return (0);
}

void load_image(t_info *info, int *texture, char *path)
{
	int y;
	int x;
	y = 0;
	x = 0;
	info->img.img = mlx_xpm_file_to_image(info->mlx, path, &info->img.img_width, &info->img.img_height);
	
	if(info->game.texture[0] == NULL)
	{
		dprintf(1, "salut\n");
		alloc_storage(info);
	}
		
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);
	while (y < info->img.img_height)
	{
		while (x < info->img.img_width)
		{
			texture[info->img.img_width * y + x] = info->img.data[info->img.img_width * y + x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(info->mlx, info->img.img);
}
void load_texture(t_info *info)
{
	load_image(info, info->game.texture[0], info->north_texture_path);
	load_image(info, info->game.texture[1], info->south_texture_path);
	load_image(info, info->game.texture[2], info->west_texture_path);
	load_image(info, info->game.texture[3], info->east_texture_path);
}
int graph_main(t_info *info)
{
	info->mlx = mlx_init();
	//info->game.dir_x = -1;
	//info->game.dir_y = 0.0;
	//info->game.planeX = 0.0;
	//info->game.planeY = 0.66;
	info->game.movespeed = 0.05;
	info->game.rotspeed = 0.05;

		if (!(info->game.texture = (int **)wrmalloc(sizeof(int *) * 4)))
       		 return (-1);
			info->game.texture[0] = NULL;
					
	alloc_storage(info);
	load_texture(info);

	info->win = mlx_new_window(info->mlx, width, height, "mlx");

	info->img.img = mlx_new_image(info->mlx, width, height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);
	//loops all the time when there's no event
	mlx_loop_hook(info->mlx, &main_loop, info);
	//triggered by an event : here, whenever a key is pressed ?
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


	i = 0;
/*	if(info->img.img_height == 0)
		return(-1);*/
				
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