/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:50:51 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/05 14:10:42 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <stdio.h> // a virer

typedef struct	s_settings
{
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
}				map_settings;


void			cub3D(int fd, char **line);
void			ft_parse(char *line, map_settings *settings);
void			resolution(char *line, map_settings *settings);
void			ft_map(char *line, map_settings *settings);
void			ft_add_line_map(char *line, map_settings *settings);
void			texture(char *line, map_settings *settings);

#endif
