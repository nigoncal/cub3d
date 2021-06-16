/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:24:08 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/27 10:08:05 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	add_map_line(char *line, t_setup *setup)
{
	int		size;
	int		y;
	char	**temp;

	size = 0;
	y = 0;
	while (setup->map[size])
	{
		if (size == 2147483647 && setup->map[size])
			abort_prog("Your map is too big");
		size++;
	}
	size++;
	temp = (char **)wrmalloc(sizeof(char *) * size + 1);
	if (temp == NULL)
		abort_prog("Failed to malloc setup->map");
	while (setup->map[y])
	{
		temp[y] = ft_strdup(setup->map[y]);
		y++;
	}
	temp[y] = ft_strdup(line);
	temp[y + 1] = 0;
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
