/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_textures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:49:51 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/11 14:57:25 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

void		p_textures(char *line, t_settings *cub_sets)
{
	if (*line == 'N')
		if ((p_north_texture(line, cub_sets)) == -1)
			abort_prog(line, cub_sets, "North line : NO ./path.xpm OR .png");
	if (*line == 'S')
	{
		if (*line == 'S' && *(line + 1) == 'O')
		{
			if ((p_south_texture(line, cub_sets)) == -1)
				abort_prog(line, cub_sets, "South line: SO ./path.xpm OR .png");
		}
		else
			if ((p_sprite_texture(line, cub_sets)) == -1)
				abort_prog(line, cub_sets, "Sprite line: S ./path.xpm OR .png");
	}
	if (*line == 'E')
		if ((p_east_texture(line, cub_sets)) == -1)
			abort_prog(line, cub_sets, "East line : EA ./path.xpm OR .png");
	if (*line == 'W')
		if ((p_west_texture(line, cub_sets)) == -1)
			abort_prog(line, cub_sets, "West line : WE ./path.xpm OR .png");
}
