#ifndef CUB3D_H
# define CUB3D_H

# define ERROR -1
# define RAS 0
# define BUFFER_SIZE 64

/* HEADERS */
# include "../libft/libft.h"
# include "minilibx/mlx.h"
# include "srcs/get_next_line.h"

/* LIBRARIES */
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
	int		nb_encountered;
}				t_parsed_ids;

typedef	struct	s_map
{
	bool	size_known;
	bool	malloced;
	bool	begun;
	bool	start_found;
	int		start_line;
	int		nb_lines;
	int		tab_line;
	int		player_orientation;
	int		longest_line;
	char	**map;
}				t_map;

typedef struct s_setup
{
	t_parsed_ids		ids;
	t_map				map;
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
	/* pointeurs mlx etc */
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
int		parse_color_id(char **elements);

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
