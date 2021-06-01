/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:58:38 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/31 14:44:17 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

static void	xpm_texture_address(t_setup *setup)
{
	if (setup->north_format == 2)
		setup->game.texture[0].addr = \
		mlx_get_data_addr(setup->game.texture[0].img, \
		&setup->game.texture[0].bits_per_pixel, \
		&setup->game.texture[0].line_length, &setup->game.texture[0].endian);
	if (setup->south_format == 2)
		setup->game.texture[1].addr = \
		mlx_get_data_addr(setup->game.texture[1].img, \
		&setup->game.texture[1].bits_per_pixel, \
		&setup->game.texture[1].line_length, &setup->game.texture[1].endian);
	if (setup->east_format == 2)
		setup->game.texture[2].addr = \
		mlx_get_data_addr(setup->game.texture[2].img, \
		&setup->game.texture[2].bits_per_pixel, \
		&setup->game.texture[2].line_length, &setup->game.texture[2].endian);
	if (setup->west_format == 2)
		setup->game.texture[3].addr = \
		mlx_get_data_addr(setup->game.texture[3].img, \
		&setup->game.texture[3].bits_per_pixel, \
		&setup->game.texture[3].line_length, &setup->game.texture[3].endian);
}

static void	png_texture_address(t_setup *setup)
{
	if (setup->north_format == 1)
		setup->game.texture[0].addr = \
		mlx_get_data_addr(setup->game.texture[0].img, \
		&setup->game.texture[0].bits_per_pixel, \
		&setup->game.texture[0].line_length, &setup->game.texture[0].endian);
	if (setup->south_format == 1)
		setup->game.texture[1].addr = \
		mlx_get_data_addr(setup->game.texture[1].img, \
		&setup->game.texture[1].bits_per_pixel, \
		&setup->game.texture[1].line_length, &setup->game.texture[1].endian);
	if (setup->east_format == 1)
		setup->game.texture[2].addr = \
		mlx_get_data_addr(setup->game.texture[2].img, \
		&setup->game.texture[2].bits_per_pixel, \
		&setup->game.texture[2].line_length, &setup->game.texture[2].endian);
	if (setup->west_format == 1)
		setup->game.texture[3].addr = \
		mlx_get_data_addr(setup->game.texture[3].img, \
		&setup->game.texture[3].bits_per_pixel, \
		&setup->game.texture[3].line_length, &setup->game.texture[3].endian);
}

static void	xpm_texture(t_setup *setup)
{
	if (setup->north_format == 2)
		setup->game.texture[0].img = mlx_xpm_file_to_image(setup->mlx, \
		setup->north_texture_path, &setup->game.texture[0].width, \
		&setup->game.texture[0].height);
	if (setup->south_format == 2)
		setup->game.texture[1].img = mlx_xpm_file_to_image(setup->mlx, \
		setup->south_texture_path, &setup->game.texture[1].width, \
		&setup->game.texture[1].height);
	if (setup->east_format == 2)
		setup->game.texture[2].img = mlx_xpm_file_to_image(setup->mlx, \
		setup->east_texture_path, &setup->game.texture[2].width, \
		&setup->game.texture[2].height);
	if (setup->west_format == 2)
		setup->game.texture[3].img = mlx_xpm_file_to_image(setup->mlx, \
		setup->west_texture_path, &setup->game.texture[3].width, \
		&setup->game.texture[3].height);
}

static void	png_texture(t_setup *setup)
{
	if (setup->north_format == 1)
		setup->game.texture[0].img = mlx_png_file_to_image(setup->mlx, \
		setup->north_texture_path, &setup->game.texture[0].width, \
		&setup->game.texture[0].height); // ici une erreur
	if (setup->south_format == 1)
		setup->game.texture[1].img = mlx_png_file_to_image(setup->mlx, \
		setup->south_texture_path, &setup->game.texture[1].width, \
		&setup->game.texture[1].height);
	if (setup->east_format == 1)
		setup->game.texture[2].img = mlx_png_file_to_image(setup->mlx, \
		setup->east_texture_path, &setup->game.texture[2].width, \
		&setup->game.texture[2].height);
	if (setup->west_format == 1)
		setup->game.texture[3].img = mlx_png_file_to_image(setup->mlx, \
		setup->west_texture_path, &setup->game.texture[3].width, \
		&setup->game.texture[3].height);
}

void	graph_textures(t_setup *setup)
{
	png_texture(setup);
	xpm_texture(setup);
	png_texture_address(setup);
	xpm_texture_address(setup);
}
