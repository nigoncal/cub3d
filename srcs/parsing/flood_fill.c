/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:44:40 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/24 11:15:56 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

void	flood_fill_floor(char **map, int y, int x, t_setup *setup)
{
	char src;
	char dst;

	src = '0';
	dst = 'V';
	if (map[y][x] == ' ')
		abort_prog("M");
	if (map[y][x] == src && (x == 0	|| x == setup->map_x_size || y == 0
		|| y == setup->map_y_size))
		abort_prog("M");
	if (map[y][x] == src || bool_strchr("NSEW", map[y][x]) != -1)
	{
		map[y][x] = dst;
		flood_fill_floor(map, y - 1, x, setup);
		flood_fill_floor(map, y, x + 1, setup);
		flood_fill_floor(map, y + 1, x, setup);
		flood_fill_floor(map, y, x - 1, setup);
	}
}
