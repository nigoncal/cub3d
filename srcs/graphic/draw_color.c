/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <milletp.pro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:58:14 by nigoncal          #+#    #+#             */
/*   Updated: 2021/06/21 15:59:28 by pmillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_celling_floor(t_setup *setup)
{
	int	i;

	i = 0;
	if (setup->game.drawstart > 0)
	{
		while (i < setup->game.drawstart)
		{
			setup->game.buf[i][setup->x] = setup->game.c_color.color;
			i++;
		}
	}
	i = setup->game.drawend;
	while (i < setup->height - 1)
	{
		setup->game.buf[i][setup->x] = setup->game.f_color.color;
		i++;
	}
}
