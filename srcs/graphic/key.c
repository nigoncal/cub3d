/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:18:43 by nigoncal          #+#    #+#             */
/*   Updated: 2021/06/22 10:25:23 by nigoncal         ###   ########lyon.fr   */
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
