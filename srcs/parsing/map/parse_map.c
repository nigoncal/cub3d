/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <milletp.pro@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:46:12 by pmillet           #+#    #+#             */
/*   Updated: 2021/06/23 10:28:53 by pmillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	non_empty_line(char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (i == 2147483647)
		{
			close(fd);
			abort_prog("One of the line in you .cub file is too long");
		}
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\v')
			return (1);
		i++;
	}
	return (0);
}

static int	is_map(char *line)
{
	int			i;
	int			j;
	const char	*set;

	i = 0;
	set = " 10NSEW";
	while (line[i])
	{
		j = 0;
		while (set[j])
		{
			if (line[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			return (-1);
		i++;
	}
	return (0);
}

static void	continue_map(char *line, t_setup *setup, int fd)
{
	int	error;

	error = 0;
	if (setup->map_over == false)
	{
		if (non_empty_line(line, fd) == 1)
		{
			if (is_map(line) == 0)
				store_map(line, setup);
			else
			{
				close(fd);
				abort_prog("Forbidden character found in map. Allowed in map : \
N/S/E/W, 0, 1");
			}
		}
		else
			setup->map_over = true;
	}
	else if (non_empty_line(line, fd) == 1)
	{
		close(fd);
		abort_prog("Only empty lines are allowed after the end of the map");
	}
}

static void	start_map(char *line, t_setup *setup, int fd)
{
	if (non_empty_line(line, fd) == 1)
	{
		if (is_map(line) == 0)
		{
			store_map(line, setup);
			setup->map_started = true;
		}
		else
		{
			close(fd);
			abort_prog("There should be only 8 identifier lines");
		}
	}
}

void	parse_map(char *line, t_setup *setup, int fd)
{
	if (setup->map_started == true)
		continue_map(line, setup, fd);
	else
		start_map(line, setup, fd);
}
