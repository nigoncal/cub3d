/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_floor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:18:48 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/19 10:25:18 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

static int	store_rgb(char **tab_rgb, t_settings *cub_sets)
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
	cub_sets->f_color.chan.red = rgb[0];
	cub_sets->f_color.chan.green = rgb[1];
	cub_sets->f_color.chan.blue = rgb[2];
	return (0);
}

static int	right_content(t_settings *cub_sets)
{
	char	**tab_rgb;

	tab_rgb = NULL;
	if (count_lines(cub_sets->elements) != 2
		|| ft_strcmp(cub_sets->elements[0], "F") != 0)
		return (-1);
	tab_rgb = ft_split(cub_sets->elements[1], ',');
	if (count_lines(tab_rgb) != 3 || is_tab_digit(tab_rgb) == -1
		|| store_rgb(tab_rgb, cub_sets) == -1)
		return (-1);
	return (0);
}

void	p_floor(char *line, t_settings *cub_sets)
{
	if (cub_sets->b_floor == true)
		abort_prog("F identifier is used more than once");
	cub_sets->elements = ft_split(line, ' ');
	if (right_content(cub_sets) == -1)
		abort_prog("Usage : F r,g,b (with 0 >= r/g/b <= 255)");
	cub_sets->b_floor = true;
	free_char_p2p(cub_sets->elements);
}
