
#include"../cub3D.h"
#include "../key_macros.h"
#include <string.h>
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define mapWidth 24
#define mapHeight 24
#define width 1280
#define height 720



int	worldMap[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1}
						};

void	verLine(t_info *info, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(info->mlx, info->win, x, y, color);
		y++;
	}
}

void	calc(t_info *info)
{
 	info->x = 0;
	while (info->x < width)
	{
		

		info->cameraX = 2 * info->x / (double)width -1 ; //camera dans l'espace
		info->raydirX = info->dirX + info->planeX *	info->cameraX;
		info->raydirY = info->dirY + info->planeY * info->cameraX;
		
		 info->mapX = (int)info->posX;
		info->mapY = (int)info->posY;

		//length of ray from current position to next x or y-side
		info->sidedistX = 0;
		info->sidedistY = 0;
		
		 //length of ray from one x or y-side to next x or y-side
		info->deltadistX = fabs(1 / info->raydirX);
		info->deltadistY = fabs(1 / info->raydirY);
	
		info->hit = 0;

		if (info->raydirX < 0)
		{
			info->stepX = -1;
			info->sidedistX = (info->posX - info->mapX) *	info->deltadistX;
		}
		else
		{
			info->stepX = 1;
			info->sidedistX = (info->mapX + 1.0 - info->posX) * info->deltadistX;
		}
		if (info->raydirY < 0)
		{
			info->stepY = -1;
			info->sidedistY = (info->posY - info->mapY) * info->deltadistY;
		}
		else
		{
			info->stepY = 1;
			info->sidedistY = (info->mapY + 1.0 - info->posY) * info->deltadistY;
		}

		while (info->hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
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
			//Check if ray has hit a wall
			if (worldMap[info->mapX][info->mapY] > 0) info->hit = 1;
		}
		if (info->side == 0)
			info->perpwalldist = (info->mapX - info->posX + (1 - info->stepX) / 2) / info->raydirX;
		else
			info->perpwalldist = (info->mapY - info->posY + (1 - info->stepY) / 2) / info->raydirY;
		//Calculate height of line to draw on screen
		int lineHeight = (int)(height / info->perpwalldist);

		//calculate lowest and highest pixel to fill in current stripe
		info->drawstart = -lineHeight / 2 + height / 2;
		if(info->drawstart < 0)
			info->drawstart = 0;
		info->drawend = lineHeight / 2 + height / 2;
		if(info->drawend >= height)
			info->drawend = height - 1;

		info->color = 0;
		if (worldMap[info->mapY][info->mapX] == 1)
			info->color = 0xFF0000;
		else if (worldMap[info->mapY][info->mapX] == 2)
			info->color = 0x00FF00;
		else if (worldMap[info->mapY][info->mapX] == 3)
			info->color = 0x0000FF;
		else if (worldMap[info->mapY][info->mapX] == 4)
			info->color = 0xFFFFFF;
		else
			info->color = 0xFFFF00;
		
		if (info->side == 1)
			info->color = info->color / 2;
		verLine(info, info->x, info->drawstart, info->drawend, info->color);

		info->x++;
	}
}

int	main_loop(t_info *info)
{
	calc(info);	 
	mlx_clear_window(info->mlx, info->win);
	return (0);
}

int	key_press(int key, t_info *info)
{
	if (key == K_W)
	{
		if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
	}
	//move backwards if no wall behind you
	if (key == K_S)
	{
		if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
	}
	//rotate to the right
	if (key == K_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	//rotate to the left
	if (key == K_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}

int	main(void)
{
	t_info info;
	info.mlx = mlx_init();

	info.posX = 12;
	info.posY = 5;
	info.dirX = -1;
	info.dirY = 0;
	info.planeX = 0;
	info.planeY = 0.66;
	info.moveSpeed = 0.5;
	info.rotSpeed = 0.05;
	info.win = mlx_new_window(info.mlx, width, height, "mlx");
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_loop(info.mlx);
}