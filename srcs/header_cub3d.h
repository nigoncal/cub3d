/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:00:12 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/16 13:45:29 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_CUB3D_H
# define HEADER_CUB3D_H
# define COLOR_MAX 255
// check tous les includes et vires si pas besoin
# include "mlx/mlx.h"
# include "libft/libft.h"
//# include "key_macros.h"
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>
# include <strings.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef union	u_color
{
	struct	s_chan
	{
		uint8_t	alpha;
		uint8_t	red;
		uint8_t	green;
		uint8_t	blue;
	}		chan;
	uint32_t color;
}				t_col;

typedef struct	s_settings
{
	bool	screenshot;
	bool	res;
	bool	north;
	bool	south;
	bool	east;
	bool	west;
	bool	sprite;
	bool	b_floor;
	bool	b_ceiling;
	bool	map_started;
	bool	player;
	bool	map_over;
	void	*mlx;
	int		id_counter;
	char	**elements;
	int		width;
	int		height;
	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
	char	*sprite_texture_path;
	t_col	f_color;
	t_col	c_color;
	char	**map;
}				t_settings;

/*typedef struct	s_info

  t_settings ok;
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
  char		*buffer; // MALLOC
  int 		lineHeight;
  int			line_lenght;
  int  		BPP;
  int			height; //Hauteur
  int 		width; //Largeur
  void	*mlx; // MALLOC
  void	*win; // MALLOC
  void	*image; // MALLOC
// MALLOC D'AUTRES CHOSES QUE NICO EST EN TRAIN DE CODER
}				t_info;*/

void			abort_prog(char *s);
void			start(int fd, char **line, t_settings *cub_sets);
int				non_empty_line(char *line);
void			parse_id(char *line, t_settings *cub_sets);
void			p_resolution(char *line, t_settings *cub_sets);
void			p_textures(char *line, t_settings *cub_sets);
int				p_north_texture(char *line, t_settings *cub_sets);
int				p_south_texture(char *line, t_settings *cub_sets);
int				p_east_texture(char *line, t_settings *cub_sets);
int				p_west_texture(char *line, t_settings *cub_sets);
int				p_sprite_texture(char *line, t_settings *cub_sets);
void			parse_map(char *line, t_settings *cub_sets);
void			store_map(char *line, t_settings *cub_sets);
int				square_map(t_settings *cub_sets);
void			p_floor(char *line, t_settings *cub_sets);
void			p_ceiling(char *line, t_settings *cub_sets);
//void			free_struct(t_settings *cub_sets);
/*void			create_windows(t_info *info);
  void			put_square( int lenght, t_screen *sc);
  void			create_mini_map(t_screen *sc);
  void			init(t_info *info);
  void			put_pixel(t_screen *screen);
  void			get_map();
  void			verLine(t_info *info, int x, int y1, int y2, int color);
  int				key_hook(int keycode);
  int				main_loop(t_info *info);
  int				key_press(int key, t_info *info);
  void			add_line_map(char *line, t_settings *cub_sets);
  void			ft_map(char *line, t_settings *cub_sets);
  void			calc(t_info *info);
  void			raycast_cal(t_info *info);
  void			raycast_calc_dir(t_info *info);
  void			raycast_calc_delta(t_info *info);
  void			raycast_calc_pos(t_info *info);*/

#endif
