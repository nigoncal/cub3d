/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:20:23 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/18 17:17:15 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

void	parse_id(char *line, t_settings *cub_sets)
{
	line = change_char(line, ' ', '\t');
	line = change_char(line, ' ', '\v');
	while (*line == ' ')
		line++;
	if (*line == 'R')
		p_resolution(line, cub_sets);
	else if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
		p_textures(line, cub_sets);
	else if (*line == 'F')
		p_floor(line, cub_sets);
	else if (*line == 'C')
		p_ceiling(line, cub_sets);
	else if (*line == '\0')
		return ;
	else
		abort_prog("Identifiers allowed and mandatory : R,NO,SO,WE,EA,S,F,C");
}
