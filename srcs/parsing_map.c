/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:24:43 by pmillet           #+#    #+#             */
/*   Updated: 2021/05/11 15:03:52 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	get_map_size(char *line, t_setup *setup)
{
	int	len;

	len = 0;
	//if (map_valid_line && line not empty)
	printf("on passe dans get map size\n");
	setup->map.nb_lines++;
	if ((len = ft_strlen(line)) > setup->map.longest_line)
		setup->map.longest_line = len;
	return (0);
}

int	parse_map(char *line, t_setup *setup)
{
	//static int	tab_line;
	
	if (setup->map.size_known != 1)
	{
		
		get_map_size(line, setup);
		// go to map parsing
	}
	else if (setup->map.malloced == 0)
	{
		//malloc le char ** de la struct pour stocker la map
		setup->map.map = malloc(sizeof(char *) * (setup->map.nb_lines + 1));
		if (setup->map.map == NULL)
			return (-1);
		else
			setup->map.malloced = 1;
	}
	if (setup->map.malloced)
	{
		//go to map_copy
		if (setup->map.nb_lines > 0)
		{
			setup->map.map[setup->map.tab_line] = line;
			if (setup->map.map[setup->map.tab_line] == NULL)
			{
				free_2d_tab(setup->map.map, setup->map.tab_line);
				return (-1);
			}
			setup->map.tab_line++;
			setup->map.nb_lines--;
		}
		else if (setup->map.nb_lines == 0)
		{
			setup->map.map[setup->map.tab_line] = 0;
		}
	}
	return (0);
}
