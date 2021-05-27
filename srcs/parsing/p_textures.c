/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_textures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:49:51 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/27 13:29:04 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

void	p_textures(char *line, t_setup *setup)
{
	if (*line == 'N')
		p_north_texture(line, setup);
	if (*line == 'S')
		p_south_texture(line, setup);
	if (*line == 'E')
		p_east_texture(line, setup);
	if (*line == 'W')
		p_west_texture(line, setup);
}
