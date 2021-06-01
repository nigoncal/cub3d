/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:44:40 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/27 09:38:56 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	flood_fill(char **map, int y, int x, t_setup *setup)
{
	if (map[y][x] == ' ')
		abort_prog("M");
	if ((map[y][x] == '2' && (x != 0 || x != setup->map_xsize
			|| y != 0 || y != setup->map_ysize)))
	{
		map[y][x] = 'X';
		flood_fill(map, y - 1, x, setup);
		flood_fill(map, y, x + 1, setup);
		flood_fill(map, y + 1, x, setup);
		flood_fill(map, y, x - 1, setup);
	}
	if ((map[y][x] == '0' || bool_strchr("NSEW", map[y][x]) != -1)
		&& (x != 0 || x != setup->map_xsize
		|| y != 0 || y != setup->map_ysize))
	{
		map[y][x] = 'V';
		flood_fill(map, y - 1, x, setup);
		flood_fill(map, y, x + 1, setup);
		flood_fill(map, y + 1, x, setup);
		flood_fill(map, y, x - 1, setup);
	}
}
