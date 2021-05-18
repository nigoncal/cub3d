/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_textures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:49:51 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/18 17:11:54 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

void		p_textures(char *line, t_settings *cub_sets)
{
	if (*line == 'N')
		p_north_texture(line, cub_sets);
	if (*line == 'S')
	{
		if (*line == 'S' && *(line + 1) == 'O')
			p_south_texture(line, cub_sets);
		else
			p_sprite_texture(line, cub_sets);
	}
	if (*line == 'E')
		p_east_texture(line, cub_sets);
	if (*line == 'W')
		p_west_texture(line, cub_sets);
}
