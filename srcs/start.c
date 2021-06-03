/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:27:03 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/31 14:41:12 by sylducam         ###   ########lyon.fr   */
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

void	start(int fd, char **line, t_setup *setup)
{
	setup->mlx = malloc(sizeof(void));
	setup->game.width = 1280;
	setup->game.height = 720;
	if (setup->mlx == NULL)
		abort_prog("Failed to malloc setup->mlx");
	setup->mlx = mlx_init();
	while (get_next_line(fd, line))
	{
		if (setup->id_counter < 6)
		{
			setup->id_counter += non_empty_line(*line);
			parse_id(*line, setup);
		}
		else
		{
			if (setup->id_counter == 2147483647)
				abort_prog("Your map is too big");
			parse_map(*line, setup);
		}
	}
	square_map(setup);
	dprintf(1, "width = |%d|\n", setup->game.width);
	dprintf(1, "height = |%d|\n", setup->game.height);
	dprintf(1, "north = |%s|\n", setup->north_texture_path);
	dprintf(1, "south = |%s|\n", setup->south_texture_path);
	dprintf(1, "west = |%s|\n", setup->west_texture_path);
	dprintf(1, "east = |%s|\n", setup->east_texture_path);
	dprintf(1, "f_color = |%x|\n", setup->game.f_color.color);
	dprintf(1, "f_color = |%d|\n", setup->game.f_color.chan.red);
	dprintf(1, "f_color = |%d|\n", setup->game.f_color.chan.green);
	dprintf(1, "f_color = |%d|\n", setup->game.f_color.chan.blue);
	dprintf(1, "c_color = |%x|\n", setup->game.c_color.color);
	dprintf(1, "c_color = |%d|\n", setup->game.c_color.chan.red);
	dprintf(1, "c_color = |%d|\n", setup->game.c_color.chan.green);
	dprintf(1, "c_color = |%d|\n", setup->game.c_color.chan.blue);
	dprintf(1, "map_ysize = |%d|\n", setup->map_ysize);
	dprintf(1, "map_xsize = |%d|\n", setup->map_xsize);
	int c = 0;
	while (setup->map[c])
		dprintf(1, "setup->map[c] = |%s|\n", setup->map[c++]);	
	check_map(setup);
	c = 0;
	dprintf(1, "player_dir = |%c|\n", setup->player_dir);
	dprintf(1, "dir_x = |%f|\n", setup->game.dir_x);
	dprintf(1, "dir_y = |%f|\n", setup->game.dir_y);
	dprintf(1, "pos_x = |%f|\n", setup->game.pos_x);
	dprintf(1, "pos_y = |%f|\n", setup->game.pos_y);
	while (setup->map[c])
		dprintf(1, "setup->map[c] = |%s|\n", setup->map[c++]);
	graph_textures(setup);
	dprintf(1, "north_format = |%d|\n", setup->north_format);
	dprintf(1, "south_format = |%d|\n", setup->north_format);
	dprintf(1, "east_format = |%d|\n", setup->north_format);
	dprintf(1, "west_format = |%d|\n", setup->north_format);
	//dprintf(1, "setup->game.texture[0].img = |%p|\n", setup->game.texture[0].img);
	//dprintf(1, "setup->game.texture[0].addr = |%s|\n", setup->game.texture[0].addr);
	//dprintf(1, "setup->game.texture[0].addr = |%d|\n", *setup->game.texture[0].addr);
	//dprintf(1, "setup->game.texture[0].bits_per_pixel = |%d|\n", setup->game.texture[0]->bits_per_pixel);
	//dprintf(1, "setup->game.texture[0].line_length = |%d|\n", setup->game.texture[0]->line_length);
	//dprintf(1, "setup->game.texture[0].endian = |%d|\n", setup->game.texture[0]->endian);
	//dprintf(1, "setup->game.texture[0].width = |%d|\n", setup->game.texture[0]->width);
	//dprintf(1, "setup->game.texture[0].height = |%d|\n", setup->game.texture[0]->height);
	////dprintf(1, "setup->game.texture[1].img = |%p|\n", setup->game.texture[1].img);
	////dprintf(1, "setup->game.texture[1].addr = |%s|\n", setup->game.texture[1].addr);
	//dprintf(1, "setup->game.texture[1].bits_per_pixel = |%d|\n", setup->game.texture[1]->bits_per_pixel);
	//dprintf(1, "setup->game.texture[1].line_length = |%d|\n", setup->game.texture[1]->line_length);
	//dprintf(1, "setup->game.texture[1].endian = |%d|\n", setup->game.texture[1]->endian);
	//dprintf(1, "setup->game.texture[1].width = |%d|\n", setup->game.texture[1]->width);
	//dprintf(1, "setup->game.texture[2].height = |%d|\n", setup->game.texture[2]->height);
	////dprintf(1, "setup->game.texture[2].img = |%p|\n", setup->game.texture[2].img);
	////dprintf(1, "setup->game.texture[2].addr = |%s|\n", setup->game.texture[2].addr);
	//dprintf(1, "setup->game.texture[2].bits_per_pixel = |%d|\n", setup->game.texture[2]->bits_per_pixel);
	//dprintf(1, "setup->game.texture[2].line_length = |%d|\n", setup->game.texture[2]->line_length);
	//dprintf(1, "setup->game.texture[2].endian = |%d|\n", setup->game.texture[2]->endian);
	//dprintf(1, "setup->game.texture[2].width = |%d|\n", setup->game.texture[2]->width);
	//dprintf(1, "setup->game.texture[2].height = |%d|\n", setup->game.texture[2]->height);
	////dprintf(1, "setup->game.texture[3].img = |%p|\n", setup->game.texture[3].img);
	////dprintf(1, "setup->game.texture[3].addr = |%s|\n", setup->game.texture[3].addr);
	//dprintf(1, "setup->game.texture[3].bits_per_pixel = |%d|\n", setup->game.texture[3]->bits_per_pixel);
	//dprintf(1, "setup->game.texture[3].line_length = |%d|\n", setup->game.texture[3]->line_length);
	//dprintf(1, "setup->game.texture[3].endian = |%d|\n", setup->game.texture[3]->endian);
	//dprintf(1, "setup->game.texture[3].width = |%d|\n", setup->game.texture[3]->width);
	wrdestroy();
}
