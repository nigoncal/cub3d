/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:44:40 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/22 13:17:58 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

void	flood_fill(char **map, int y, int x, char src, char dst)
{
	if (map[y][x] == ' ')
		abort_prog("M");
	if (map[y][x] == src)
	{
		map[y][x] = dst;
		flood_fill(map, y - 1, x, src, dst);
		flood_fill(map, y, x + 1, src, dst);
		flood_fill(map, y + 1, x + 1, src, dst);
		flood_fill(map, y, x - 1, src, dst);
	}
}
