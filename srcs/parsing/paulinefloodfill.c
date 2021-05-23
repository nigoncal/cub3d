#include "../header_cub3D.h"
/* Most of the code comes from Lodev's website */

#define BOARD_WIDTH  33
#define BOARD_HEIGHT 14

 /*typedef struct MAP
 {
   unsigned char b[BOARD_HEIGHT][BOARD_WIDTH];
 } MAP;*/

static void	flood_loop(char **map, int x, int y, char dst_c, char src_c)
{
	int	filll;
	int	fillr;
	int	i;
	int	in_line;
	////unsigned char c = src_c, fillC = dst_c;
	// find left side, filling along the way
	in_line = 1;
	filll = x;
	fillr = x;
	printf("Lol\n");
	while (in_line)
	{
		printf("colonne courante = %d\n", filll);
		printf("ligne courante = %d\n", y);
		//printf("dst_c = %c\n", dst_c);
		//printf("case courante : %c\n", map[y][filll]);
		map[y][filll] = dst_c;
		filll--;
		in_line = (filll < 0) ? 0 : (map[y][filll] == src_c);
	}
	filll++;
	// find right side, filling along the way
	in_line = 1;
	while( in_line )
	{
		map[y][fillr] = dst_c;
		fillr++;
		in_line = (fillr > BOARD_WIDTH-1) ? 0 : (map[y][fillr] == src_c);
	}
	fillr--;
	// search top and bottom : ADAPT WITH A WHILE
	for(i = filll; i <= fillr; i++)
	{
	  if( y > 0 && map[y - 1][i] == src_c )
	      flood_loop(map, i, y - 1, dst_c, src_c);
	  if( y < BOARD_HEIGHT-1 && map[y + 1][i] == src_c )
	      flood_loop(map, i, y + 1, dst_c, src_c);
	}
	int c = 0;
	while (map[c])
	{
		dprintf(1, "cub_sets->map[%d] = |%s|\n", c, map[c]);
		c++;
	}
}

void	flood_fill(char **map, int x, int y, unsigned int c)
{
	flood_loop(map, x, y, c, '0');
	//map->b[y][x] = c;  // some buggy optimizers needed this line
}

int	find_player(t_settings *cub_sets)
{
	bool	player_found;
	int		x;
	int		y;

	player_found = 0;
	y = 0;
	while (cub_sets->map[y])
	{
		x = 0;
		while (cub_sets->map[y][x])
		{
			if (ft_strchr("NSEW", cub_sets->map[y][x]) != 0)
			{
				if (player_found == 1)
					return (ERROR);
				player_found = 1;
				cub_sets->play_x = x;
				cub_sets->play_y = y;
				cub_sets->start_orientation = cub_sets->map[y][x];
			}
			x++;
		}
		y++;
	}
	flood_fill(cub_sets->map, cub_sets->play_x, cub_sets->play_y, 'a');
	return (RAS);
}
