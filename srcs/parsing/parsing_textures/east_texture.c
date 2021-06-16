/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   east_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:53:36 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/16 09:58:08 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	checking(t_setup *setup)
{
	int	fd;

	fd = 0;
	if (count_lines(setup->elements) != 2
		|| ft_strcmp(setup->elements[0], "EA") != 0
		|| format_check(setup->elements[1], ".xpm") == -1)
		return (-1);
	fd = open(setup->elements[1], O_DIRECTORY);
	if (fd >= 0)
		return (-1);
	fd = open(setup->elements[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	return (0);
}

void	east_texture(char *line, t_setup *setup)
{
	if (setup->east == true)
		abort_prog("EA (east) identifier is used more than once");
	setup->elements = ft_split(line, ' ');
	if (checking(setup) == -1)
		abort_prog("Usage : EA ./path_without_spaces.xpm OR .png");
	setup->east_texture_path = ft_strdup(setup->elements[1]);
	setup->east = true;
}