/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ceiling.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:18:41 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/12 10:24:28 by sylducam         ###   ########lyon.fr   */
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
		rgb[i] = ft_atoi(&(*tab_rgb[i]));
		i++;
	}
	i = 0;
	while (rgb[i])
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (-1);
		i++;
	}
	cub_sets->c_color.chan.red = rgb[0];
	cub_sets->c_color.chan.green = rgb[1];
	cub_sets->c_color.chan.blue = rgb[2];
	return (0);
}

static int	right_content(t_settings *cub_sets)
{
	int		i;
	char	**tab_rgb;

	i = 0;
	tab_rgb = NULL;
	while (cub_sets->elements[i])
		i++;
	if (i != 2)
		return (-1);
	i = 0;
	if (ft_strcmp(cub_sets->elements[0], "C") != 0)
		return (-1);
	tab_rgb = ft_split(cub_sets->elements[1], ',');
	while (tab_rgb[i])
		i++;
	if (i != 3)
		return (-1);
	if (is_tab_digit(tab_rgb) == -1)
		return (-1);
	if (store_rgb(tab_rgb, cub_sets) == -1)
		return (-1);
	return (0);
}

void	p_ceiling(char *line, t_settings *cub_sets)
{
	if (cub_sets->b_ceiling == true)
		abort_prog(line, cub_sets, "Identifiers should be used only once");
	cub_sets->elements = ft_split(line, ' ');
	if (right_content(cub_sets) == -1)
		abort_prog(line, cub_sets, "C line :\nF r,g,b\n 0 >= r/g/b <= 255");
	cub_sets->b_ceiling = true;
	free_char_p2p(cub_sets->elements);
}
