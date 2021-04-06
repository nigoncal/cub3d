/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:24:57 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/02 12:04:19 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3D.h"
#include "libft/libft.h"

// tout d'abord listes toutes tes erreurs possibles et geres les au prealable avec des fonctions

void 	check_path(char *line, map_settings *settings, char)
{

		settings->north_texture_path = ft_strdup(*line);
}

void	texture(char *line, map_settings *settings)
{
	if (line == 'N')
		check_path(N)
	if (line == 'S' && line + 1 == 'O')
		settings->south_texture_path = ft_strdup(*line);
	if (line == 'W')
		settings->west_texture_path = ft_strdup(*line);
	if (line == 'E')
		settings->east_texture_path = ft_strdup(*line);
	if (line == 'S' && line + 1 == ' ')
		settings->sprite_texture_path = ft_strdup(*line);
	while (line != '.')
		line++;
	if (type == 's')
	while (line != '\0')
		line++;
}

/*void	texture(char *line, map_settings *settings)
{
	char type;

	type = 0;
	if (line == 'N')
		type = 'N';
	if (line == 'S' && *(*line + 1) == 'O')
		type = 'S';
	if (line == 'W')
		type = 'W';
	if (line == 'E')
		type = 'E';
	if (line + 1 == ' ')
		type = 's';
	while (line != '.')
		line++;
	if (type == 'N')
		settings->north_texture_path = ft_strdup(*line);
	if (type == 'S')
		settings->south_texture_path = ft_strdup(*line);
	if (type == 'W')
		settings->west_texture_path = ft_strdup(*line);
	if (type == 'E')
		settings->east_texture_path = ft_strdup(*line);
	if (type == 's')
		settings->sprite_texture_path = ft_strdup(*line);
	while (line != '\0')
		line++;
}*/
