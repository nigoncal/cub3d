/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:27:03 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/11 14:25:21 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"

int	non_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\v')
			return (1);
		i++;
	}
	return (0);
}

void	start(int fd, char **line, t_settings *cub_sets)
{
	cub_sets->mlx = malloc(sizeof(void));
	if (cub_sets->mlx == NULL)
		abort_prog(*line, cub_sets, "Failed to malloc cub_sets->mlx");
	cub_sets->mlx = mlx_init();
	while (get_next_line(fd, line))
	{
		dprintf(1, "X\n");
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
//	free(cub_sets); // mieux
	dprintf(1, "width = |%d|\n", cub_sets->width);
	dprintf(1, "height = |%d|\n", cub_sets->height);
	dprintf(1, "north = |%s|\n", cub_sets->north_texture_path);
	dprintf(1, "south = |%s|\n", cub_sets->south_texture_path);
	dprintf(1, "west = |%s|\n", cub_sets->west_texture_path);
	dprintf(1, "east = |%s|\n", cub_sets->east_texture_path);
	dprintf(1, "sprite = |%s|\n", cub_sets->sprite_texture_path);
	dprintf(1, "f_color = |%d|\n", cub_sets->f_color);
	dprintf(1, "c_color = |%d|\n", cub_sets->c_color);
/*	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[0]);
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
	dprintf(1, "cub_sets->map = |%s|\n", cub_sets->map[14]);*/
}
