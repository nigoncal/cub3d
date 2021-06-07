/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:18:02 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/27 10:07:10 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	fill_line(t_info *info)
{
	int	y_new;
	int	x_new;
	int	y_old;
	int	x_old;

	y_old = 0;
	x_old = 0;
	y_new = 1;
	x_new = 1;
	while (y_new < info->map_ysize + 1)
	{
		info->squared_map[y_new][0] = ' ';
		while (info->map[y_old][x_old])
			info->squared_map[y_new][x_new++] = info->map[y_old][x_old++];
		info->squared_map[y_new][x_new] = ' ';
		info->squared_map[y_new][x_new + 1] = '\0';
		x_new = 1;
		x_old = 0;
		y_old++;
		y_new++;
	}
}

static void	margin(t_info *info)
{
	int	x;

	x = 0;
	while (x < info->map_xsize + 2)
		info->squared_map[0][x++] = ' ';
	info->squared_map[0][x] = '\0';
	x = 0;
	while (x < info->map_xsize + 2)
		info->squared_map[info->map_ysize + 1][x++] = ' ';
	info->squared_map[info->map_ysize + 1][x] = '\0';
	info->squared_map[info->map_ysize + 2] = 0;
}

static void	size_map(t_info *info)
{
	info->map_ysize = count_lines(info->map);
	info->map_xsize = longest_line(info->map);
}

void	square_map(t_info *info)
{
	int		y;

	y = 0;
	size_map(info);
	info->squared_map = wrmalloc(sizeof(char *) * (info->map_ysize + 3));
	if (info->squared_map == NULL)
		abort_prog("Failed to malloc info->map");
	while (y < info->map_ysize + 2)
	{
		info->squared_map[y] = wrmalloc(sizeof(char) * (info->map_xsize + 3));
		if (info->squared_map[y] == NULL)
			abort_prog("Failed to malloc info->map");
		y++;
	}
	margin(info);
	fill_line(info);
	info->map = info->squared_map;
}
