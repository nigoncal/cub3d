
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
#define mapWidth 9
#define mapHeight 17
/*#define width 1280
#define height 720*/

/*typedef struct s_img
{
	void *img;
	int *data;
	int size_l;
	int bpp;
	int endian;
	int img_width;
	int img_height;
} t_img;

typedef struct s_info
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	void *mlx;
	void *win;
	t_img img;
	int buf[height][width];
	int **texture;
	double moveSpeed;
	double rotSpeed;
} t_info;*/

int worldMap[mapWidth][mapHeight] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
void draw(t_setup *setup)
{
	int x;
	int y;
	x = 0;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			setup->info.img.data[y * WIN_WIDTH + x] = setup->info.buf[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(setup->info.mlx, setup->info.win, setup->info.img.img, 0, 0);
}
void tex_orientation(int *texDir, int *side, double rayDirX, double perpWallDist, double *wallX, t_setup *setup)
{
	if (*side == 0 && rayDirX < 0) //NO
		*texDir = 0;
	if (*side == 0 && rayDirX >= 0) // S
		*texDir = 1;
	if (*side == 1 && setup->game.raydiry < 0) // WE
		*texDir = 2;
	if (*side == 1 && setup->game.raydiry >= 0) // EA
		*texDir = 3;
	if (*side == 0)
		*wallX = setup->info.posY + perpWallDist * setup->game.raydiry;
	else
		*wallX = setup->info.posX + perpWallDist * rayDirX;
	*wallX -= floor((*wallX)); // wallX = 15.3 devient wallX = 0.3
}
void calc(t_setup *setup)
{
	int x;
	x = 0;
	while (x < WIN_WIDTH)
	{
		setup->game.camerax = 2 * x / (double)WIN_WIDTH - 1;
		setup->game.raydirx = setup->game.dir_x + setup->game.planex * setup->game.camerax;
		setup->game.raydiry = setup->game.dir_y + setup->game.planey * setup->game.camerax;
		int mapX = (int)setup->game.pos_x;
		int mapY = (int)setup->game.pos_y;
		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / setup->game.raydirx);
		double deltaDistY = fabs(1 / setup->game.raydiry);
		double perpWallDist;
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		int hit = 0; //was there a wall hit?
		int side;	 //was a NS or a EW wall hit?
		if (setup->game.raydirx < 0)
		{
			stepX = -1;
			sideDistX = (setup->game.pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - setup->game.pos_x) * deltaDistX;
		}
		if (setup->game.raydiry < 0)
		{
			stepY = -1;
			sideDistY = (setup->game.pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - setup->game.pos_y) * deltaDistY;
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
			if (worldMap[mapX][mapY] != 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - setup->game.pos_x + (1 - stepX) / 2) / setup->game.raydirx;
		else
			perpWallDist = (mapY - setup->game.pos_y + (1 - stepY) / 2) / setup->game.raydiry;
		//Calculate height of line to draw on screen
		int lineHeight = (int)(WIN_HEIGHT / perpWallDist);
		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawEnd >= WIN_HEIGHT || drawEnd < 0)
			drawEnd = WIN_HEIGHT - 1;
		// calculate value of wallX
		double wallX;
		if (side == 0)
			wallX = setup->game.pos_y + perpWallDist * setup->game.raydiry;
		else
			wallX = setup->game.pos_x + perpWallDist * setup->game.raydirx;
		wallX -= floor(wallX);
		// Choosing a texture in the texture tab
		//int texNum = worldMap[mapX][mapY];
		int texDir;
		tex_orientation(&texDir, &side, setup->game.raydirx, perpWallDist, &wallX, setup);
		// x coordinate on the texture
		int texX = (int)(wallX * (double)texWidth);
		if (side == 0 && setup->game.raydirx > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && setup->game.raydiry < 0)
			texX = texWidth - texX - 1;
		// How much to increase the texture coordinate perscreen pixel
		double step = 1.0 * texHeight / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - WIN_HEIGHT / 2 + lineHeight / 2) * step;
		int y = drawStart;
		while (y < drawEnd)
		{
			y++;
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			int color = setup->info.texture[texDir][texHeight * texY + texX];
			// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (side == 1)
				color = (color >> 1) & 8355711;
			setup->info.buf[y][x] = color;
		}
		y = 0;
		while (y < drawStart)
		{
			setup->info.buf[y][x] = 0x77b5fe;
			y++;
		}
		y = drawEnd;
		while (y < WIN_HEIGHT)
		{
			setup->info.buf[y][x] = 0x808000;
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
		if (!worldMap[(int)(setup->game.pos_x + setup->game.dir_x * MOVE_SPEED)][(int)(setup->game.pos_y)])
			setup->game.pos_x += setup->game.dir_x * MOVE_SPEED;
		if (!worldMap[(int)(setup->game.pos_x)][(int)(setup->game.pos_y + setup->game.dir_y * MOVE_SPEED)])
			setup->game.pos_y += setup->game.dir_y * MOVE_SPEED;
	}
	//move backwards if no wall behind you
	if (key == K_S)
	{
		if (!worldMap[(int)(setup->game.pos_x - setup->game.dir_x * MOVE_SPEED)][(int)(setup->game.pos_y)])
			setup->game.pos_x -= setup->game.dir_x * MOVE_SPEED;
		if (!worldMap[(int)(setup->game.pos_x)][(int)(setup->game.pos_y - setup->game.dir_y * MOVE_SPEED)])
			setup->game.pos_y -= setup->game.dir_y * MOVE_SPEED;
	}
	//rotate to the right
	if (key == K_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = setup->game.dir_x;
		setup->game.dir_x = setup->game.dir_x * cos(-ROT_SPEED) - setup->game.dir_y * sin(-ROT_SPEED);
		setup->game.dir_y = oldDirX * sin(-ROT_SPEED) + setup->game.dir_y * cos(-ROT_SPEED);
		double oldPlaneX = setup->game.planex;
		setup->game.planex = setup->game.planex * cos(-ROT_SPEED) - setup->game.planey * sin(-ROT_SPEED);
		setup->game.planey = oldPlaneX * sin(-ROT_SPEED) + setup->game.planey * cos(-ROT_SPEED);
	}
	//rotate to the left
	if (key == K_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = setup->game.dir_x;
		setup->game.dir_x = setup->game.dir_x * cos(ROT_SPEED) - setup->game.dir_y * sin(ROT_SPEED);
		setup->game.dir_y = oldDirX * sin(ROT_SPEED) + setup->game.dir_y * cos(ROT_SPEED);
		double oldPlaneX = setup->game.planex;
		setup->game.planex = setup->game.planex * cos(ROT_SPEED) - setup->game.planey * sin(ROT_SPEED);
		setup->game.planey = oldPlaneX * sin(ROT_SPEED) + setup->game.planey * cos(ROT_SPEED);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}
void load_image(t_setup *setup, int *texture, char *path)
{
	int y;
	int x;
	y = 0;
	x = 0;
	setup->info.img.img = mlx_xpm_file_to_image(setup->info.mlx, path, &setup->info.img.img_width, &setup->info.img.img_height);
	setup->info.img.data = (int *)mlx_get_data_addr(setup->info.img.img, &setup->info.img.bpp, &setup->info.img.size_l, &setup->info.img.endian);
	while (y < setup->info.img.img_height)
	{
		while (x < setup->info.img.img_width)
		{
			texture[setup->info.img.img_width * y + x] = setup->info.img.data[setup->info.img.img_width * y + x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(setup->info.mlx, setup->info.img.img);
}
void load_texture(t_setup *setup)
{
	//t_img img;
	load_image(setup, setup->info.texture[0], "textures/eagle.xpm");
	load_image(setup, setup->info.texture[1], "textures/redbrick.xpm");
	load_image(setup, setup->info.texture[2], "textures/purplestone.xpm");
	load_image(setup, setup->info.texture[3], "textures/greystone.xpm");
	load_image(setup, setup->info.texture[4], "textures/bluestone.xpm");
	load_image(setup, setup->info.texture[5], "textures/mossy.xpm");
	load_image(setup, setup->info.texture[6], "textures/wood.xpm");
	load_image(setup, setup->info.texture[7], "textures/colorstone.xpm");
}
int graph_main(t_setup *setup)
{
	//t_info info;
	printf("blip\n");
	//setup->info.mlx = mlx_init();
	setup->info.posX = 5;
	setup->info.posY = 5;
	setup->info.dirX = -1;
	setup->info.dirY = 0.0;
	setup->info.planeX = 0.0;
	setup->info.planeY = 0.66;
	int j;
	int i;
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			setup->info.buf[i][j] = 0;
			j++;
		}
		i++;
	}
	if (!(setup->info.texture = (int **)malloc(sizeof(int *) * 8)))
		return (-1);
	i = 0;
	while (i < 8)
	{
		if (!(setup->info.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
			return (-1);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < texHeight * texWidth)
		{
			setup->info.texture[i][j] = 0;
			j++;
		}
		i++;
	}
	load_texture(setup);
	//setup->info.moveSpeed = 0.05;
	//setup->info.rotSpeed = 0.05;
	setup->info.win = mlx_new_window(setup->mlx, WIN_WIDTH, WIN_HEIGHT, "mlx");
	setup->info.img.img = mlx_new_image(setup->mlx, WIN_WIDTH, WIN_HEIGHT);
	setup->info.img.data = (int *)mlx_get_data_addr(setup->info.img.img, &setup->info.img.bpp, &setup->info.img.size_l, &setup->info.img.endian);
	mlx_loop_hook(setup->mlx, &main_loop, setup);
	mlx_hook(setup->info.win, X_EVENT_KEY_PRESS, 0, &key_press, setup);
	mlx_loop(setup->mlx);
	return (0);
}