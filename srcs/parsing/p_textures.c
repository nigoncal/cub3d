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

#include "../../includes/cub3d.h"

void	p_textures(char *line, t_info *info)
{
	if (*line == 'N')
		p_north_texture(line, info);
	if (*line == 'S')
		p_south_texture(line, info);
	if (*line == 'E')
		p_east_texture(line, info);
	if (*line == 'W')
		p_west_texture(line, info);
}
