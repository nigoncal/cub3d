/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 09:47:48 by nigoncal          #+#    #+#             */
/*   Updated: 2021/06/22 10:49:57 by nigoncal         ###   ########lyon.fr   */
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

int	alloc_storage(t_setup *setup)
{
	int		j;
	int		i;

	i = 0;
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
	return (1);
}

int	exit_skip(void)
{
	exit(0);
	return (0);
}
