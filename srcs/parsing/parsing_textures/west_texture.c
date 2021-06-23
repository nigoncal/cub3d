/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   west_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <milletp.pro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:53:53 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/23 08:43:40 by pmillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	checking(t_setup *setup)
{
	int	fd;

	fd = 0;
	if (count_lines(setup->elements) != 2
		|| ft_strcmp(setup->elements[0], "WE") != 0
		|| format_check(setup->elements[1], ".xpm") == -1)
		return (-1);
	fd = open(setup->elements[1], O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		abort_prog("One of your textures is a directory, not a real .xpm");
	}
	fd = open(setup->elements[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

void	west_texture(char *line, t_setup *setup)
{
	if (setup->west == true)
		abort_prog("WE (west) identifier is used more than once");
	setup->elements = ft_split(line, ' ');
	if (checking(setup) == -1)
		abort_prog("Usage : WE ./path_without_spaces.xpm");
	setup->west_texture_path = ft_strdup(setup->elements[1]);
	if (setup->west_texture_path == NULL)
		abort_prog("Failed to malloc setup->west_texture_path");
	setup->west = true;
}
