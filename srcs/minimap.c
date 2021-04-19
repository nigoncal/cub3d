#define mapWidth 4
#define mapHeight 5
#include "../cub3D.h"

void create_mini_map(t_screen *sc)
{

  int count_x = 0;
  int count_y = 0;
  int worldMap[mapWidth][mapHeight] =
      {
          {1, 1, 1, 1, 1},
          {1, 0, 0, 0, 1},
          {1, 0, 1, 1, 1},
          {1, 1, 1, 1, 1}};
  int len = 150;
  while (count_x != mapWidth)
  {
    while (count_y != mapHeight)
    {
      if (worldMap[count_x][count_y] == 1)
        sc->color = 0xFF0000;
      else
        sc->color = 0xFFFFFF;
      put_square(len, sc);
      sc->i += len;
      count_y++;
    }
    count_y = 0;
    sc->i = 0;
    sc->j += len;
    count_x++;
  }
}

void put_square(int len, t_screen *sc)
{
  int tmp_2 = sc->i;
  int tmp = sc->j;

  while (sc->j < tmp + len)
  {
    while (sc->i < tmp_2 + len)
    {
      put_pixel(sc);
      sc->i++;
    }
    sc->i = tmp_2;
    sc->j++;
  }
  sc->j = tmp;
}

void put_pixel(t_screen *screen)
{
  screen->pixel = (screen->j * screen->line_bytes) + (screen->i * 4);

  if (screen->endian == 0) // Least significant (Blue) byte first
  {
    screen->buffer[screen->pixel + 0] = (screen->color) & 0xFF;
    screen->buffer[screen->pixel + 1] = (screen->color >> 8) & 0xFF;
    screen->buffer[screen->pixel + 2] = (screen->color >> 16) & 0xFF;
    screen->buffer[screen->pixel + 3] = (screen->color >> 24);
  }
}
/*while(count_x != 3)
{
    while(worldMap[count_x][count_y])
    {
      if(worldMap[count_x][count_y] == '1')
        sc->color = 0xFFFFFF;
      else
        sc->color = 0x000009;
      put_square(len, sc);
      sc->i += len;
      count_y++;
    }
    count_y = 0;
    count_x++;
    sc->j += len;
}*/

/* if(worldMap[count_x][count_y] == 1)
    sc->color = 0xFFFFFF;
  else
    sc->color = 0x000000;*/