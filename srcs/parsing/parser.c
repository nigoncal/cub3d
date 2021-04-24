/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:06:21 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/24 15:50:00 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"
#include "../libft/header_libft.h"
#include "../get_next_line/get_next_line.h"
#include <stdio.h> // a virer

void	parse_map(char *line, t_settings *cub_sets)
{
	if ((is_map(line, cub_sets)) == -1)
		return (-1);
	store_map(line, cub_sets);
}

void	parse_id(char *line, t_settings *cub_sets)
{
	line = change_char(line, ' ', '\t'); // line est malloc a la base ? change_char ft_strdup une nouvelle ligne. Quid de l'adresse de line ? ecrasee ? faut-il free les deux ? check les leaks
	line = change_char(line, ' ', '\v'); // pareil
	while (line)
	{
		while (line == ' ') // test depuis l'ajout du \t surtout le ||, plutot que le &&
			line++;
		if (line == 'R')
			resolution(line, cub_sets);
		if (line == 'N' || line == 'S' || line == 'E' || line == 'W')
			texture(line, cub_sets);
		// tu en es la
		if (line == 'F' || line == 'C')
			color(line, cub_sets);
		else
			abort_all(line, cub_sets, "Identifiers allowed : R, NO, SO, WE, EA, S, F, C");
	}
}
