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

void	flood_fill(char **map, int y, int x, t_info *info)
{
	if (map[y][x] == ' ')
		abort_prog("M");
	if ((map[y][x] == '2' && (x != 0 || x != info->map_xsize
			|| y != 0 || y != info->map_ysize)))
	{
		map[y][x] = 'X';
		flood_fill(map, y - 1, x, info);
		flood_fill(map, y, x + 1, info);
		flood_fill(map, y + 1, x, info);
		flood_fill(map, y, x - 1, info);
	}
	if ((map[y][x] == '0' || bool_strchr("NSEW", map[y][x]) != -1)
		&& (x != 0 || x != info->map_xsize
		|| y != 0 || y != info->map_ysize))
	{
		map[y][x] = 'V';
		flood_fill(map, y - 1, x, info);
		flood_fill(map, y, x + 1, info);
		flood_fill(map, y + 1, x, info);
		flood_fill(map, y, x - 1, info);
	}
}
