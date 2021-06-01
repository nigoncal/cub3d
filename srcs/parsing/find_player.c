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

#include "../header_cub3d.h"

static void	store_dir_xy(t_setup *setup)
{
	if (setup->player_dir == 'N')
		setup->game.dir_y = 0.66;
	if (setup->player_dir == 'S')
		setup->game.dir_y = -0.66;
	if (setup->player_dir == 'E')
		setup->game.dir_x = 0.66;
	if (setup->player_dir == 'W')
		setup->game.dir_x = -0.66;
}

static void	store_player(int y, int x, t_setup *setup)
{
	if (setup->player_dir)
		abort_prog("You can't have more than one player on the map");
	else
	{
		setup->player_dir = setup->map[y][x];
		setup->x = x;
		setup->y = y;
		setup->game.pos_x = (float)x + 0.5;
		setup->game.pos_y = (float)y + 0.5;
		store_dir_xy(setup);
	}
}

void	find_player(t_setup *setup)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (setup->map[y])
	{
		while (setup->map[y][x])
		{
			if (bool_strchr("NSEW", setup->map[y][x]) != -1)
				store_player(y, x, setup);
			x++;
		}
		y++;
		x = 0;
	}
	if (setup->player_dir == 0)
		abort_prog("No player found on the map");
	flood_fill(setup->map, setup->y, setup->x, setup);
}
