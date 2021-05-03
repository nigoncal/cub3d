/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:00:12 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/03 08:09:34 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_CUB3D_H
# define HEADER_CUB3D_H
// check tous les includes et vires si pas besoin
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/errno.h> // pour errno, je le garde ?
# include <string.h>
# include <strings.h>
# include "libft/libft.h"
# include "minilibx/mlx.h" // attention

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
	bool	map_started;
	bool	map_over;
	void	*mlx;
	int		id_counter;
	int		width;
	int		height;
  	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
	char	*sprite_texture_path;
	int		north_fd;  // a virer, juste pour les tests
	int		south_fd;  // "
	int		west_fd;   // "
	int		east_fd;   // "
	int		sprite_fd; // "
	int		floor_red;
	int		floor_green;
	int		floor_blue;
	int		ceiling_red;
	int		ceiling_green;
	int		ceiling_blue;
	char	**map;
}				t_settings;


void			start(int fd, char **line, t_settings *cub_sets);
int				non_empty_line(char *line);
void			parse_id(char *line, t_settings *cub_sets);
void			p_textures(char *line, t_settings *cub_sets);
void			parse_map(char *line, t_settings *cub_sets);
int				is_map(char *line);
void			store_map(char *line, t_settings *cub_sets);
void			add_line_map(char *line, t_settings *cub_sets);
void			p_resolution(char *line, t_settings *cub_sets);
int				p_north_texture(char *line, t_settings *cub_sets);
int				p_south_texture(char *line, t_settings *cub_sets);
int				p_west_texture(char *line, t_settings *cub_sets);
int				p_east_texture(char *line, t_settings *cub_sets);
int				p_sprite_texture(char *line, t_settings *cub_sets);
void			abort_prog(char *line, t_settings *cub_sets, char *s);

#endif
