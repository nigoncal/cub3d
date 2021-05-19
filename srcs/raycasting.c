
#include"../cub3D.h"
#include "../key_macros.h"
#include <string.h>
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17


void	verLine(t_info *info, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	char *dst;
	while (y <= y2)
	{
    	dst = info->buffer + (y * info->line_lenght + x * (info->BPP / 8));
   		*(unsigned int*)dst = color;
		y++;
	}
}

void	calc(t_info *info)
{
	info->x = 0;
	info->image = mlx_new_image(info->mlx, info->width, info->height);
	info->buffer = mlx_get_data_addr(info->image, &info->BPP, &info->line_lenght, &info->endian);
	while (info->x < info->width)
	{
		info->hit = 0;
		raycast_cal(info);
		raycast_calc_dir(info);
		raycast_calc_delta(info);
		raycast_calc_pos(info);
		verLine(info, info->x, info->drawstart, info->drawend, info->color);
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
	info->cameraX = 2 * info->x / (double)info->width -1;
	//get rays directions based on
	info->raydirX = info->dirX + info->planeX * info->cameraX;
	info->raydirY = info->dirY + info->planeY * info->cameraX;
	//update what map box we work with based on player's position
	info->mapX = (int)info->posX;
	info->mapY = (int)info->posY;
	//length of ray from current position to next x or y-side
	info->sidedistX = 0;
	info->sidedistY = 0;
	 //length of ray from one x or y-side to next x or y-side
	info->deltadistX = fabs(1 / info->raydirX);
	info->deltadistY = fabs(1 / info->raydirY);
	info->hit = 0;
}

void	raycast_calc_dir(t_info *info)
{
	if (info->raydirX < 0)
	{
		info->stepX = -1;
		info->sidedistX = (info->posX - info->mapX) * info->deltadistX;
	}
	else
	{
		info->stepX = 1;
		info->sidedistX = (info->mapX + 1.0 - info->posX) \
	* info->deltadistX;
	}
	if (info->raydirY < 0)
	{
		info->stepY = -1;
		info->sidedistY = (info->posY - info->mapY) * info->deltadistY;
	}
	else
	{
		info->stepY = 1;
		info->sidedistY = (info->mapY + 1.0 - info->posY) \
	* info->deltadistY;
	}
}

void	raycast_calc_delta(t_info *info)
{
	while (info->hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction : look for a wall
		if (info->sidedistX < info->sidedistY)
		{
			info->sidedistX += info->deltadistX;
			info->mapX += info->stepX;
			info->side = 0;
		}
		else
		{
			info->sidedistY += info->deltadistY;
			info->mapY += info->stepY;
			info->side = 1;
		}
		//If ray has hit a wall, we keep this info in info->hit
		if (info->ok.map[info->mapX][info->mapY] == '1')
			info->hit = 1;
	}
}

void	raycast_calc_pos(t_info *info)
{
	if (info->side == 0)
		info->perpwalldist = (info->mapX - info->posX + \
	(1 - info->stepX) / 2) / info->raydirX;
	else
		info->perpwalldist = (info->mapY - info->posY + \
	(1 - info->stepY) / 2) / info->raydirY;
		//Calculate info->height of line to draw on screen WTF IS THIS ???
	info->line_height = (int)(info->height / info->perpwalldist);
	//calculate lowest and highest pixel to fill in current stripe
	info->drawstart = -info->line_height / 2 + info->height / 2;
	if (info->drawstart < 0)
		info->drawstart = 0;
	info->drawend = info->line_height / 2 + info->height / 2;
	if (info->drawend >= info->height)
		info->drawend = info->height - 1;
	if (info->ok.map[info->mapY][info->mapX] == '1')
		info->color = 0xFF0000;
	else
		info->color = 0xFFFFFF;
	//change color depending on wall orientation but it is fucked up
	if (info->side == 1)
		info->color = info->color / 2;
}