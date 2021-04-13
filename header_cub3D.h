/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:00:12 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/13 13:31:41 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdbool.h>
# include <stdio.h> // a virer
# include <mlx.h>

// commentaire a laisser pour expliquer a quoi correspond chaque chiffre du path id

typedef struct	s_settings
{
	bool	R;
	bool	NO;
	bool	SO;
	bool	EA;
	bool	WE;
	bool	S;
	bool	F;
	bool	C;
	int		width;
	int		height;
	int		path_id;
/*
  	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
	char	*sprite_texture_path;

toute cette partie je la emplace par juste les fd ?
*/
	int		north_fd;
	int		south_fd;
	int		west_fd;
	int		east_fd;
	int		sprite_fd;
	int		floor_red;
	int		floor_green;
	int		floor_blue;
	int		ceiling_red;
	int		ceiling_green;
	int		ceiling_blue;
	char	**map;
}				cub_settings;


void			cub3d(int fd, char **line);
void			ft_parse(char *line, cub_settings *settings);
void			resolution(char *line, cub_settings *settings);
void			ft_map(char *line, cub_settings *settings);
void			ft_add_line_map(char *line, cub_settings *settings);
void			texture(char *line, cub_settings *settings);
void			abort_prog(char *line, cub_settings *settings, char *s);

int				map_part(char *line);

#endif
