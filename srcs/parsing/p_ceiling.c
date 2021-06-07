/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ceiling.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:36:44 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/27 09:39:36 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	store_rgb(char **tab_rgb, t_info *info)
{
	int	i;
	int	rgb[3];

	i = 0;
	while (tab_rgb[i])
	{
		rgb[i] = atoi_limit(tab_rgb[i], COLOR_MAX + 1);
		if (rgb[i] == COLOR_MAX + 1)
			return (-1);
		i++;
	}
	info->game.c_color.chan.red = rgb[0];
	info->game.c_color.chan.green = rgb[1];
	info->game.c_color.chan.blue = rgb[2];
	return (0);
}

static int	right_content(t_info *info)
{
	char	**tab_rgb;

	tab_rgb = NULL;
	if (count_lines(info->elements) != 2
		|| ft_strcmp(info->elements[0], "C") != 0)
		return (-1);
	tab_rgb = ft_split(info->elements[1], ',');
	if (count_lines(tab_rgb) != 3 || is_tab_digit(tab_rgb) == -1
		|| store_rgb(tab_rgb, info) == -1)
		return (-1);
	return (0);
}

void	p_ceiling(char *line, t_info *info)
{
	if (info->b_ceiling == true)
		abort_prog("C identifier is used more than once");
	info->elements = ft_split(line, ' ');
	if (right_content(info) == -1)
		abort_prog("Usage : C r,g,b (with 0 >= r/g/b <= 255)");
	info->b_ceiling = true;
	wrfree(info->elements);
}
