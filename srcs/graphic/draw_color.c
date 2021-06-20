/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:58:14 by nigoncal          #+#    #+#             */
/*   Updated: 2021/06/20 17:49:05 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_celling_floor(t_setup *setup)
{
	int	i;

	i = 0;
	while (i < setup->game.drawstart)
	{
		setup->game.buf[i][setup->x] = setup->game.c_color.color;
		i++;
	}
	i = setup->game.drawend;
	while (i < setup->height)
	{
		setup->game.buf[i][setup->x] = setup->game.f_color.color;
		i++;
	}
}
