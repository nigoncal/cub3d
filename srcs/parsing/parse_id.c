/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <milletp.pro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:20:23 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/23 08:19:00 by pmillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_id(char *line, t_setup *setup, int fd)
{
	line = change_char(line, ' ', '\t');
	line = change_char(line, ' ', '\v');
	while (*line == ' ')
		line++;
	if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
		textures(line, setup);
	else if (*line == 'F')
		parse_floor(line, setup);
	else if (*line == 'C')
		ceiling(line, setup);
	else if (*line == '\0')
		return ;
	else
	{
		close(fd);
		abort_prog("Identifiers allowed and mandatory : NO,SO,WE,EA,S,F,C. \
Note that they need to be all BEFORE the map.");
	}
}
