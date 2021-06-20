/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:17:30 by nigoncal          #+#    #+#             */
/*   Updated: 2021/06/20 12:26:22 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    dda_algo(t_setup *setup)
{
		while (setup->game.hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (setup->game.sidedist_x <= setup->game.sidedist_y)
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
			if (setup->map[setup->game.map_y][setup->game.map_x] == '1')
				setup->game.hit = 1;
        }
}

void    fisheye(t_setup *setup)
{
    	if (setup->game.side == 0)
			setup->game.perpwalldist = (setup->game.map_x - setup->game.pos_x + (1 - setup->game.step_x) / 2) / setup->game.raydir_x;
		else
			setup->game.perpwalldist = (setup->game.map_y - setup->game.pos_y + (1 - setup->game.step_y) / 2) / setup->game.raydir_y;
}

void    height_wall(t_setup *setup)
{
		setup->game.lineheight = (int)(setup->height / setup->game.perpwalldist);
}

void    fill_stripe(t_setup *setup)
{
    	    setup->game.drawstart = -setup->game.lineheight / 2 + setup->height / 2;
		if (setup->game.drawstart < 0)
			setup->game.drawstart = 0;
		 setup->game.drawend = setup->game.lineheight / 2 + setup->height / 2;
		if (setup->game.drawend >= setup->height || setup->game.drawend < 0)
			setup->game.drawend = setup->height - 1;
}
