/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:46:42 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/13 11:11:13 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	store_dir_xy(t_info *info)
{
	/* TESTED :
	WEST = 
	dir_x = |-1.000000|
	dir_y = |0.000000|*/
	// OLD :
	/*if (info->player_dir == 'N') // OUEST
		info->game.dir_x = -1;
	if (info->player_dir == 'S') // EST
		info->game.dir_x = 1;
	if (info->player_dir == 'E') // NORD
		info->game.dir_y = 1;
	if (info->player_dir == 'W') // SUD
		info->game.dir_y = -1;*/
	if (info->player_dir == 'N')
	{
		info->game.dir_y = 1;
		info->game.planeX = 0.66;
	}
	if (info->player_dir == 'S')
	{
		info->game.dir_y = 1;
	}
	if (info->player_dir == 'E')
		info->game.dir_x = -1;
	if (info->player_dir == 'W')
		info->game.dir_x = 1;
}

static void	store_player(int y, int x, t_info *info)
{
	if (info->player_dir)
		abort_prog("You can't have more than one player on the map");
	else
	{
		info->player_dir = info->map[y][x];
		info->x = x;
		info->y = y;
		info->game.pos_x = (float)x + 0.5;
		info->game.pos_y = (float)y + 0.5;
		store_dir_xy(info);
	}
}

void	find_player(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (info->map[y])
	{
		while (info->map[y][x])
		{
			if (bool_strchr("NSEW", info->map[y][x]) != -1)
				store_player(y, x, info);
			x++;
		}
		y++;
		x = 0;
	}
	if (info->player_dir == 0)
		abort_prog("No player found on the map");
	flood_fill(info->map, info->y, info->x, info);
}
