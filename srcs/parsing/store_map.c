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

#include "../../includes/cub3d.h"

static void	add_map_line(char *line, t_info *info)
{
	int		size;
	int		y;
	char	**temp;

	size = 0;
	y = 0;
	while (info->map[size])
	{
		if (size == 2147483647 && info->map[size])
			abort_prog("Your map is too big");
		size++;
	}
	size++;
	temp = (char **)wrmalloc(sizeof(char *) * size + 1);
	if (temp == NULL)
		abort_prog("Failed to malloc info->map");
	while (info->map[y])
	{
		temp[y] = ft_strdup(info->map[y]);
		y++;
	}
	temp[y] = ft_strdup(line);
	temp[y + 1] = 0;
	free_char_p2p(info->map);
	info->map = temp;
}

void	store_map(char *line, t_info *info)
{
	if (info->map == NULL)
	{
		info->map = (char **)wrmalloc(sizeof(char *) + 1);
		if (info->map == NULL)
			abort_prog("Failed to malloc info->map");
		info->map[0] = ft_strdup(line);
		info->map[1] = 0;
	}
	else
		add_map_line(line, info);
}
