/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:36:22 by nigoncal          #+#    #+#             */
/*   Updated: 2021/06/08 12:44:46 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include"../../../includes/cub3d.h"

void	dda(t_setup *setup)
{
		while (setup->game.hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (setup->game.sidedist_x < setup->game.sidedist_y)
			{
				setup->game.sidedist_x += setup->game.deltadist_x;
				setup->game.map_x += setup->game.step_x;
				setup->game.side = 0;
			}
			else
			{
				setup->game.sidedist_y += setup->game.deltadist_y;
				setup->game.map_y += setup->game.step_y;
				setup->game.side = 1;
			}
			//Check in map if ray has setup->game.hit a wall
			if (setup->map[setup->game.map_y][setup->game.map_x] != 'V')
				setup->game.hit = 1;
		}
}