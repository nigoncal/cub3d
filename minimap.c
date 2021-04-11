#define mapWidth 4
#define mapHeight 5
#include"header.h"

void create_mini_map(t_screen *sc)
{

int count_x = 0;
int count_y = 0;
int ratio = 0;
    int worldMap[mapWidth][mapHeight]=
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

int i = 0;
char tab[5] = "01011";
while(i != 5)
{
    sc->i = sc->i + 50;
    sc->j = 0;
    put_square(50, sc);
    i++;
}
}

void    put_square(int lenght, t_screen *sc)
{
while(sc->j < lenght)
{
    while(sc->i < lenght)
    {
      put_pixel(sc);
      sc->i++;
    }
    sc->i = 0;
    sc->j++;
}
lenght = lenght *2;
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