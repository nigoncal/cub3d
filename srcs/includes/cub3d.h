/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:00:12 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/30 17:48:37 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define COLOR_MAX 255
# define ERROR -1
# define RAS 0
// check tous les includes et vires si pas besoin
# include "../mlx/mlx.h"
# include "../../libft/libft.h"
# include "key_macos.h"
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
	uint32_t	color;
}				t_col;

typedef struct	s_sprite
{
	
}				t_sprite;

typedef struct	s_textures
{
//	char	*buffer;
//	char	*; // a renommer
}				t_textures;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct s_game
{
	t_col		f_color;
	t_col		c_color;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
//	double		planeX; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
//	double		planeY; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
//	double		raydirX; //calcul de direction x du rayon
//	double		raydirY; //calcul de direction y du rayon
//	double		cameraX; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
//	int			mapX; // coordonée x du carré dans lequel est pos
//	int			mapY; // coordonnée y du carré dans lequel est pos
//	double		sidedistX; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
//	double		sidedistY; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
//	double		deltadistX; //distance que rayon parcours entre chaque point d'intersection vertical
//	double		deltadistY; //distance que le rayon parcours entre chaque point d'intersection horizontal
//	int			stepX; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
//	int			stepY; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
//	int			hit; // 1 si un mur a ete touche, 0 sinon
	int			side;
	double		perpwalldist; // distance du joueur au mur
//	int			lineheight; //hauteur de la ligne a dessiner
//	int			drawstart; //position de debut ou il faut dessiner
//	int			drawend; //position de fin ou il faut dessiner
//	int			x; //permet de parcourir tous les rayons
//	double		moveSpeed;
//	double		rotSpeed;
//	int			endian;
//	char		*buffer;
//	int			line_height;
//	int			line_lenght;
//	int			BPP;
	int			width;
	int			height;
	t_data		texture[4];
//	void		*win;
//	void		*image;
}				t_game;

typedef struct	s_setup
{
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
	t_game	game;
}				t_setup;

void			abort_prog(char *s);
void			start(int fd, char **line, t_setup *setup);
int				non_empty_line(char *line);
void			parse_id(char *line, t_setup *setup);
void			p_resolution(char *line, t_setup *setup);
void			p_textures(char *line, t_setup *setup);
void			p_north_texture(char *line, t_setup *setup);
void			p_south_texture(char *line, t_setup *setup);
void			p_east_texture(char *line, t_setup *setup);
void			p_west_texture(char *line, t_setup *setup);
void			p_sprite_texture(char *line, t_setup *setup);
void			p_floor(char *line, t_setup *setup);
void			p_ceiling(char *line, t_setup *setup);
void			parse_map(char *line, t_setup *setup);
void			store_map(char *line, t_setup *setup);
void			square_map(t_setup *setup);
void			flood_fill(char **map, int y, int x, t_setup *setup);
void			find_player(t_setup *setup);
void			check_map(t_setup *setup);
void			graph_textures(t_setup *setup);

/* GRAPHIC */

int    graph_main(void);

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
  void			add_line_map(char *line, t_setup *setup);
  void			ft_map(char *line, t_setup *setup);
  void			calc(t_info *info);
  void			raycast_cal(t_info *info);
  void			raycast_calc_dir(t_info *info);
  void			raycast_calc_delta(t_info *info);
  void			raycast_calc_pos(t_info *info);*/

#endif
