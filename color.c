/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:13:32 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/05 11:41:20 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h> // a virer

// il te faut passer trois fois dedans avec un tableau d'int, donc i = 0 et tu check si tu n'as pas deja enregistre un C ou un F et si ca passe plus de 3 fois ca veut dire qu'il y a plus que rgb, donc erreur

void	color(char **line, t_settings *cub_sets)
{
	if (*(*line) == 'C')
	{
		cub_sets->ceiling_red = ft_pf_atoi(line);
		cub_sets->ceiling_green = ft_pf_atoi(line);
		cub_sets->ceiling_blue = ft_pf_atoi(line);
	}
	if (*(*line) == 'F')
	{
		cub_sets->floor_red = ft_pf_atoi(line);
		cub_sets->floor_green = ft_pf_atoi(line);
		cub_sets->floor_blue = ft_pf_atoi(line);
	}
}
