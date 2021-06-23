/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <milletp.pro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 08:12:58 by pmillet           #+#    #+#             */
/*   Updated: 2021/06/23 08:13:01 by pmillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press_mouvement(int key, t_setup *setup)
{
	if (key == MOVE_W)
		setup->key.forward = 1;
	if (key == MOVE_S)
		setup->key.back = 1;
	if (key == MOVE_A)
		setup->key.right = 1;
	if (key == MOVE_D)
		setup->key.left = 1;
	if (key == ROTATE_LEFT)
		setup->key.rotate_left = 1;
	if (key == ROTATE_RIGHT)
		setup->key.rotate_right = 1;
	if (key == EXIT_ESC)
	{
		wrdestroy();
		exit(0);
	}
	return (0);
}

int	key_release(int key, t_setup *setup)
{
	if (key == MOVE_W)
		setup->key.forward = 0;
	if (key == MOVE_S)
		setup->key.back = 0;
	if (key == MOVE_A)
		setup->key.right = 0;
	if (key == MOVE_D)
		setup->key.left = 0;
	if (key == ROTATE_LEFT)
		setup->key.rotate_left = 0;
	if (key == ROTATE_RIGHT)
		setup->key.rotate_right = 0;
	return (0);
}
