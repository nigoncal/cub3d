/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:27:03 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/15 16:22:47 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	non_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (i == 2147483647)
			abort_prog("One of the line in you .cub file is too long");
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\v')
			return (1);
		i++;
	}
	return (0);
}

void	start(int fd, char **line, t_info *info)
{
	while (get_next_line(fd, line))
	{
		if (info->id_counter < 6)
		{
			info->id_counter += non_empty_line(*line);
			parse_id(*line, info);
		}
		else
		{
			if (info->id_counter == 2147483647)
				abort_prog("Your map is too big");
			parse_map(*line, info);
		}
	}
	square_map(info);
	/*dprintf(1, "width = |%d|\n", info->game.width);
	dprintf(1, "height = |%d|\n", info->game.height);
	dprintf(1, "north = |%s|\n", info->north_texture_path);
	dprintf(1, "south = |%s|\n", info->south_texture_path);
	dprintf(1, "west = |%s|\n", info->west_texture_path);
	dprintf(1, "east = |%s|\n", info->east_texture_path);
	dprintf(1, "f_color = |%x|\n", info->game.f_color.color);
	dprintf(1, "f_color = |%d|\n", info->game.f_color.chan.red);
	dprintf(1, "f_color = |%d|\n", info->game.f_color.chan.green);
	dprintf(1, "f_color = |%d|\n", info->game.f_color.chan.blue);
	dprintf(1, "c_color = |%x|\n", info->game.c_color.color);
	dprintf(1, "c_color = |%d|\n", info->game.c_color.chan.red);
	dprintf(1, "c_color = |%d|\n", info->game.c_color.chan.green);
	dprintf(1, "c_color = |%d|\n", info->game.c_color.chan.blue);
	dprintf(1, "map_ysize = |%d|\n", info->map_ysize);
	dprintf(1, "map_xsize = |%d|\n", info->map_xsize);*/
	int c = 0;
/*	while (info->map[c])
		dprintf(1, "info->map[c] = |%s|\n", info->map[c++]);	*/
	check_map(info);
	c = 0;
	dprintf(1, "player_dir = |%c|\n", info->player_dir);
	dprintf(1, "dir_x = |%f|\n", info->game.dir_x);
	dprintf(1, "dir_y = |%f|\n", info->game.dir_y);
	dprintf(1, "pos_x = |%f|\n", info->game.pos_x);
	dprintf(1, "pos_y = |%f|\n", info->game.pos_y);
	while (info->map[c])
		dprintf(1, "info->map[c] = |%s|\n", info->map[c++]);
//	graph_textures(info);
	/*dprintf(1, "north_format = |%d|\n", info->north_format);
	dprintf(1, "south_format = |%d|\n", info->north_format);
	dprintf(1, "east_format = |%d|\n", info->north_format);
	dprintf(1, "west_format = |%d|\n", info->north_format);
	dprintf(1, "info->game.texture[0].img = |%p|\n", info->game.texture[0].img);
	//dprintf(1, "info->game.texture[0].addr = |%s|\n", info->game.texture[0].addr);
	//dprintf(1, "info->game.texture[0].addr = |%d|\n", *info->game.texture[0].addr);
	dprintf(1, "info->game.texture[0].bits_per_pixel = |%d|\n", info->game.texture[0].bits_per_pixel);
	dprintf(1, "info->game.texture[0].line_length = |%d|\n", info->game.texture[0].line_length);
	dprintf(1, "info->game.texture[0].endian = |%d|\n", info->game.texture[0].endian);
	dprintf(1, "info->game.texture[0].width = |%d|\n", info->game.texture[0].width);
	dprintf(1, "info->game.texture[0].height = |%d|\n", info->game.texture[0].height);
	dprintf(1, "info->game.texture[1].img = |%p|\n", info->game.texture[1].img);
	//dprintf(1, "info->game.texture[1].addr = |%s|\n", info->game.texture[1].addr);
	dprintf(1, "info->game.texture[1].bits_per_pixel = |%d|\n", info->game.texture[1].bits_per_pixel);
	dprintf(1, "info->game.texture[1].line_length = |%d|\n", info->game.texture[1].line_length);
	dprintf(1, "info->game.texture[1].endian = |%d|\n", info->game.texture[1].endian);
	dprintf(1, "info->game.texture[1].width = |%d|\n", info->game.texture[1].width);
	dprintf(1, "info->game.texture[2].height = |%d|\n", info->game.texture[2].height);
	dprintf(1, "info->game.texture[2].img = |%p|\n", info->game.texture[2].img);
	//dprintf(1, "info->game.texture[2].addr = |%s|\n", info->game.texture[2].addr);
	dprintf(1, "info->game.texture[2].bits_per_pixel = |%d|\n", info->game.texture[2].bits_per_pixel);
	dprintf(1, "info->game.texture[2].line_length = |%d|\n", info->game.texture[2].line_length);
	dprintf(1, "info->game.texture[2].endian = |%d|\n", info->game.texture[2].endian);
	dprintf(1, "info->game.texture[2].width = |%d|\n", info->game.texture[2].width);
	dprintf(1, "info->game.texture[2].height = |%d|\n", info->game.texture[2].height);
	dprintf(1, "info->game.texture[3].img = |%p|\n", info->game.texture[3].img);
	//dprintf(1, "info->game.texture[3].addr = |%s|\n", info->game.texture[3].addr);
	dprintf(1, "info->game.texture[3].bits_per_pixel = |%d|\n", info->game.texture[3].bits_per_pixel);
	dprintf(1, "info->game.texture[3].line_length = |%d|\n", info->game.texture[3].line_length);
	dprintf(1, "info->game.texture[3].endian = |%d|\n", info->game.texture[3].endian);
	dprintf(1, "info->game.texture[3].width = |%d|\n", info->game.texture[3].width);*/
	
}
