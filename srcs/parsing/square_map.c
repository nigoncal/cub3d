/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:18:02 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/24 18:52:17 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

static void	fill_line(t_setup *setup)
{
	int	y_new;
	int	x_new;
	int	y_old;
	int	x_old;

	y_old = 0;
	x_old = 0;
	y_new = 1;
	x_new = 1;

	while (y_new < setup->map_y_size + 1)
	{
		setup->squared_map[y_new][0] = ' ';
		while (setup->map[y_old][x_old])
			setup->squared_map[y_new][x_new++] = setup->map[y_old][x_old++];
		setup->squared_map[y_new][x_new] = ' ';
		setup->squared_map[y_new][x_new + 1] = '\0';
		x_new = 1;
		x_old = 0;
	y_old++;
	y_new++;
	}
}

static void	margin(t_setup *setup)
{
	int	x;

	x = 0;
	while (x < setup->map_x_size + 2)
		setup->squared_map[0][x++] = ' ';
	setup->squared_map[0][x] = '\0';
	x = 0;
	while (x < setup->map_x_size + 2)
		setup->squared_map[setup->map_y_size + 1][x++] = ' ';
	setup->squared_map[setup->map_y_size + 1][x] = '\0';
	setup->squared_map[setup->map_y_size + 2] = 0;
}

static void	size_map(t_setup *setup)
{
	setup->map_y_size = count_lines(setup->map);
	setup->map_x_size = longest_line(setup->map);
}

int	square_map(t_setup *setup)
{
	int		y;

	y = 0;
	size_map(setup);
	setup->squared_map = wrmalloc(sizeof(char *) * (setup->map_y_size + 3));
	if (setup->squared_map == NULL)
		return (-1);
	while (y < setup->map_y_size + 2)
	{
		setup->squared_map[y] = wrmalloc(sizeof(char) * (setup->map_x_size + 3));
		if (setup->squared_map[y] == NULL)
			return (-1);
		y++;
	}
	margin(setup);
	fill_line(setup);
	free_char_p2p(setup->map); // attention a ca
	setup->map = setup->squared_map;
	return (0);
}
