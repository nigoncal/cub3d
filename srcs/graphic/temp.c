#include "../../includes/cub3d.h"


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
	if (setup->game.side == 0 && setup->game.raydir_x < 0)
		setup->game.texdir = 0;
	if (setup->game.side == 0 && setup->game.raydir_x >= 0)
		setup->game.texdir = 1;
	if (setup->game.side == 1 && setup->game.raydir_y < 0)
		setup->game.texdir = 2;
	if (setup->game.side == 1 && setup->game.raydir_y >= 0)
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
			if (setup->game.sidedist_x <= setup->game.sidedist_y)
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
		setup->game.tex_x = (int)(setup->game.wall_x * (double)texWidth);
		if (setup->game.side == 0 && setup->game.raydir_x > 0)
			setup->game.tex_x = texWidth - setup->game.tex_x - 1;
		if (setup->game.side == 1 && setup->game.raydir_y < 0)
			setup->game.tex_x = texWidth - setup->game.tex_x - 1;
		// How much to increase the texture coordinate perscreen pixel
		setup->game.step = 1.0 * texHeight / setup->game.lineheight;
		// Starting texture coordinate
		setup->game.tex_pos = (setup->game.drawstart - height / 2 + setup->game.lineheight / 2) * setup->game.step;
		y = setup->game.drawstart;
		while (y < setup->game.drawend)
		{
			y++;
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			 setup->game.tex_y = (int)setup->game.tex_pos & (texHeight - 1);
			setup->game.tex_pos += setup->game.step;
			setup->game.color = setup->game.texture[setup->game.texdir][texHeight * setup->game.tex_y + setup->game.tex_x];
		// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (setup->game.side == 1)
				setup->game.color = (setup->game.color >> 1) & 8355711;
			setup->game.buf[y][x] = setup->game.color;
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

	if (key == MOVE_W)
	{
		if (setup->map[(int)(setup->game.pos_y)][(int)(setup->game.pos_x + setup->game.dir_x * setup->game.movespeed)] == 'V')
			setup->game.pos_x += setup->game.dir_x * setup->game.movespeed;
	
		if (setup->map[(int)(setup->game.pos_y + setup->game.dir_y * setup->game.movespeed)][(int)(setup->game.pos_x)] == 'V')
			setup->game.pos_y += setup->game.dir_y * setup->game.movespeed;
	}
	//move backwards if no wall behind you
	if (key == MOVE_S)
	{
		if (setup->map[(int)(setup->game.pos_y)][(int)(setup->game.pos_x - setup->game.dir_x * setup->game.movespeed)] == 'V')
			setup->game.pos_x -= setup->game.dir_x * setup->game.movespeed;
	
		if (setup->map[(int)(setup->game.pos_y - setup->game.dir_y * setup->game.movespeed)][(int)(setup->game.pos_x)] == 'V')
			setup->game.pos_y -= setup->game.dir_y * setup->game.movespeed;
	}
	//move to the right
	if (key == MOVE_A)
	{
		if (setup->map[(int)(setup->game.pos_y)][(int)(setup->game.pos_x - setup->game.dir_y * setup->game.movespeed)] == 'V')
		{
			if (setup->map[(int)(setup->game.pos_y)][(int)(setup->game.pos_x + setup->game.dir_y * setup->game.movespeed)] == 'V')
				setup->game.pos_x += setup->game.dir_y * setup->game.movespeed;
		}
		if (setup->map[(int)(setup->game.pos_y - setup->game.dir_x * setup->game.movespeed)][(int)(setup->game.pos_x)] == 'V')
		{
			if (setup->map[(int)(setup->game.pos_y - setup->game.dir_x * setup->game.movespeed)][(int)(setup->game.pos_x)] == 'V')
				setup->game.pos_y -= setup->game.dir_x * setup->game.movespeed;
		}
	}
	//move to the left
	if (key == MOVE_D)
	{
		if (setup->map[(int)(setup->game.pos_y)][(int)(setup->game.pos_x - setup->game.dir_y * setup->game.movespeed)] == 'V')
		{
			if (setup->map[(int)(setup->game.pos_y)][(int)(setup->game.pos_x - setup->game.dir_y * setup->game.movespeed)] == 'V')
				setup->game.pos_x -= setup->game.dir_y * setup->game.movespeed;
		}
		if (setup->map[(int)(setup->game.pos_y + setup->game.dir_x * setup->game.movespeed)][(int)(setup->game.pos_x)] == 'V')
		{
			if (setup->map[(int)(setup->game.pos_y + setup->game.dir_x * setup->game.movespeed)][(int)(setup->game.pos_x)] == 'V')
				setup->game.pos_y += setup->game.dir_x * setup->game.movespeed;
		}
	}
	//rotate to the right
	if (key == ROTATE_LEFT)
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
	if (key == ROTATE_RIGHT)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = setup->game.dir_x;
		setup->game.dir_x = setup->game.dir_x * cos(setup->game.rotspeed) - setup->game.dir_y * sin(setup->game.rotspeed);
		setup->game.dir_y = oldDirX * sin(setup->game.rotspeed) + setup->game.dir_y * cos(setup->game.rotspeed);
		double oldPlaneX = setup->game.planeX;
		setup->game.planeX = setup->game.planeX * cos(setup->game.rotspeed) - setup->game.planeY * sin(setup->game.rotspeed);
		setup->game.planeY = oldPlaneX * sin(setup->game.rotspeed) + setup->game.planeY * cos(setup->game.rotspeed);
	}
	if (key == EXIT_ESC)
		exit(0);
	return (0);
}

