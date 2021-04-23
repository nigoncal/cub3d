/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:27:03 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/23 11:24:33 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/header_libft.h"
#include "get_next_line/get_next_line.h"
#include "header_cub3d.h"
#include <stdio.h> // a virer

static int	id_part(char *line)
{
	static int	non_empty_lines = 0;
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t'
			&& line[i] != '\v' && line[i] != '\n')
		{
			non_empty_lines++;
			break ;
		}
		i++;
	}
	return (non_empty_lines);
}

void	start(int fd, char **line, t_settings *cub_sets)
{
	cub_sets->mlx = mlx_init();
	init_map_char(cub_sets);
	while (get_next_line(fd, line))
	{
		if (id_part(*line) <= 8)
			parse_id(*line, cub_sets); // continues de passer tout le reste ne simple pointeur dans les fonctions a venir, souviens toi des epxlications de Mohammed notees dans ton cahier
		else
		{
			parse_map(*line, cub_sets);
		}
	}
	free(cub_sets); // mieux
	dprintf(1, "width = |%d|\n", cub_sets->width);
	dprintf(1, "height = |%d|\n", cub_sets->height);
	dprintf(1, "north = |%s|\n", cub_sets->north_texture_path);
	dprintf(1, "south = |%s|\n", cub_sets->south_texture_path);
	dprintf(1, "west = |%s|\n", cub_sets->west_texture_path);
	dprintf(1, "east = |%s|\n", cub_sets->east_texture_path);
	dprintf(1, "sprite = |%s|\n", cub_sets->sprite_texture_path);
	dprintf(1, "floor_red = |%d|\n", cub_sets->floor_red);
	dprintf(1, "floor_green = |%d|\n", cub_sets->floor_green);
	dprintf(1, "floor_blue = |%d|\n", cub_sets->floor_blue);
	dprintf(1, "ceiling_red = |%d|\n", cub_sets->ceiling_red);
	dprintf(1, "ceiling_green = |%d|\n", cub_sets->ceiling_green);
	dprintf(1, "ceiling_blue = |%d|\n", cub_sets->ceiling_blue);
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[0]);
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[1]);
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[2]);
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[3]);
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[4]);
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[5]);
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[6]);
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[7]);
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[8]);
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[9]);
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[10]);
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[11]);
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[12]);
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[13]);
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[14]);
//	check_cub(cub_sets);
}
