/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:11:38 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/07 15:59:22 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include "header_cub3D.h"
#include <stdbool.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h> // a virer

// faire tous les checkings d'erreur

typedef struct	s_settings
{
	bool	R;
	int		width;
	int		height;
}				cub_settings;

int		check_elements(char **elements, cub_settings *settings)
{
	int	i;

	i = 0;
	while (elements[i])
		i++;
	if (i != 3)
		return (0);
	i = 0;
	if (ft_strncmp(elements[0], "R", ft_strlen(elements[0])))
		return (0);
	while (elements[1][i])
		if (!(ft_isdigit(elements[1][i++])))
			return (0);
	i = 0;
	while (elements[2][i])
		if (!(ft_isdigit(elements[2][i++])))
			return (0);
	settings->R = true;
	settings->width = ft_atoi(elements[1]);
	settings->height = ft_atoi(elements[2]);
	if (settings->width <= 0 || settings->height <= 0)
		return (0);
	return (1);
}

void	resolution(char *line, cub_settings *settings)
{
	char **elements;

	if (settings->R == true)
		dprintf(1, "R already true\n");
	//	abort_prog(line, settings, "Identifiers should be used only once");
	elements = ft_split(line, ' ');
	if (!(check_elements(elements, settings)))
		dprintf(1, "Error\n");
	//	abort_prog(line, settings, "Resolution line not well formated. Usage :\
	//			\nR <width> <height>\nOnly positive values");
}


int main()
{
	char *line = "  Rgiuyg  50  20     ";
	cub_settings *settings;
//	settings = NULL;
	ft_bzero(settings, sizeof(cub_settings));
	settings->R = false;
	settings->width = 0;
	settings->height = 0;
	resolution(line, settings);
	dprintf(1, "R = %d\n", settings->R);
	dprintf(1, "width = %d\n", settings->width);
	dprintf(1, "height = %d\n", settings->height);
}
