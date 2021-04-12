/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:47:23 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/07 09:58:08 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "../cub3D.h"

// need wrong paths errors

int		check_cub(t_setup *settings)
{
	if (settings->width < 1 || settings->height < 1)
	{
		write(1, "Error\nWrong resolution\n", 23);
		return (-1);
	}
	if (settings->north_texture_path == 0)
	{
		write(1, "Error\nNorth texture path missing\n", 33);
		return (-1);
	}
	if (settings->south_texture_path == 0)
	{
		write(1, "Error\nSouth texture path missing\n", 33);
		return (-1);
	}
	if (settings->west_texture_path == 0)
	{
		write(1, "Error\nWest texture path missing\n", 32);
		return (-1);
	}
	if (settings->east_texture_path == 0)
	{
		write(1, "Error\nEast texture path missing\n", 32);
		return (-1);
	}
	if (settings->sprite_texture_path == 0)
	{
		write(1, "Error\nSprite texture path missing\n", 35);
		return (-1);
	}
	return (0);
}