void load_image(t_setup *setup, int *texture, char *path)
{
	int y;
	int x;
	y = 0;
	x = 0;
	setup->img.img = mlx_xpm_file_to_image(setup->mlx, path, &setup->img.img_width, &setup->img.img_height);
	if (setup->img.img_width != 64 || setup->img.img_height != 64)
		abort_prog("Only non-empty, 64x64 .xpm textures are supported.");
	if(setup->game.texture[0] == NULL)
	{
		dprintf(1, "salut\n");
		alloc_storage(setup);
	}
	setup->img.data = (int *)mlx_get_data_addr(setup->img.img, &setup->img.bpp, &setup->img.size_l, &setup->img.endian);
	while (y < setup->img.img_height)
	{
		while (x < setup->img.img_width)
		{
			texture[setup->img.img_width * y + x] = setup->img.data[setup->img.img_width * y + x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(setup->mlx, setup->img.img);
}

void	load_texture(t_setup *setup)
{
	load_image(setup, setup->game.texture[0], setup->north_texture_path);
	load_image(setup, setup->game.texture[1], setup->south_texture_path);
	load_image(setup, setup->game.texture[2], setup->west_texture_path);
	load_image(setup, setup->game.texture[3], setup->east_texture_path);
}

int graph_main(t_setup *setup)
{
	setup->mlx = mlx_init();
	setup->game.dir_x = 0;
	setup->game.dir_y = -1;
	setup->game.planeX = 0.66;
	setup->game.planeY = 0;
	setup->game.movespeed = 0.05;
	setup->game.rotspeed = 0.05;
	setup->game.map_x = 0;
	setup->game.map_y = 0;

		if (!(setup->game.texture = (int **)wrmalloc(sizeof(int *) * 4)))
       		 return (-1); // abort_prog
			setup->game.texture[0] = NULL;
					
	alloc_storage(setup);
	load_texture(setup);

	setup->win = mlx_new_window(setup->mlx, width, height, "mlx");

	setup->img.img = mlx_new_image(setup->mlx, width, height);
	setup->img.data = (int *)mlx_get_data_addr(setup->img.img, &setup->img.bpp, &setup->img.size_l, &setup->img.endian);
	//loops all the time when there's no event
	mlx_loop_hook(setup->mlx, &main_loop, setup);
	//triggered by an event : here, whenever a key is pressed ?
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


	i = 0;
/*	if(setup->img.img_height == 0)
		return(-1);*/
				
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
