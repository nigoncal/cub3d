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
# include <stdbool.h>

typedef	struct	s_parsed_IDs
{
	bool	res;
	bool	NO_tex;
	bool	SO_tex;
	bool	WE_tex;
	bool	EA_tex;
	bool	Sprite;
	bool	Floor;
	bool	Ceiling;
	bool	Map;
}				t_parsed_IDs;

typedef struct s_setup
{
	struct s_parsed_IDs	IDs;
	int					cub_fd;
	int					res_w;
	int					res_h;
	int					max_w;
	int					max_h;
	char				*north_texture_path;
	char				*south_texture_path;
	char				*west_texture_path;
	char				*east_texture_path;
	char				*sprite_texture_path;
	int					floor_red;
	int					floor_green;
	int					floor_blue;
	int					ceiling_red;
	int					ceiling_green;
	int					ceiling_blue;
	int					nb_parsed_values;
	char				**map;
	int					map_start_line;
	bool				map_size_known;
	int					map_longest_line;
	int					map_nb_lines;
	bool				map_malloced;
	int					map_tab_line;
	int					map_player_orientation;
	/*pointeurs mlx etc*/
	void				*mlx;
}				t_setup;

/* Parsing */

int		parse_args(int argc, char **argv, t_setup *setup);
int		check_file(char *path, char *extension);
int		parse_res_ID(char **elements, t_setup *setup);
int		parse_resolution(char **tab, t_setup *setup);
int		cap_resolution(t_setup *setup);
int		parse_tex_ID(char **elements, t_setup *setup);
int		parse_textures(char **tab, t_setup *setup);

/* Utils */
int		skip_ws(char const *str);
int		skip_non_digits(char const *str, int skip_what);
char	*is_line_empty(char *line);
int		get_map_size(char *line, t_setup *setup);
int		open_file(t_setup *setup, int fd);
int		parse_map(char *line, t_setup *setup);

/* GNL */

int		get_next_line(int fd, char **line);

/* Exit */

int		free_2d_tab(char **tab, int l);

#endif
