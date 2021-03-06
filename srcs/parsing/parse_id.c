/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:20:23 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/28 10:39:24 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

void	parse_id(char *line, t_setup *setup)
{
	line = change_char(line, ' ', '\t');
	line = change_char(line, ' ', '\v');
	while (*line == ' ')
		line++;
	if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
		p_textures(line, setup);
	else if (*line == 'F')
		p_floor(line, setup);
	else if (*line == 'C')
		p_ceiling(line, setup);
	else if (*line == '\0')
		return ;
	else
		abort_prog("Identifiers allowed and mandatory : NO,SO,WE,EA,S,F,C");
}
