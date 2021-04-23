/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:00:12 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/23 11:13:30 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_CUB3D_H
# define HEADER_CUB3D_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/errno.h> // pour errno, je le garde ?
# include <string.h>
# include "../get_next_line/get_next_line.h"
# include "minilibx/mlx.h" // attention

typedef struct	s_map
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
	char	map_char[4];
	map_char
}				t_map;


void			start(int fd, char **line, t_settings *cub_sets);
void			parse_id(char *line, t_settings *cub_sets);
void			parse_map(char *line, t_settings *cub_sets);
//void			ft_map(char *line, t_settings *cub_sets); // rename et vires le de parser.c
//void			add_line_map(char *line, t_settings *cub_sets);
void			p_resolution(char *line, t_settings *cub_sets);
int				p_north_texture(char *line, t_settings *cub_sets);
int				p_south_texture(char *line, t_settings *cub_sets);
int				p_west_texture(char *line, t_settings *cub_sets);
int				p_east_texture(char *line, t_settings *cub_sets);
int				p_sprite_texture(char *line, t_settings *cub_sets);
void			abort_prog(char *line, t_settings *cub_sets, char *s);

#endif
