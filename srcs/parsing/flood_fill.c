/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:44:40 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/22 19:14:22 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

void	flood_fill(t_setup *setup, char pixel, char src, char dst)
{
	if (pixel == ' ')
		abort_prog("M");
	if (pixel == src)
	{
		pixel = dst;
		flood_fill(setup y - 1, x, src, dst);
		flood_fill(map, y, x + 1, src, dst);
		flood_fill(map, y + 1, x + 1, src, dst);
		flood_fill(map, y, x - 1, src, dst);
	}
}
