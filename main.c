#include "header.h"
#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64




int main(void)
{
  t_screen sc;
  t_ray ray;
  init_screen(&sc);
  init_ray(&ray);

	if (sc.pixel_bits != 32)
    	sc.color = mlx_get_color_value(sc.mlx, sc.color);
  create_mini_map(&sc);
  mlx_put_image_to_window(sc.mlx, sc.win, sc.image, 0, 0);
  mlx_loop(sc.mlx);
  return (0);
}

void	init_ray(t_ray *ray)
{
	 ray->posX = 22, 
	 ray->posY = 12; 
	 ray->dirX = -1;
	 ray->dirY = 0;
	 ray->planX = 0;
	 ray->planY = 0.66;
}

void	init_screen(t_screen *screen)
{
	screen->i = 0;
	screen->j = 0;
	screen->max_h = 1000;
	screen->max_w = 1000;
	screen->pixel_bits = 0;
	screen->line_bytes = 0;
	screen->endian = 0;
	screen->color = 0x66FFCC;
	screen->mlx = mlx_init();
	screen->image = mlx_new_image(screen->mlx, screen->max_w, screen->max_h);
	screen->win = mlx_new_window(screen->mlx, screen->max_w, screen->max_h, "Fenetre de bg");
	screen->buffer = mlx_get_data_addr(screen->image, &screen->pixel_bits, \
	&screen->line_bytes, &screen->endian);
}

void cal_ray(t_vec *ray, t_screen sc, float FOV)
{
	ray->cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
	ray->rayDirX = ray->dirX + ray->planeX * ray->cameraX;
	ray->rayDirY = ray->dirY + ray->planeY * ray->cameraX;
}
