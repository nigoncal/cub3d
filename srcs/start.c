/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:27:03 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/25 14:31:19 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"

void	start(int fd, char **line, t_settings *cub_sets)
{
	cub_sets->mlx = mlx_init();
	while (get_next_line(fd, line))
	{
		if (cub_sets->id_counter < 8)
		{
			cub_sets->id_counter += non_empty_line(*line);
			parse_id(*line, cub_sets);
		}
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
}