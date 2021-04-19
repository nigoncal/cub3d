#include "../cub3D.h"
#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64




int main(void)
{
  t_screen sc;
  t_ray ray;
  init_screen(&sc);
  ft_bzero(&ray, sizeof(ray));
  //create_mini_map(&sc);
  ray_cast_test(&sc);
  mlx_put_image_to_window(sc.mlx, sc.win, sc.image, 0, 0);
  mlx_loop(sc.mlx);
  return (0);
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
