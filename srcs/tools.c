/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:57:36 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/25 08:11:01 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"
#include "libft/header_libft.h"
#include "get_next_line/get_next_line.h"
#include "header_cub3d.h"

int	is_map(char *line, t_settings *cub_sets)
{
	int	i;
	int	j;
	char *set;

	i = 0;
	j = 0;
	set = " 102NSEW";
	while (line[i])
	{
		while (set[j])
		{
			if (line[i] == set[j])
				break ;
			j++;
			return (-1);
		}
		i++;
	}
	return (0);
}

int	non_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t'
			&& line[i] != '\v' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

void	init_map_char(t_settings *cub_sets)
{
	char	*set;
	int		i;

	i = 0;
	set = " 102NSEW";
	while (set[i])
	{
		cub_sets->map_char[i] = set[i];
		i++;
	}
	cub_sets->map_char[i] = set[i];
}
