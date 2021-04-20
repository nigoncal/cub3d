/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:11:38 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/05 11:41:16 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3D.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h> // a virer

// faire tous les checkings d'erreur

void	resolution(char *line, t_setup *settings)
{
	while (line++)
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
	}
}
