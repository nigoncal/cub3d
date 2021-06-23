/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <milletp.pro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 08:14:00 by pmillet           #+#    #+#             */
/*   Updated: 2021/06/23 08:14:03 by pmillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(t_setup *setup)
{
	draw_forward_back(setup);
	draw_left_right(setup);
	draw_rotate_left(setup);
	draw_rotate_right(setup);
	return (0);
}

void	alloc_storage(t_setup *setup)
{
	int		j;
	int		i;

	i = 0;
	setup->game.texture = wrmalloc(sizeof(int *) * 4);
	if (setup->game.texture == NULL)
		abort_prog("erreur malloc");
	while (i < 4)
	{
		setup->game.texture[i] = (int *)wrmalloc(sizeof(int) * (64 * 64));
		if (setup->game.texture[i] == NULL)
			abort_prog("erreur malloc");
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 64 * 64)
		{
			setup->game.texture[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	exit_skip(void)
{
	exit(0);
	return (0);
}
