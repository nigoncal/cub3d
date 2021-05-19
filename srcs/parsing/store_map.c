/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:24:08 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/14 16:06:35 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

int	square_map(t_settings *cub_sets)
{
	char	**squared_map;
	int		x;
	int		i;
	int		j;

	i = 0;
	j = 0;
	squared_map = wrmalloc(sizeof(char *) * count_lines(cub_sets->map) + 1);
	if (squared_map == NULL)
		return (-1);
	x = longest_line(cub_sets->map);
	while (cub_sets->map[i])
	{
		squared_map[i] = wrmalloc(sizeof(char) * x + 1);
		if (squared_map[i] == NULL)
			return (-1);
		while (cub_sets->map[i][j])
		{
			squared_map[i][j] = cub_sets->map[i][j];
			j++;
		}
		while (j < x)
			squared_map[i][j++] = ' ';
		squared_map[i][j] = '\0';
		j = 0;
		i++;
	}
	squared_map[i] = 0;
	free_char_p2p(cub_sets->map);
	cub_sets->map = squared_map;
	return (0);
}

static void	add_map_line(char *line, t_settings *cub_sets)
{
	int		size;
	int		i;
	char	**temp;

	size = 0;
	i = 0;
	while (cub_sets->map[size])
		size++;
	size++;
	temp = (char**)wrmalloc(sizeof(char*) * size + 1);
	if (temp == NULL)
		abort_prog("Failed to malloc cub_sets->map");
	while (cub_sets->map[i])
	{
		temp[i] = ft_strdup(cub_sets->map[i]);
		i++;
	}
	temp[i] = ft_strdup(line);
	temp[i + 1] = 0;
	free_char_p2p(cub_sets->map);
	cub_sets->map = temp;

}

void	store_map(char *line, t_settings *cub_sets)
{
	if (cub_sets->map == NULL)
	{
		cub_sets->map = (char **)wrmalloc(sizeof(char *) + 1);
		if (cub_sets->map == NULL)
			abort_prog("Failed to malloc cub_sets->map");
		cub_sets->map[0] = ft_strdup(line);
		cub_sets->map[1] = 0;
	}
	else
		add_map_line(line, cub_sets);
}
