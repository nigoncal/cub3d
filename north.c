/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:02:15 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/11 16:03:55 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3D.h"
#include <stdbool.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h" // en a-t-il besoin ?

static int	format_check(char *file, char *format)
{
	if (file && format && *file && *format)
	{
		while (*file)
			file++;
		file -= strlen(format);
		while (*file && *format)
		{
			if (*file != *format)
				return (1);
			file++;
			format++;
		}
	}
	return (0);
}

static int	right_path(cub_settings *settings, char **elements)
{
	if (settings->path_id == 1)
		return ((ft_strncmp(elements[0], "NO", ft_strlen(elements[0]))) +
				(settings->north_fd = open(elements[1], O_RDONLY)));
	if (settings->path_id == 2)
		return ((ft_strncmp(elements[0]), "SO", ft_strlen(elements[0])) +
				(settings->south_fd = open(elements[1], O_RDONLY)));
	if (settings->path_id == 3)
		return ((ft_strncmp(elements[0]), "WE", ft_strlen(elements[0])) +
				(settings->west_fd = open(elements[1], O_RDONLY)));
	if (settings->path_id == 4)
		return ((ft_strncmp(elements[0]), "EA", ft_strlen(elements[0])) +
				(settings->east_fd = open(elements[1], O_RDONLY)));
	if (settings->path_id == 5)
		return ((ft_strncmp(elements[0]), "S", ft_strlen(elements[0])) +
				(settings->sprite_fd = open(elements[1], O_RDONLY)));
	return (0);
}

static int	right_amount(char **elements, cub_settings *settings)
{
	int	i;

	i = 0;
	while (elements[i])
		i++;
	if (i != 2)
		return (1);
	if (check_everything(settings, elements))
		return (1);
	return (0);
}

int			north(char *line, cub_settings *settings)
{
	char **elements; // a free ?

	if (settings->NO == true)
		return (1);
	elements = ft_split(line, ' ');
	if (right_amount(elements, settings) || right_path(elements, settings)) // possibilite d'n mettre plusieurs sur une ligne ? au lieu d'avoir plusieurs ligne de return (1)
		return (1);
	settings->NO = true;
	return (0);
}
