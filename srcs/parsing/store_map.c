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

int	square_map(t_setup *setup)
{
	char	**squared_map;
	int		x;
	int		i;
	int		j;

	i = 0;
	j = 0;
	squared_map = wrmalloc(sizeof(char *) * count_lines(setup->map) + 1);
	if (squared_map == NULL)
		return (-1);
	x = longest_line(setup->map);
	while (setup->map[i])
	{
		squared_map[i] = wrmalloc(sizeof(char) * x + 1);
		if (squared_map[i] == NULL)
			return (-1);
		while (setup->map[i][j])
		{
			squared_map[i][j] = setup->map[i][j];
			j++;
		}
		while (j < x)
			squared_map[i][j++] = ' ';
		squared_map[i][j] = '\0';
		j = 0;
		i++;
	}
	squared_map[i] = 0;
	free_char_p2p(setup->map);
	setup->map = squared_map;
	return (0);
}

static void	add_map_line(char *line, t_setup *setup)
{
	int		size;
	int		i;
	char	**temp;

	size = 0;
	i = 0;
	while (setup->map[size])
		size++;
	size++;
	temp = (char**)wrmalloc(sizeof(char*) * size + 1);
	if (temp == NULL)
		abort_prog("Failed to malloc setup->map");
	while (setup->map[i])
	{
		temp[i] = ft_strdup(setup->map[i]);
		i++;
	}
	temp[i] = ft_strdup(line);
	temp[i + 1] = 0;
	free_char_p2p(setup->map);
	setup->map = temp;

}

void	store_map(char *line, t_setup *setup)
{
	if (setup->map == NULL)
	{
		setup->map = (char **)wrmalloc(sizeof(char *) + 1);
		if (setup->map == NULL)
			abort_prog("Failed to malloc setup->map");
		setup->map[0] = ft_strdup(line);
		setup->map[1] = 0;
	}
	else
		add_map_line(line, setup);
}
