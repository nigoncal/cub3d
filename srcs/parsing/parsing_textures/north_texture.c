/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 09:41:34 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/07 16:00:51 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	checking(t_setup *setup)
{
	int	fd;

	fd = 0;
	if (count_lines(setup->elements) != 2
		|| ft_strcmp(setup->elements[0], "NO") != 0)
		return (-1);
	if (format_check(setup->elements[1], ".png") != -1)
		setup->north_format = 1;
	if (format_check(setup->elements[1], ".xpm") != -1)
		setup->north_format = 2;
	if (setup->north_format == 0)
		return (-1);
	fd = open(setup->elements[1], O_DIRECTORY);
	if (fd >= 0)
		return (-1);
	fd = open(setup->elements[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	return (0);
}

void	north_texture(char *line, t_setup *setup)
{
	if (setup->north == true)
		abort_prog("NO (north) identifier is used more than once");
	setup->elements = ft_split(line, ' ');
	if (checking(setup) == -1)
		abort_prog("Usage : NO ./path_without_spaces.xpm OR .png");
	setup->north_texture_path = ft_strdup(setup->elements[1]);
	store_textures(setup);
	setup->north = true;
}
