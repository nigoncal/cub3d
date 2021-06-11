/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:58:38 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/31 16:41:34 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*static void	xpm_texture_address(t_info *info)
{
	if (info->north_format == 2)
		info->game.texture[0].addr = \
		mlx_get_data_addr(info->game.texture[0].img, \
		&info->game.texture[0].bits_per_pixel, \
		&info->game.texture[0].line_length, &info->game.texture[0].endian);
	if (info->south_format == 2)
		info->game.texture[1].addr = \
		mlx_get_data_addr(info->game.texture[1].img, \
		&info->game.texture[1].bits_per_pixel, \
		&info->game.texture[1].line_length, &info->game.texture[1].endian);
	if (info->east_format == 2)
		info->game.texture[2].addr = \
		mlx_get_data_addr(info->game.texture[2].img, \
		&info->game.texture[2].bits_per_pixel, \
		&info->game.texture[2].line_length, &info->game.texture[2].endian);
	if (info->west_format == 2)
		info->game.texture[3].addr = \
		mlx_get_data_addr(info->game.texture[3].img, \
		&info->game.texture[3].bits_per_pixel, \
		&info->game.texture[3].line_length, &info->game.texture[3].endian);
}

static void	png_texture_address(t_info *info)
{
	if (info->north_format == 1)
		info->game.texture[0].addr = \
		mlx_get_data_addr(info->game.texture[0].img, \
		&info->game.texture[0].bits_per_pixel, \
		&info->game.texture[0].line_length, &info->game.texture[0].endian);
	if (info->south_format == 1)
		info->game.texture[1].addr = \
		mlx_get_data_addr(info->game.texture[1].img, \
		&info->game.texture[1].bits_per_pixel, \
		&info->game.texture[1].line_length, &info->game.texture[1].endian);
	if (info->east_format == 1)
		info->game.texture[2].addr = \
		mlx_get_data_addr(info->game.texture[2].img, \
		&info->game.texture[2].bits_per_pixel, \
		&info->game.texture[2].line_length, &info->game.texture[2].endian);
	if (info->west_format == 1)
		info->game.texture[3].addr = \
		mlx_get_data_addr(info->game.texture[3].img, \
		&info->game.texture[3].bits_per_pixel, \
		&info->game.texture[3].line_length, &info->game.texture[3].endian);
}

static void	xpm_texture(t_info *info)
{
	if (info->north_format == 2)
		info->game.texture[0].img = mlx_xpm_file_to_image(info->mlx, \
		info->north_texture_path, &info->game.texture[0].width, \
		&info->game.texture[0].height);
	if (info->south_format == 2)
		info->game.texture[1].img = mlx_xpm_file_to_image(info->mlx, \
		info->south_texture_path, &info->game.texture[1].width, \
		&info->game.texture[1].height);
	if (info->east_format == 2)
		info->game.texture[2].img = mlx_xpm_file_to_image(info->mlx, \
		info->east_texture_path, &info->game.texture[2].width, \
		&info->game.texture[2].height);
	if (info->west_format == 2)
		info->game.texture[3].img = mlx_xpm_file_to_image(info->mlx, \
		info->west_texture_path, &info->game.texture[3].width, \
		&info->game.texture[3].height);
}

static void	png_texture(t_info *info)
{
	if (info->north_format == 1)
		info->game.texture[0].img = mlx_png_file_to_image(info->mlx, \
		info->north_texture_path, &info->game.texture[0].width, \
		&info->game.texture[0].height);
	if (info->south_format == 1)
		info->game.texture[1].img = mlx_png_file_to_image(info->mlx, \
		info->south_texture_path, &info->game.texture[1].width, \
		&info->game.texture[1].height);
	if (info->east_format == 1)
		info->game.texture[2].img = mlx_png_file_to_image(info->mlx, \
		info->east_texture_path, &info->game.texture[2].width, \
		&info->game.texture[2].height);
	if (info->west_format == 1)
		info->game.texture[3].img = mlx_png_file_to_image(info->mlx, \
		info->west_texture_path, &info->game.texture[3].width, \
		&info->game.texture[3].height);
}*/

void	graph_textures(t_info *info)
{
	(void)info;
	/*png_texture(info);
	xpm_texture(info);
	png_texture_address(info);
	xpm_texture_address(info);*/
}
