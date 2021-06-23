/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <milletp.pro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 08:12:23 by pmillet           #+#    #+#             */
/*   Updated: 2021/06/23 08:12:26 by pmillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ray_dir(t_setup *setup)
{
	setup->game.camera_x = 2 * setup->x / (double)setup->width - 1;
	setup->game.raydir_x = setup->game.dir_x + setup->game.plane_x \
	* setup->game.camera_x;
	setup->game.raydir_y = setup->game.dir_y + setup->game.plane_y \
	* setup->game.camera_x;
}

void	detect_case(t_setup *setup)
{
	setup->game.map_x = (int)setup->game.pos_x;
	setup->game.map_y = (int)setup->game.pos_y;
}

void	ray_len(t_setup *setup)
{
	setup->game.deltadist_x = fabs(1 / setup->game.raydir_x);
	setup->game.deltadist_y = fabs(1 / setup->game.raydir_y);
	setup->game.hit = 0;
}
