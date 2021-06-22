/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:14:12 by nigoncal          #+#    #+#             */
/*   Updated: 2021/06/22 10:23:56 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calc_step_x(t_setup *setup)
{
	if (setup->game.raydir_x < 0)
	{
		setup->game.step_x = -1;
		setup->game.sidedist_x = (setup->game.pos_x - setup->game.map_x) \
		* setup->game.deltadist_x;
	}
	else
	{
		setup->game.step_x = 1;
		setup->game.sidedist_x = (setup->game.map_x + 1.0 - setup->game.pos_x) \
		* setup->game.deltadist_x;
	}
}

void	calc_step_y(t_setup *setup)
{
	if (setup->game.raydir_y < 0)
	{
		setup->game.step_y = -1;
		setup->game.sidedist_y = (setup->game.pos_y - \
		setup->game.map_y) * setup->game.deltadist_y;
	}
	else
	{
		setup->game.step_y = 1;
		setup->game.sidedist_y = (setup->game.map_y + 1.0 \
		- setup->game.pos_y) * setup->game.deltadist_y;
	}
}