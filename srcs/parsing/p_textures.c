/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_textures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:49:51 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/15 14:51:24 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

void		p_textures(char *line, t_settings *cub_sets)
{
	if (*line == 'N')
		if ((p_north_texture(line, cub_sets)) == -1)
			abort_prog("NO ./path.xpm OR .png\nOnly one line like this");
	if (*line == 'S')
	{
		if (*line == 'S' && *(line + 1) == 'O')
		{
			if ((p_south_texture(line, cub_sets)) == -1)
				abort_prog("SO ./path.xpm OR .png\nOnly one line like this");
		}
		else
			if ((p_sprite_texture(line, cub_sets)) == -1)
				abort_prog("S ./path.xpm OR .png\nOnly one line like this");
	}
	if (*line == 'E')
		if ((p_east_texture(line, cub_sets)) == -1)
			abort_prog("EA ./path.xpm OR .png\nOnly one line like this");
	if (*line == 'W')
		if ((p_west_texture(line, cub_sets)) == -1)
			abort_prog("WE ./path.xpm OR .png\nOnly one line like this");
}
