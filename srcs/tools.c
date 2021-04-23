/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:57:36 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/23 09:57:07 by sylducam         ###   ########lyon.fr   */
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

	i = 0;
	j = 0;
	while (line[i])
	{
		while (cub_sets->map_char[j])
		{
			if (line[i] == cub_sets->map_char[j])
				break ;
			j++;
			return (-1);
		}
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

int	ft_count_lines(int fd, int lines)
{
	char		*reader;
	int			eoread;
	
	reader = NULL;
	if ((reader = malloc(sizeof(char) * 4)) == NULL)
		return (0); // specifier erreur
	while ((eoread = read(fd, reader, 4)) > 0)
		lines += count_eol(reader);
	free(reader);
	return (lines);
}
