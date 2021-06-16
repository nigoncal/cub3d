/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:00:12 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/16 09:47:49 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define COLOR_MAX 255
# define ERROR -1
# define RAS 0

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17

# define ROTATE_LEFT		123
# define ROTATE_RIGHT		124
# define MOVE_A				2
# define MOVE_D				0
# define MOVE_W				13
# define MOVE_S				1

# define EXIT_ESC			53



// check tous les includes et vires si pas besoin
# include "../mlx/mlx.h"
# include "../libft/libft.h"
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

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;


typedef union	u_color
{
	struct	s_chan
	{
		uint8_t	alpha;
		uint8_t	red;
		uint8_t	green;
		uint8_t	blue;
	}		chan;
	uint32_t	color;
}				t_col;


typedef struct	s_data {
	void		*img;
	char		*addr; // *data
	int		line_length; //size_l
	int		bits_per_pixel; // bpp
	int		endian;
	int		width;
	int		height; // img_height
}				t_data; // t_img

typedef struct s_game
{
	t_col		f_color;
	t_col		c_color;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		planeX; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double		planeY; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)

	double		raydir_x; //calcul de direction x du rayon
	double		raydir_y; //calcul de direction y du rayon
	double		camera_x; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	double		wall_x;
	int			map_x; // coordonée x du carré dans lequel est pos
	int			map_y; // coordonnée y du carré dans lequel est pos
	double		sidedist_x; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double		sidedist_y; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double		deltadist_x; //distance que rayon parcours entre chaque point d'intersection vertical
	double		deltadist_y; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int			step_x; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int			step_y; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int			hit; // 1 si un mur a ete touche, 0 sinon
	int			side;
	double		perpwalldist; // distance du joueur au mur
	int			lineheight; //hauteur de la ligne a dessiner
	int			drawstart; //position de debut ou il faut dessiner
	int			drawend; //position de fin ou il faut dessiner
	double		movespeed;
	double		rotspeed;
	int			width;
	int			height;
	int			texdir;
	int			**texture;
	int			color;
	int 		tex_y;
	int			tex_x;
	double		step;
	double		tex_pos;
	int 		buf[720][1280];
	void		*image;
}				t_game;

typedef struct	s_setup
{
	void	*win;
	void	*mlx;
	int		north_format;
	int		south_format;
	int		east_format;
	int		west_format;
	bool	north;
	bool	south;
	bool	east;
	bool	west;
	bool	b_floor;
	bool	b_ceiling;
	bool	map_started;
	bool	map_over;
	int		id_counter;
	char	**elements;
	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
	char	**map;
	char	**squared_map;
	int		map_xsize;
	int		map_ysize;
	char	player_dir;
	int		x;
	int		y;
	t_img	img;
	t_game	game;
}				t_setup;

void			abort_prog(char *s);
int				non_empty_line(char *line);
void			parse_id(char *line, t_setup *setup);
void			textures(char *line, t_setup *setup);
void			north_texture(char *line, t_setup *setup);
void			south_texture(char *line, t_setup *setup);
void			east_texture(char *line, t_setup *setup);
void			west_texture(char *line, t_setup *setup);
void			parse_floor(char *line, t_setup *setup);
void			ceiling(char *line, t_setup *setup);
void			parse_map(char *line, t_setup *setup);
void			store_map(char *line, t_setup *setup);
void			square_map(t_setup *setup);
void			check_map(t_setup *setup);
void			graph_textures(t_setup *setup);
int				alloc_storage(t_setup *setup);
void			tex_orientation(t_setup *setup);
/*void			create_windows(t_setup *setup);
  void			put_square( int lenght, t_screen *sc);
  void			create_mini_map(t_screen *sc);
  void			init(t_setup *setup);
  void			put_pixel(t_screen *screen);
  void			get_map();
  void			verLine(t_setup *setup, int x, int y1, int y2, int color);
  int				key_hook(int keycode);
  int				main_loop(t_setup *setup);
  int				key_press(int key, t_setup *setup);
  void			add_line_map(char *line, t_setup *setup);
  void			ft_map(char *line, t_setup *setup);
  void			calc(t_setup *setup);
  void			raycast_cal(t_setup *setup);
  void			raycast_calc_dir(t_setup *setup);
  void			raycast_calc_delta(t_setup *setup);
  void			raycast_calc_pos(t_setup *setup);*/


/* GRAPHIC */

int				graph_main(t_setup *setup);
void			draw(t_setup *setup);
void			init_buf(t_setup *setup);
void			dda(t_setup *setup);

#endif
