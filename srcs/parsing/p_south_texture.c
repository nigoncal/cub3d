/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_south_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 09:41:34 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/28 11:43:31 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	checking(t_info *info)
{
	int	fd;

	fd = 0;
	if (count_lines(info->elements) != 2
		|| ft_strcmp(info->elements[0], "SO") != 0)
		return (-1);
	if (format_check(info->elements[1], ".png") != -1)
		info->south_format = 1;
	if (format_check(info->elements[1], ".xpm") != -1)
		info->south_format = 2;
	if (info->south_format == 0)
		return (-1);
	fd = open(info->elements[1], O_DIRECTORY);
	if (fd >= 0)
		return (-1);
	fd = open(info->elements[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	return (0);
}

void	p_south_texture(char *line, t_info *info)
{
	if (info->south == true)
		abort_prog("SO (south) identifier is used more than once");
	info->elements = ft_split(line, ' ');
	if (checking(info) == -1)
		abort_prog("Usage : SO ./path_without_spaces.xpm OR .png");
	info->south_texture_path = ft_strdup(info->elements[1]);
	info->south = true;
}
