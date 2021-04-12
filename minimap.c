#define mapWidth 4
#define mapHeight 5
#include"header.h"

void create_mini_map(t_screen *sc)
{

int count_x = 0;
int count_y = 0;
int ratio = 0;
    int worldMap[mapWidth + 1][mapHeight + 1]=
  {
    {1,1,1,1,1},
    {1,0,0,0,1},
    {1,0,1,1,1},
    {1,1,1,1,1}
  };

 /* if(worldMap[count_x][count_y] == 1)
    sc->color = 0xFFFFFF;
  else
    sc->color = 0x000000;*/


int len = 50;

sc->i = 500;
sc->j = 500;
      put_square(len, sc);
  }

void    put_square(int len, t_screen *sc)
{
  int tmp_2 = sc->i;
  int tmp = sc->j;

  while(sc->j < tmp + len)
  {
    while(sc->i < tmp_2 + len)
    {
      put_pixel(sc);
      sc->i++;
    }
    sc->i = tmp_2;
  sc->j++;
  }
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