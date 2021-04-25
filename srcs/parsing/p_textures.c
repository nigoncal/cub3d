/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 09:01:58 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/25 14:34:49 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

void		p_textures(char *line, t_settings *cub_sets)
{
	if (*line == 'N')
		if ((p_north_texture(line, cub_sets)) == -1)
			abort_prog(line, cub_sets, "North line : NO ./path.xpm OR .png");
	if (*line == 'S' && *line + 1 == 'O')
		if ((p_south_texture(line, cub_sets)) == -1)
			abort_prog(line, cub_sets, "South line : SO ./path.xpm OR .png");
	if (*line == 'E')
		if ((p_east_texture(line, cub_sets)) == -1)
			abort_prog(line, cub_sets, "East line : EA ./path.xpm OR .png");
	if (*line == 'W')
		if ((p_west_texture(line, cub_sets)) == -1)
			abort_prog(line, cub_sets, "West line : WE ./path.xpm OR .png");
	if (*line == 'S')
		if ((p_sprite_texture(line, cub_sets)) == -1)
			abort_prog(line, cub_sets, "Sprite line : S ./path.xpm OR .png");
}
