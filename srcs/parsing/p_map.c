/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:06:01 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/03 09:51:49 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

static void	add_line_map(char *line, t_settings *cub_sets)
{
	int		size;
	int		i;
	char	**temp;

	size = 0;
	i = 0;
	while (cub_sets->map[size])
		size++;
	size++;
	temp = (char**)malloc(sizeof(char*) * size + 1);
	if (temp  == NULL)
		return ; // error message
	while (cub_sets->map[i])
	{
		temp[i] = ft_strdup(cub_sets->map[i]);
		i++;
	}
	temp[i] = ft_strdup(line);
	temp[i + 1] = 0;
	free(cub_sets->map);
	cub_sets->map = temp;
		
}

void	store_map(char *line, t_settings *cub_sets)
{
	if (cub_sets->map == NULL)
	{
		cub_sets->map = (char**)malloc(sizeof(char*) + 1);
		if (cub_sets->map == NULL)
			abort_prog(line, cub_sets, "Failed to malloc cub_sets->map");
		cub_sets->map[0] = ft_strdup(line); // fais attention free de ft_strdup
		cub_sets->map[1] = 0;
	}
	else
		add_map_line(line, cub_sets);
}