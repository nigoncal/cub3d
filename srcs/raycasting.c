
#include"../cub3D.h"
#include "../key_macros.h"
#include <string.h>
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17


void	verLine(t_info *info, int x, int y1, int y2)
{
	int		y;
	char	*dst;

	y = y1;
	while (y <= y2)
	{
    	dst = info->buffer + (y * info->line_lenght + x * (info->bpp / 8));
   		*(unsigned int*)dst = info->color;
		y++;
	}
}

void	calc(t_info *info)
{
	info->x = 0;
	info->image = mlx_new_image(info->mlx, info->width, info->height);
	info->buffer = mlx_get_data_addr(info->image, &info->bpp, &info->line_lenght, &info->endian);

	while (info->x < info->width)
	{
		info->hit = 0;
		raycast_cal(info);
		raycast_calc_dir(info);
		raycast_calc_delta(info);
		raycast_calc_pos(info);
		verLine(info, info->x, info->drawstart, info->drawend);
		info->x++;
	}
	mlx_clear_window(info->mlx, info->win);
}

int	main_loop(t_info *info)
{
	calc(info);
	   mlx_put_image_to_window(info->mlx, info->win, info->image, 0, 0);
	return (0);
}

void	raycast_cal(t_info *info)
{
	//PEUT ETRE : on cherche a placer l'origine du point precis a partir duquel on lancera les rayons (son X dans la largeur car Y bouge ailleurs)
	//camera dans l'espace
	info->camera_x = 2 * info->x / (double)info->width -1 ;
	//get rays directions based on
	info->raydir_x = info->dir_x + info->plane_x * info->camera_x;
	info->raydir_y = info->dir_y + info->plane_y * info->camera_x;
	//update what map box we work with based on player's position
	info->map_x = (int)info->pos_x;
	info->map_y = (int)info->pos_y;
	//length of ray from current position to next x or y-side
	info->sidedist_x = 0;
	info->sidedist_y = 0;
	 //length of ray from one x or y-side to next x or y-side
	info->deltadist_x = fabs(1 / info->raydir_x);
	info->deltadist_y = fabs(1 / info->raydir_y);
	info->hit = 0;
}

void	raycast_calc_dir(t_info *info)
{
	if (info->raydir_x < 0)
	{
		info->step_x = -1;
		info->sidedist_x = (info->pos_x - info->map_x) * info->deltadist_x;
	}
	else
	{
		info->step_x = 1;
		info->sidedist_x = (info->map_x + 1.0 - info->pos_x) \
	* info->deltadist_x;
	}
	if (info->raydir_y < 0)
	{
		info->step_y = -1;
		info->sidedist_y = (info->pos_y - info->map_y) * info->deltadist_y;
	}
	else
	{
		info->step_y = 1;
		info->sidedist_y = (info->map_y + 1.0 - info->pos_y) \
* info->deltadist_y;
	}
}

void	raycast_calc_delta(t_info *info)
{
	while (info->hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction : look for a wall
		if (info->sidedist_x < info->sidedist_y)
		{
			info->sidedist_x += info->deltadist_x;
			info->map_x += info->step_x;
			info->side = 0;
		}
		else
		{
			info->sidedist_y += info->deltadist_y;
			info->map_y += info->step_y;
			info->side = 1;
		}
		//If ray has hit a wall, we keep this info in info->hit
		if (info->setup.map[info->map_x][info->map_y] == '1')
			info->hit = 1;
	}
}

void	raycast_calc_pos(t_info *info)
{
	if (info->side == 0)
	info->perpwalldist = (info->map_x - info->pos_x +\
	(1 - info->step_x) / 2) / info->raydir_x;
	else
	info->perpwalldist = (info->map_y - info->pos_y +\
	(1 - info->step_y) / 2) / info->raydir_y;
	//Calculate info->height of line to draw on screen WTF IS THIS ???
	 info->line_height = (int)(info->height / info->perpwalldist);
	//calculate lowest and highest pixel to fill in current stripe
	info->drawstart = -info->line_height / 2 + info->height / 2;
	if (info->drawstart < 0)
		info->drawstart = 0;
	info->drawend = info->line_height / 2 + info->height / 2;
	if (info->drawend >= info->height)
		info->drawend = info->height - 1;
	if (info->setup.map[info->map_y][info->map_x] == '1')
		info->color = 0xFF0000;
	else
		info->color = 0xFFFFFF;
	//change color depending on wall orientation but it is fucked up
	if (info->side == 1)
		info->color = info->color / 2;
}