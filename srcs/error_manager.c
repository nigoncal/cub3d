/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:46:12 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/26 14:44:59 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"

// penses a free elements aussi, dans le parsing des textures (free_char_p2p)
// > free le juste avant d'appeler abort_prog

void	map_error(void)
{
	ft_putstr("An error was spotted in your map\nRules of the map :\n");
	ft_putstr("The only characters allowed are 0 for the floor, ");
	ft_putstr("1 for the walls, 2 for the sprites, N/S/E/W for the player ");
	ft_putstr("according to it's orientation and spaces.\n");
	ft_putstr("The map has to be closed by walls and space characters are ");
	ft_putstr("only allowed outside the map to shape it to your will.\n");
}

void	abort_prog(char *error_msg)
{
	ft_putstr("Error\n");
	if (*error_msg == 'M')
		map_error();
	else
		ft_putstr(error_msg);
	write (1, "\n", 1);
	wrdestroy();
	exit(1);
}
