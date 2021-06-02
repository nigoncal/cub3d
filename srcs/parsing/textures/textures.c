/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:49:51 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/27 13:29:04 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

void	textures(char *line, t_setup *setup)
{
	if (*line == 'N')
		north_texture(line, setup);
	if (*line == 'S')
		south_texture(line, setup);
	if (*line == 'E')
		east_texture(line, setup);
	if (*line == 'W')
		west_texture(line, setup);
}
