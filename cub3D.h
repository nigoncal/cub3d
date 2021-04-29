#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 64

/* HEADERS */
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
	int		nb_parsed_IDs;
}				t_parsed_IDs;

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
	/*PARSING from Sylducam*/
	bool			screenshot;
	bool			R;
	bool			NO;
	bool			SO;
	bool			EA;
	bool			WE;
	bool			S;
	bool			F;
	bool			C;
	/*OTHER*/
	void			*mlx;
	int				width;
	int				height;
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
	char			map_char[8];
}				t_settings;

typedef struct	s_info
{
	t_settings		ok;
	/* Paulicorne's structs */
	t_parsed_IDs	IDs;
	t_map			map_info;
	/* adding stuff to implement Paulicorne's parsing */
	int				cub_fd;
	/* Game info */
	double			posX; //position x du joueur
	double			posY; //position y du joueur
	double			dirX; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double			dirY; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double			planeX; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double			planeY; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double			raydirX; //calcul de direction x du rayon
	double			raydirY; //calcul de direction y du rayon
	double			cameraX; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int				mapX; // coordonée x du carré dans lequel est pos
	int				mapY; // coordonnée y du carré dans lequel est pos
	double			sidedistX; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double			sidedistY; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double			deltadistX; //distance que rayon parcours entre chaque point d'intersection vertical
	double			deltadistY; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int				stepX; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int				stepY; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int				hit; // 1 si un mur a ete touche, 0 sinon
	int				side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double			perpwalldist; // distance du joueur au mur
	int				lineheight; //hauteur de la ligne a dessiner
	int				drawstart; //position de debut ou il faut dessiner
	int				drawend; //position de fin ou il faut dessiner
	int				x; //permet de parcourir tous les rayons
	double			moveSpeed;
	double			rotSpeed;
	int				color;
	int				endian;
	char			*buffer;
	int				lineHeight;
	int				line_lenght;
	int				BPP;
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
int		parse_ID(char *ID, char *expected, int max);
int		parse_tex_ID(char **elements, t_info *info);

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

/* GRAPHIC */

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

/* Exit */

int		free_2d_tab(char **tab, int l);

#endif