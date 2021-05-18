/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:27:03 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/18 14:01:01 by pmillet          ###   ########lyon.fr   */
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
		abort_prog("Failed to malloc cub_sets->mlx");
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
	if (square_map(cub_sets) == -1)
		abort_prog("Failed to malloc cub_sets->map");
	dprintf(1, "width = |%d|\n", cub_sets->width);
	dprintf(1, "height = |%d|\n", cub_sets->height);
	dprintf(1, "north = |%s|\n", cub_sets->north_texture_path);
	dprintf(1, "south = |%s|\n", cub_sets->south_texture_path);
	dprintf(1, "west = |%s|\n", cub_sets->west_texture_path);
	dprintf(1, "east = |%s|\n", cub_sets->east_texture_path);
	dprintf(1, "sprite = |%s|\n", cub_sets->sprite_texture_path);
	dprintf(1, "f_color = |%x|\n", cub_sets->f_color.color);
	dprintf(1, "f_color = |%d|\n", cub_sets->f_color.chan.red);
	dprintf(1, "f_color = |%d|\n", cub_sets->f_color.chan.green);
	dprintf(1, "f_color = |%d|\n", cub_sets->f_color.chan.blue);
	dprintf(1, "c_color = |%x|\n", cub_sets->c_color.color);
	dprintf(1, "c_color = |%d|\n", cub_sets->c_color.chan.red);
	dprintf(1, "c_color = |%d|\n", cub_sets->c_color.chan.green);
	dprintf(1, "c_color = |%d|\n", cub_sets->c_color.chan.blue);
	int c = 0;
	while (cub_sets->map[c])
	{
		dprintf(1, "cub_sets->map[c] = |%s|\n", cub_sets->map[c++]);
	}
	printf("nb de lignes de map/ Y : %d\n", c);
	printf("nb de colonnes de map/ X : %zu\n", ft_strlen(cub_sets->map[0]));
	
//	free_struct(cub_sets);
}
