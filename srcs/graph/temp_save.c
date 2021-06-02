/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:18:03 by yohlee            #+#    #+#             */
/*   Updated: 2021/05/31 11:26:02 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
//#include "mlx/mlx.h"
//#include "key_macros.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define texWidth 64
#define texHeight 64
#define mapWidth 9
#define mapHeight 17
#define _width 1280
#define _height 720

/*typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;*/

/*typedef struct	s_info
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	void	*mlx;
	void	*win;
	t_img	img;
	//int		**buf;
	// pas init comme ca mais en int **buf, et malloc + loin
	int		buf[_height][_width];
	int		**texture;
	double	moveSpeed;
	double	rotSpeed;
}				t_info;*/

char	worldMap[mapWidth][mapHeight] =
{
									
									{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},								
									{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
									{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
									{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
									{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
									{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
									{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
									{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
									{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};


void	draw(t_info *info, t_setup *setup)
{

	int x;
	int y;
		x = 0;
		y = 0;
	while (y < _height)
	{
		while (x < _width)
		{
			// old ver : info->img.data[y * width + x] = info->buf[y][x];
			// Where is img.data ? setup->texture[].addr ? wich texture to draw ?
			info->img.data[y * setup->game.width + x] = info->buf[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	tex_orientation(int *texDir, int *side, double rayDirX, double rayDirY, double perpWallDist, double *wallX, t_info *info)
{
	if (*side == 0 && rayDirX < 0) //NO
		*texDir = 0;
	if (*side == 0 && rayDirX >= 0) // S
		*texDir = 1;
	if (*side == 1 && rayDirY < 0) // WE
		*texDir = 2;
	if (*side == 1 && rayDirY >= 0) // EA
		*texDir = 3;
	if (*side == 0)
		*wallX = info->posY + perpWallDist * rayDirY;
	else
		*wallX = info->posX + perpWallDist * rayDirX;
	*wallX -= floor((*wallX)); // wallX = 15.3 devient wallX = 0.3
}

void	calc(t_info *info, t_setup *setup)
{
	int	x;

	x = 0;
	while (x < setup->game.width)
	{

		double cameraX = 2 * x / (double)setup->game.width - 1;
		double rayDirX = info->dirX + info->planeX * cameraX;
		double rayDirY = info->dirY + info->planeY * cameraX;
		
		int mapX = (int)info->posX;
		int mapY = (int)info->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		
		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}

		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check in map if ray has hit a wall
			if (worldMap[mapX][mapY] != 0) hit = 1;

		}
		if (side == 0)
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(setup->game.height / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + setup->game.height / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + setup->game.height / 2;
		if(drawEnd >= setup->game.height || drawEnd < 0)
			drawEnd = setup->game.height - 1;


	


		// calculate value of wallX
		double wallX;
		if (side == 0)
			wallX = info->posY + perpWallDist * rayDirY;
		else
			wallX = info->posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		// Choosing a texture in the texture tab
		//int texNum = worldMap[mapX][mapY];
		int texDir;
		tex_orientation(&texDir, &side, rayDirX, rayDirY, perpWallDist, &wallX, info);

		// x coordinate on the texture
		int texX = (int)(wallX * (double)texWidth);
		if (side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texWidth - texX - 1;

		// How much to increase the texture coordinate perscreen pixel
		double step = 1.0 * texHeight / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - setup->game.height / 2 + lineHeight / 2) * step;
		int y = drawStart;
		while (y < drawEnd)
		{
			y++;
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			int color = info->texture[texDir][texHeight * texY + texX];
			// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (side == 1)
				color = (color >> 1) & 8355711;
			info->buf[y][x] = color;
		}
		
		y = 0;
		while(y < drawStart)
		{
			info->buf[y][x] = 0x77b5fe;
			y++;
		}
		y = drawEnd;
		while(y < _height)
		{
			info->buf[y][x] = 0x808000;
			y++;
		}
		x++;
	}
	}


int	main_loop(t_info *info, t_setup *setup)
{
	calc(info, setup);
	draw(info, setup);
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

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
int y;
int x;
		y = 0;
		x = 0;
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
while (y < img->img_height)
	{
while(x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		x = 0;
		y++;
	}
mlx_destroy_image(info->mlx, img->img);
}

/*void	load_image(t_setup *setup, int tex_nb, int *texture, char *path, t_info *info)
{
	int y;
	int x;
		y = 0;
		x = 0;

	// changer car ici pn a une struct par texture PTDR
	// old : img->img = mlx_xpm_file_to_image(setup->mlx, path, &img->img_width, &img->img_height);
	setup->game.texture[tex_nb].img = mlx_xpm_file_to_image(setup->mlx, path, &setup->game.texture[tex_nb].width, &setup->game.texture[tex_nb].height);
	// old :img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	setup->game.texture[tex_nb].addr = (int *)mlx_get_data_addr(\
	setup->game.texture[tex_nb].img, &setup->game.texture[tex_nb].bits_per_pixel, \
	&setup->game.texture[tex_nb].line_length, &setup->game.texture[tex_nb].endian);
	while (y < setup->game.texture[tex_nb].height)
	{
		while(x < setup->game.texture[tex_nb].width)
		{
			// old ver : texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			texture[info->img.img_width * y + x] = setup->game.texture[tex_nb].addr[info->img.img_width * y + x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(setup->mlx, setup->game.texture[tex_nb].img);
}*/

void	load_texture(t_info *info)
{
	t_img	img;
load_image(info, info->texture[0], "textures/eagle.xpm", &img);
load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
load_image(info, info->texture[3], "textures/greystone.xpm", &img);
load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
load_image(info, info->texture[5], "textures/mossy.xpm", &img);
load_image(info, info->texture[6], "textures/wood.xpm", &img);
load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
}

/*void	load_texture(t_info *info, t_setup *setup)
{
	//t_img	img;
	load_image(setup, 0, info->texture[0], "textures/eagle.xpm", info);
	load_image(setup, 1, info->texture[1], "textures/redbrick.xpm", info);
	load_image(setup, 2, info->texture[2], "textures/purplestone.xpm", info);
	load_image(setup, 3, info->texture[3], "textures/greystone.xpm", info);
	load_image(setup, 4, info->texture[4], "textures/bluestone.xpm", info);
	load_image(setup, 5, info->texture[5], "textures/mossy.xpm", info);
	printf("wesh\n");
	load_image(setup, 6, info->texture[6], "textures/wood.xpm", info);
	// CRASHES THERE
	load_image(setup, 7, info->texture[7], "textures/colorstone.xpm", info);
}*/

int    graph_main(t_setup *setup)
{
    t_info info;
    //info.mlx = mlx_init();
	setup->mlx = mlx_init();

    info.posX = 5;
    info.posY = 5;
    info.dirX = -1;
    info.dirY = 0.0;
    info.planeX = 0.0;
    info.planeY = 0.66;

    int j;
    int i;

    i = 0;
    while (i < _height)
    {
        j = 0;
        while (j < _width)
        {
            info.buf[i][j] = 0;
            j++;
        }
        i++;
    }

    if (!(info.texture = (int **)malloc(sizeof(int *) * 8)))
        return (-1);
    i = 0;
    while (i < 8)
    {
        if (!(info.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
            return (-1);
        i++;
    }
    i = 0;
    while (i < 8)
    {
        j = 0;
        while (j < texHeight * texWidth)
        {
            info.texture[i][j] = 0;
            j++;
        }
        i++;
    }

	// CRASHES HERE !!!!!!!!!!!!!!!!!!!!
    load_texture(&info);
	printf("pouetpouet\n");

    info.moveSpeed = 0.05;
    info.rotSpeed = 0.05;
    
    info.win = mlx_new_window(setup->mlx, _width, _height, "mlx");

    info.img.img = mlx_new_image(setup->mlx, _width, _height);
	printf("M D R\n");
    info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);

    mlx_loop_hook(setup->mlx, &main_loop, &info);
    mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
    mlx_loop(setup->mlx);
	return (0);
}
