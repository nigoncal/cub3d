/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:47:23 by sylducam          #+#    #+#             */
/*   Updated: 2021/03/22 14:54:56 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "cub3D.h"

// need wrong paths errors

int		check_cub(map_settings *settings)
{
	if (settings->width < 1 || settings->height < 1)
	{
		write(1, "Error\nWrong resolution\n", 23);
		return (-1)
	}
	if (settings->north_texture_path == 0)
	{
		write(1, "Error\nNorth texture path missing\n", 33);
		return (-1)
	}
	if (settings->south_texture_path == 0)
	{
		write(1, "Error\nSouth texture path missing\n", 33);
		return (-1)
	}
	if (settings->west_texture_path == 0)
	{
		write(1, "Error\nWest texture path missing\n", 32);
		return (-1)
	}
	if (settings->east_texture_path == 0)
	{
		write(1, "Error\nEast texture path missing\n", 32);
		return (-1)
	}
	if (settings->sprite_texture_path == 0)
	{
		write(1, "Error\nSprite texture path missing\n", 35);
		return (-1)
	}
	return (0);
}
