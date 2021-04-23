# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include"libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdbool.h>
/* == GNL INCLUDES == */
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
#include "mlx/mlx.h"



	typedef struct	s_info
{
	double		posX; //position x du joueur
	double		posY; //position y du joueur
	double		dirX; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double		dirY; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double		planeX; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double		planeY; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double		raydirX; //calcul de direction x du rayon
	double		raydirY; //calcul de direction y du rayon
	double		cameraX; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int			mapX; // coordonée x du carré dans lequel est pos
	int			mapY; // coordonnée y du carré dans lequel est pos
	double		sidedistX; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double		sidedistY; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double		deltadistX; //distance que rayon parcours entre chaque point d'intersection vertical
	double		deltadistY; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int			stepX; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int			stepY; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int			hit; // 1 si un mur a ete touche, 0 sinon
	int			side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double		perpwalldist; // distance du joueur au mur
	int			lineheight; //hauteur de la ligne a dessiner
	int			drawstart; //position de debut ou il faut dessiner
	int			drawend; //position de fin ou il faut dessiner
	int			x; //permet de parcourir tous les rayons
	double		moveSpeed;
	double		rotSpeed;
	int			color;
	int			endian;
	char		*buffer;
	int 		lineHeight;
	int			line_lenght;
	int  		BPP;
	int			height; //Hauteur
	int 		width; //Largeur
	void	*mlx;
	void	*win;
	void	*image;
}				t_info;
typedef struct	s_settings
{
	bool	screenshot;
	bool	R;
	bool	NO;
	bool	SO;
	bool	EA;
	bool	WE;
	bool	S;
	bool	F;
	bool	C;
	void	*mlx;
	int		width;
	int		height;
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
	char	map_char[8];
	
}				t_settings;


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


void    put_square( int lenght, t_screen *sc);
void	create_mini_map(t_screen *sc);
void	init(t_info *info);
void    put_pixel(t_screen *screen);
void 	get_map();
void	verLine(t_info *info, int x, int y1, int y2, int color);
int		key_hook(int keycode);
int		main_loop(t_info *info);
int		key_press(int key, t_info *info);
void	add_line_map(char **line, t_settings *cub_sets);
