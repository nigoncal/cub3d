/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:02:15 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/12 12:01:29 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3D.h"
#include <stdbool.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h" // en a-t-il besoin ?
#include <strings.h>

static int	right_format(char *file, char *format)
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

static int	right_file(char **elements, cub_settings *settings)
{
	if (ft_strcmp(elements[0], "NO")) // ok niveau parentheses ? trop ?
		return (1);
	if ((right_format(elements[1], ".xpm")) &&
			(right_format(elements[1], ".png"))) // ok dans bazar_a_test, a tester ici
		return (1);
	if (settings->north_fd = open(elements[1], O_RDONLY))
		return (1);
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
	if (right_file(elements, settings))
		return (1);
	return (0);
}

int			north(char *line, cub_settings *settings)
{
	char **elements; // a free ?

	if (settings->NO == true)
		return (1);
	change_char(line);
	elements = ft_split(line, ' ');
	if (right_amount(elements, settings)) // possibilite d'en mettre plusieurs sur une ligne ? au lieu d'avoir plusieurs ligne de return (1)
		return (1);
	settings->NO = true;
	return (0);
}

int main()
{
	char *line;
	line = strdup("N");
}
