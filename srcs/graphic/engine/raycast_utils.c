/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:36:22 by nigoncal          #+#    #+#             */
/*   Updated: 2021/06/13 12:40:57 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include"../../../includes/cub3d.h"

void	dda(t_info *info)
{
		while (info->game.hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (info->game.sidedist_x < info->game.sidedist_y)
			{
				info->game.sidedist_x += info->game.deltadist_x;
				info->game.map_x += info->game.step_x;
				info->game.side = 0;
			}
			else
			{
				info->game.sidedist_y += info->game.deltadist_y;
				info->game.map_y += info->game.step_y;
				info->game.side = 1;
			}
			//Check in map if ray has info->game.hit a wall
			if (info->map[info->game.map_y][info->game.map_x] != 'V')
				info->game.hit = 1;
		}
}