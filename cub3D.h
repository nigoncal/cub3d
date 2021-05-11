#ifndef CUB3D_H
# define CUB3D_H
# define ERROR -1
# define RAS 0
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

typedef	struct	s_parsed_ids
{
	bool	res;
	bool	no_tex;
	bool	so_tex;
	bool	we_tex;
	bool	ea_tex;
	bool	sprite;
	bool	floor;
	bool	ceiling;
	bool	map;
}				t_parsed_ids;

typedef struct s_setup
{
	struct s_parsed_ids	ids;
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
int		parse_id(char *id, char *expected, int max);
//int		parse_res_ID(char **elements, t_setup *setup);
int		parse_resolution(char **tab, t_setup *setup);
int		cap_resolution(t_setup *setup);
int		parse_tex_id(char **elements, t_setup *setup);
int		parse_textures(char **tab, t_setup *setup);

/* Parsing utils */
int		skip_ws(char const *str);
int		skip_non_digits(char const *str, int skip_what);
char	*is_line_empty(char *line);
int		get_map_size(char *line, t_setup *setup);
int		open_file(t_setup *setup, int fd);
int		parse_map(char *line, t_setup *setup);
char	*change_char(char *str, char new, char old, bool do_free);

/* GNL */

int		get_next_line(int fd, char **line);

/* Exit */

int		free_2d_tab(char **tab, int l);

#endif
