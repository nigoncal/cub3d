/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:06:01 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/25 16:05:39 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


void	add_line_map(char *line, t_settings *cub_sets)
{
	int		size;
	int		i;
	char	**temp;

	size = 0;
	i = 0;
	while (cub_sets->map[size])
		size++;
	size++;
	if ((temp = (char**)malloc(sizeof(char*) * size + 1)) == NULL) //Malloc la taille de ta map + 1
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

void	ft_map(char *line, t_settings *cub_sets)
{
	if (cub_sets->map == NULL)
	{
		if ((cub_sets->map = malloc(sizeof(char*) + 1)) == NULL)
			return ; // error message
		cub_sets->map[0] = ft_strdup(line);
		cub_sets->map[1] = 0;
	}
	else
		add_line_map(line, cub_sets);
}
