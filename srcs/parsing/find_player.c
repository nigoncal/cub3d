/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:46:42 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/27 09:38:28 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	store_dir_xy(t_info *info)
{
	if (info->player_dir == 'N')
		info->game.dir_y = 0.66;
	if (info->player_dir == 'S')
		info->game.dir_y = -0.66;
	if (info->player_dir == 'E')
		info->game.dir_x = 0.66;
	if (info->player_dir == 'W')
		info->game.dir_x = -0.66;
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
	//	char **temp = info->map;
	//flood_fill(temp, info->y, info->x, info);
}
