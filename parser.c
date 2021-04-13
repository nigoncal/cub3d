/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:06:21 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/13 17:10:01 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h> // a virer

void	color(char **line, cub_settings *settings)
{
	if (*(*line) == 'C')
	{
		settings->ceiling_red = ft_pf_atoi(line);
		settings->ceiling_green = ft_pf_atoi(line);
		settings->ceiling_blue = ft_pf_atoi(line);
	}
	if (*(*line) == 'F')
	{
		settings->floor_red = ft_pf_atoi(line);
		settings->floor_green = ft_pf_atoi(line);
		settings->floor_blue = ft_pf_atoi(line);
	}
}

void	ft_add_line_map(char **line, cub_settings *settings)
{
	int		size;
	int		i;
	char	**temp;

	size = 0;
	i = 0;
	while (settings->map[size])
		size++;
	size++;
	if ((temp = (char**)malloc(sizeof(char*) * size + 1)) == NULL)
		return ; // error message
	while (size--)
	{
		temp[i] = ft_strdup(settings->map[i]);
		i++;
	}
	temp[i - 1] = ft_strdup(*line);
	temp[i] = 0;
	free(settings->map);
	settings->map = temp;
}

void	ft_map(char **line, cub_settings *settings)
{
	if (settings->map == NULL)
	{
		if ((settings->map = (char**)malloc(sizeof(char*) + 1)) == NULL)
			return ; // error message
		settings->map[0] = ft_strdup(*line);
		settings->map[1] = 0;
	}
	else
		ft_add_line_map(line, settings);
	while (*(*line) != '\0')
		(*line)++;
}

void	parse_id(char *line, cub_settings *settings)
{
	line = change_char(line, ' ', '\t');
	line = change_char(line, ' ', '\v');
	while (line)
	{
		while (line == ' ') // test depuis l'ajout du \t surtout le ||, plutot que le &&
			line++;
		if (line == 'R')
			resolution(line, settings);
		if (line == 'N' || line == 'S' || line == 'E' || line == 'W')
			texture(line, settings);
		// tu en es la
		if (line == 'F' || line == 'C')
			color(line, settings);
		else
			abort_all(line, settings, "Identifiers allowed : R, NO, SO, WE, EA, S, F, C");
	}
}

void	parse_map(char *line, cub_settings *settings)
{
	while (line)
	{
		if (ft_isalnum(line)) // map : peut commencer par et contenir |' '/1/0/2/N/S/W/E|.
			ft_map(line, settings);
	}
}
