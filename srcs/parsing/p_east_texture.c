/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_east_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:43:39 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/13 14:50:36 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	checking(t_info *info)
{
	int	fd;

	fd = 0;
	if (count_lines(info->elements) != 2
		|| ft_strcmp(info->elements[0], "EA") != 0)
		return (-1);
	if (format_check(info->elements[1], ".png") != -1)
		info->east_format = 1;
	if (format_check(info->elements[1], ".xpm") != -1)
		info->east_format = 2;
	if (info->east_format == 0)
		return (-1);
	fd = open(info->elements[1], O_DIRECTORY);
	if (fd >= 0)
		return (-1);
	fd = open(info->elements[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	return (0);
}

void	p_east_texture(char *line, t_info *info)
{
	if (info->east == true)
		abort_prog("EA (east) identifier is used more than once");
	info->elements = ft_split(line, ' ');
	if (checking(info) == -1)
		abort_prog("Usage : EA ./path_without_spaces.xpm OR .png");
	info->east_texture_path = ft_strdup(info->elements[1]);
	info->east = true;
}
