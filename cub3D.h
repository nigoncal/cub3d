#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 64

# include "../libft/libft.h"
# include "minilibx/mlx.h"
# include "srcs/get_next_line.h"

# include <math.h>
# include <unistd.h>
# include <stdio.h> // a virer

/* == GNL INCLUDES == */
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_setup
{
	int		res_w;
	int		res_h;
	int		max_w;
	int		max_h;
	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
	char	*sprite_texture_path;
	int		floor_red;
	int		floor_green;
	int		floor_blue;
	int		ceiling_red;
	int		ceiling_green;
	int		ceiling_blue;
	char	**map;
	int		nb_parsed_values;
	//pointeurs mlx etc
	void	*mlx;
}				t_setup;

int		parse_args(int argc, char **argv, t_setup *setup);
int		skip_ws(char const *str);
int		skip_non_digits(char const *str, int skip_what);
int		parse_textures(char *line, t_setup *setup);

// GNL

int		get_next_line(int fd, char **line);

// from Sylducam

void	cub3D(int fd, char **line);
void	parse(char *line, t_setup *settings);
void	resolution(char *line, t_setup *settings);
void	ft_map(char *line, t_setup *settings);
void	ft_add_line_map(char *line, t_setup *settings);
void	texture(char *line, t_setup *settings);

#endif
