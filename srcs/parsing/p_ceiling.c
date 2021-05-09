/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ceiling.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:18:41 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/09 11:21:04 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

static int	store_rgb(char **t_rgb, t_settings *cub_sets)
{
	int	rbg[3];

	while (t_rgb[i])
	{
		while (t_rgb[i][j])
			rgb[i] = ft_atoi(t_rgb[i][j++]);
		j = 0;
		i++;
	}
	i = 0;
	while (rgb[i])
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (-1);
		i++;
	}
	cub_sets->c_red = rgb[0];
	cub_sets->c_green = rgb[1];
	cub_sets->c_blue = rgb[2];
}

static int	right_content(char **elements, t_settings *cub_sets)
{
	int		i;
	char	**t_rgb;

	i = 0;
	rgb = NULL;
	while (elements[i])
		i++;
	if (i != 2)
		return (-1);
	i = 0;
	if (ft_strcmp(elements[0], "C") != 0)
		return (-1);
	rgb = ft_split(elements[1], ',');
	while (elements[i])
		i++;
	if (i != 3)
		return (-1);
	if (is_tab_digit(t_rbg) == -1)
		return (-1);
	if (store_rgb(t_rgb, cub_sets) == -1)
		return (-1);
	return (0);
}

void	p_ceiling(char *line, t_settings *cub_sets)
{
	char	**elements;

	if (cub_sets->b_ceiling == true)
		abort_prog(line, cub_sets, "Identifiers should be used only once");
	elements = ft_split(line, ' ');
	if (right_content(elements, cub_sets) == -1)
	{
		free_char_p2p(elements);
		abort_prog(line, cub_sets, "C line :\nF r,g,b\n 0 >= r/g/b <= 255");
	}
	cub_sets->b_ceiling = true;
	free_char_p2p(elements);
}
