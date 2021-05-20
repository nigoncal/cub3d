/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:04:18 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/20 14:31:47 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

void	store_player(int y, int x, char temp, t_setup *setup)
{

	setup->player_dir = temp;
}

void	find_player(t_setup *setup)
{
	int		y;
	int		x;
	char	temp;
	
	y = 0;
	x = 0;
	temp = 0;
	while (setup->map[y])
	{
		while (setup->map[y][x])
		{
			temp = *ft_strchr("NSEW", (int)setup->map[y][x]);
			if (temp)
			{
				if (setup->player_dir)
					abort_prog("You're map can't have more than one player");
				else
					store_player(y, x, temp, setup);
			}
			x++;
		}
	y++;
	}
	if (setup->player_dir == 0)
		abort_prog("No player found on the map")
}
