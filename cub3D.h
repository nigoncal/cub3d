#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 64

/* HeaDERS */
# include "mlx/mlx.h"
# include "key_macros.h"
# include "libft/libft.h"

/* LIBRARIES */
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

/* GNL INCLUDES */
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

/* Paulicorne's structs */

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
	int		nb_parsed_ids;
}				t_parsed_ids;

typedef	struct	s_map
{
	int		map_start_line;
	bool	map_size_known;
	int		map_longest_line;
	int		map_nb_lines;
	bool	map_malloced;
	int		map_tab_line;
	int		map_player_orientation;
}				t_map;

/* Nigoncal's structs */
typedef struct	s_settings
{
	/*PARSING Paulicorne*/
	int				max_w;
	int				max_h;
	/*PARSING from Sylducam*/
	bool			screenshot;
	bool			r;
	bool			no;
	bool			so;
	bool			ea;
	bool			we;
	bool			s;
	bool			f;
	bool			c;
	/*OTHER*/
//doublon avec la struct t_info
//	void			*mlx;
//	int				width;
//	int				height;
	char			*north_texture_path;
	char			*south_texture_path;
	char			*west_texture_path;
	char			*east_texture_path;
	char			*sprite_texture_path;
	int				floor_red;
	int				floor_green;
	int				floor_blue;
	int				ceiling_red;
	int				ceiling_green;
	int				ceiling_blue;
	char			**map;
// je sais pas a quoi sert cette string ?
	char			map_char[8];
}				t_settings;

typedef struct	s_info
{
	t_settings		setup;
	/* Paulicorne's structs */
	t_parsed_ids	ids;
	t_map			map_info;
	/* adding stuff to implement Paulicorne's parsing */
	int				cub_fd;
	/* Game info */
	double			pos_x; //position x du joueur
	double			pos_y; //position y du joueur
	double			dir_x; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double			dir_y; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double			plane_x; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double			plane_y; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double			raydir_x; //calcul de direction x du rayon
	double			raydir_y; //calcul de direction y du rayon
	double			camera_x; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int				map_x; // coordonée x du carré dans lequel est pos
	int				map_y; // coordonnée y du carré dans lequel est pos
	double			sidedist_x; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double			sidedist_y; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double			deltadist_x; //distance que rayon parcours entre chaque point d'intersection vertical
	double			deltadist_y; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int				step_x; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int				step_y; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int				hit; // 1 si un mur a ete touche, 0 sinon
	int				side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double			perpwalldist; // distance du joueur au mur
	int				line_height; //hauteur de la ligne a dessiner
	int				drawstart; //position de debut ou il faut dessiner
	int				drawend; //position de fin ou il faut dessiner
	int				x; //permet de parcourir tous les rayons/colonnes/la largeur de l'img
	double			move_speed;
	double			rot_speed;
	int				color;
	int				endian;
	char			*buffer;
//	int				line_height; //(doublon, cf plus haut)
	int				line_lenght;
	int				bpp;
	int				height;
	int				width;
	void			*mlx;
	void			*win;
	void			*image;
}				t_info;

/* on garde ou pas ? (utilisé pour la minimap, put_square et put_pixel) */
typedef struct s_screen
{
	int		pixel;
	int		color;
	char	*buffer; // contient toutes les nuances de pixels pour l'image
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	float	rayon_sp;

	int		i;
	int		j;

	int		max_h;
	int		max_w;

}	t_screen;

/* ====== PARSING ======= */

/* Paulicorne's functions */
int		parse_args(int argc, char **argv, t_info *info);
int		parse_map(char *line, t_info *info);
int		open_file(t_info *info, int fd);
int		parse_id(char *id, char *expected, int max);
int		parse_tex_id(char **elements, t_info *info);
int		parse_resolution(char **tab, t_info *info);

/* other parsing functions */
void 	get_map();
int		key_hook(int keycode);
int		main_loop(t_info *info);
int		key_press(int key, t_info *info);
void	add_line_map(char *line, t_settings *cub_sets);
void	ft_map(char *line, t_settings *cub_sets);

/* === Parsing utils === */
/* Paulicorne's */
char	*is_line_empty(char *line);
char	*change_char(char *str, char new, char old, bool do_free);
int		skip_ws(char const *str);

/* === GRAPHIC === */

void	init(t_info *info);
void	put_pixel(t_screen *screen);
void	create_windows(t_info *info);
void	put_square(int lenght, t_screen *sc);
void	create_mini_map(t_screen *sc);
void	verLine(t_info *info, int x, int y1, int y2);
void	calc(t_info *info);
void	raycast_cal(t_info *info);
void	raycast_calc_dir(t_info *info);
void	raycast_calc_delta(t_info *info);
void	raycast_calc_pos(t_info *info);

/* === Exit === */

int		free_2d_tab(char **tab, int l);

#endif