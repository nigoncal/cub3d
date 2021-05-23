/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:44:40 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/23 18:03:15 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

void	flood_fill(char **map, int y, int x)
{
	char src;
	char dst;

	src = '0';
	dst = 'O';
	if (map[y][x] == ' ')
		abort_prog("M");
	if (map[y][x + 1] == src && map[y][x] != '1')
	{
		map[y][x + 1] = dst;
		flood_fill(map, y - 1, x);
		flood_fill(map, y, x + 1);
		flood_fill(map, y + 1, x);
		flood_fill(map, y, x - 1);
	}
}
