/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:16:19 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/06 18:11:51 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "header_cub3D.h"
#include <stdio.h> // a virer

void	cub3D(int fd, char **line)
{
	cub_settings	settings;

	ft_bzero(&settings, sizeof(cub_settings));
	while (get_next_line(fd, line))
	{
		if (map_start(line) <= 8)
			parse_id(*line, &settings); // continues de passer tout le reste ne simple pointeur dans les fonctions a venir, souviens toi des epxlications de Mohammed notees dans ton cahier
		else
			parse_map(*line, &settings);
	}
	dprintf(1, "width = |%d|\n", settings.width);
	dprintf(1, "height = |%d|\n", settings.height);
	dprintf(1, "north = |%s|\n", settings.north_texture_path);
	dprintf(1, "south = |%s|\n", settings.south_texture_path);
	dprintf(1, "west = |%s|\n", settings.west_texture_path);
	dprintf(1, "east = |%s|\n", settings.east_texture_path);
	dprintf(1, "sprite = |%s|\n", settings.sprite_texture_path);
	dprintf(1, "floor_red = |%d|\n", settings.floor_red);
	dprintf(1, "floor_green = |%d|\n", settings.floor_green);
	dprintf(1, "floor_blue = |%d|\n", settings.floor_blue);
	dprintf(1, "ceiling_red = |%d|\n", settings.ceiling_red);
	dprintf(1, "ceiling_green = |%d|\n", settings.ceiling_green);
	dprintf(1, "ceiling_blue = |%d|\n", settings.ceiling_blue);
	dprintf(1, "settings->map = |%s|\n", settings.map[0]);
	dprintf(1, "settings->map = |%s|\n", settings.map[1]);
	dprintf(1, "settings->map = |%s|\n", settings.map[2]);
	dprintf(1, "settings->map = |%s|\n", settings.map[3]);
	dprintf(1, "settings->map = |%s|\n", settings.map[4]);
	dprintf(1, "settings->map = |%s|\n", settings.map[5]);
	dprintf(1, "settings->map = |%s|\n", settings.map[6]);
	dprintf(1, "settings->map = |%s|\n", settings.map[7]);
	dprintf(1, "settings->map = |%s|\n", settings.map[8]);
	dprintf(1, "settings->map = |%s|\n", settings.map[9]);
	dprintf(1, "settings->map = |%s|\n", settings.map[10]);
	dprintf(1, "settings->map = |%s|\n", settings.map[11]);
	dprintf(1, "settings->map = |%s|\n", settings.map[12]);
	dprintf(1, "settings->map = |%s|\n", settings.map[13]);
	dprintf(1, "settings->map = |%s|\n", settings.map[14]);
//	check_cub(settings);
}
