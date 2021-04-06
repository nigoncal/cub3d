/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:11:38 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/06 18:11:37 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3D.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h> // a virer

// faire tous les checkings d'erreur

int		check_elements(char **elements)
{
// 1 - est-ce le bon bombre ?
// 2 - Sont-ce les bons ?
// 3 - Si oui on remplit la struct 
}

void	resolution(char *line, map_settings *settings)
{
	char **elements;

	if (settings->R == true)
		abort_all(line, settings, "Identifiers should be used only once");
	elements = ft_split(line, ' ');
	check_elements(elements);
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
