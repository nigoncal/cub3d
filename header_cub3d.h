/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:00:12 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/15 17:51:26 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

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
	void	*mlx; // ou je lui fais mlx = mlx_init ? main plus trop de place, voir si j'en fait ou sinon start
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
}				cub_settings;


void			start(int fd, char **line);
void			parse_id(char *line, cub_settings *settings);
void			parse_map(char *line, cub_settings *settings);
void			resolution(char *line, cub_settings *settings);
//void			ft_map(char *line, cub_settings *settings); // rename et vires le de parser.c
//void			add_line_map(char *line, cub_settings *settings);
void			abort_prog(char *line, cub_settings *settings, char *s);

int				north_texture(char *line, cub_settings *settings);

#endif
