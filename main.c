#include "header.h"
#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define mapWidth 4
#define mapHeight 5



int main(void)
{
  t_screen sc;
  init(&sc);

if (sc.pixel_bits != 32)
    sc.color = mlx_get_color_value(sc.mlx, sc.color);

while(sc.j < sc.max_h)
{
    while(sc.i < sc.max_w)
    {
      put_pixel(&sc);
      sc.i++;
    }
    sc.i = 0;
    sc.j++;
}
  mlx_put_image_to_window(sc.mlx, sc.win, sc.image, 0, 0);
  mlx_loop(sc.mlx);
  return (0);
}

void  get_map()
{
  t_screen sc;
  init(&sc);

  int worldMap[mapWidth][mapHeight]=
  {
    {1,1,1,1,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,1,1,1,1}
  };

}


void    put_pixel(t_screen *screen)
{
   screen->pixel = (screen->j * screen->line_bytes) + (screen->i * 4);


    if (screen->endian == 0)   // Least significant (Blue) byte first
    {
        screen->buffer[screen->pixel + 0] = (screen->color) & 0xFF;
        screen->buffer[screen->pixel + 1] = (screen->color >> 8) & 0xFF;
        screen->buffer[screen->pixel + 2] = (screen->color >> 16) & 0xFF;
        screen->buffer[screen->pixel + 3] = (screen->color >> 24);
    }
}

void  init(t_screen *screen)
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