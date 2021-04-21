/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:00:12 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/21 17:21:34 by sylducam         ###   ########lyon.fr   */
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
# include "minilibx/mlx.h" // attention

// commentaire a laisser pour expliquer a quoi correspond chaque chiffre du path id

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


void			start(int fd, char **line);
void			parse_id(char *line, t_settings *cub_sets);
void			parse_map(char *line, t_settings *cub_sets);
void			p_resolution(char *line, t_settings *cub_sets);
//void			ft_map(char *line, t_settings *cub_sets); // rename et vires le de parser.c
//void			add_line_map(char *line, t_settings *cub_sets);
void			abort_prog(char *line, t_settings *cub_sets, char *s);

int				p_north_texture(char *line, t_settings *cub_sets);

#endif
