# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include "mlx/mlx.h"

/* == GNL INCLUDES == */
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
#include "libft/libft.h"
#include "mlx/mlx.h"
typedef struct s_screen
{
	void	*mlx;
	void	*win;
	void	*image;
	
	int		pixel;
	int		color;
	char	*buffer;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	float	rayon_sp;

	int		i;
	int		j;

	int		max_h;
	int		max_w;

}	t_screen;


void 	init(t_screen *screen);
void	put_pixel(t_screen *screen);
void 	get_map();