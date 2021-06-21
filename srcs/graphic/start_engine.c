#include "../../includes/cub3d.h"


#define texWidth 64
#define texHeight 64



void draw(t_setup *setup)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < setup->height)
	{
		while (x <= setup->width)
		{
			setup->img.data[y * setup->width + x] = setup->game.buf[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	//mlx_destroy_image(setup->mlx, setup->img.img);
	mlx_put_image_to_window(setup->mlx, setup->win, setup->img.img, 0, 0);
}


int main_loop(t_setup *setup)
{
	setup->x = 0;
	while (setup->x < setup->width)
	{
		calcul_raycast(setup);
		calcul_texture(setup);
		setup->x++;
	}
	draw(setup);
	key_press(setup);
	return (0);
}


int key_press(t_setup *setup)
{
	draw_forward_back(setup);
	draw_left_right(setup);
	draw_rotate_left(setup);
	draw_rotate_right(setup);
	return(0);
}


int start_engine(t_setup *setup)
{
	setup->mlx = mlx_init();
	/*setup->game.dir_x = 0;
	setup->game.dir_y = -1;
	setup->game.plane_x = 0.66;
	setup->game.plane_y = 0;*/
	setup->game.movespeed = 0.025;
	setup->game.rotspeed = 0.025;
	setup->game.map_x = 0;
	setup->game.map_y = 0;
	setup->key.count_key = 1;

	setup->width = 1280;
	setup->height = 720;
		if (!(setup->game.texture = (int **)wrmalloc(sizeof(int *) * 4)))
       		 return (-1); // abort_progs
					
	alloc_storage(setup);
	load_texture(setup);
	setup->win = mlx_new_window(setup->mlx, setup->width, setup->height, "mlx");
	setup->img.img = mlx_new_image(setup->mlx, setup->width, setup->height);
	setup->img.data = (int *)mlx_get_data_addr(setup->img.img, &setup->img.bpp, &setup->img.size_l, &setup->img.endian);
	mlx_hook(setup->win, 2, 0, &key_press_mouvement, setup);
	mlx_loop_hook(setup->mlx, &main_loop, setup);
	mlx_hook(setup->win, 3, 0, &key_release, setup);
	mlx_loop(setup->mlx);
	return (0);
}

int		alloc_storage(t_setup *setup)
{
	int j;
	int i;

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
	
	while (i < setup->height)
	{
		j = 0;
		while (j < setup->width)
		{
			setup->game.buf[i][j] = 0;
			j++;
		}
		i++;
	}
}
void	calcul_raycast(t_setup *setup)
{
		ray_dir(setup);
		detect_case(setup);
		ray_len(setup);
		calc_step_x(setup);
		calc_step_y(setup);
		dda_algo(setup);
		fisheye(setup);
		height_wall(setup);
		fill_stripe(setup);
		tex_orientation(setup);
}

void	calcul_texture(t_setup *setup)
{
		draw_texture(setup);
		draw_celling_floor(setup);
}