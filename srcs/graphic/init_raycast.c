/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:33:47 by nigoncal          #+#    #+#             */
/*   Updated: 2021/06/20 15:34:25 by nigoncal         ###   ########lyon.fr   */
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
