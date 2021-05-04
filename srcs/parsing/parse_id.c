/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:20:23 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/04 17:20:26 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

void	parse_id(char *line, t_settings *cub_sets)
{
	line = change_char(line, ' ', '\t'); // line est malloc a la base ? change_char ft_strdup une nouvelle ligne. Quid de l'adresse de line ? ecrasee ? faut-il free les deux ? check les leaks
	line = change_char(line, ' ', '\v'); // pareil
	while (*line)
	{
		while (*line == ' ')
			line++;
		if (*line == 'R')
			p_resolution(line, cub_sets);
		else if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
			p_textures(line, cub_sets);
		// tu en es la
	//	else if (*line == 'F' || *line == 'C')
	//		p_colors(line, cub_sets);
		else
			abort_prog(line, cub_sets, "Ids allowed : R/NO/SO/WE/EA/S/F/C");
	}
}
