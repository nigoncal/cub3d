/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <milletp.pro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 08:13:45 by pmillet           #+#    #+#             */
/*   Updated: 2021/06/23 08:13:48 by pmillet          ###   ########.fr       */
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
