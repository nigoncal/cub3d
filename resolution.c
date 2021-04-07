/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:11:38 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/07 11:27:52 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3D.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h> // a virer

// faire tous les checkings d'erreur

int		check_elements(char **elements)
{
	int	i;

	i = 0;
	while (elements[i])
		i++;
	if (i != 3)
		return (0);
	i = 0;
	if (ft_strncmp(elements[0], "R", 1))
		return (0);
	if (!(ft_isdigit(elements[1])) && !(ft_isdigit(elements[2])))
		return (0);
	settings->width == ft_atoi(elements[1]);
	settings->height == ft_atoi(elements[2]);
	if (settings->width <= 0 || settings->height <= 0)
		return (0);
	return (1);
}

void	resolution(char *line, map_settings *settings)
{
	char **elements;

	if (settings->R == true)
		abort_prog(line, settings, "Identifiers should be used only once");
	elements = ft_split(line, ' ');
	if (!(check_elements(elements)))
		abort_prog(line, settings, "Resolution line not well formated. Usage :\
				\nR <width> <height>\nOnly positive values")
		next_function
}

/*while (line++)
{
	{
		if (settings->width == 0)
			settings->width = ft_atoi(line);
		if (settings->width != 0 && settings->height == 0)
			settings->height = ft_atoi(line);
	}
	while (line = ' ')
		line++;
	line++;
}*/
