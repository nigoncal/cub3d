/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_floor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:18:48 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/10 15:58:10 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

static int	store_rgb(char **tab_rgb, t_settings *cub_sets)
{
	int	i;
	int	j;
	int	rgb[3];

	i = 0;
	j = 0;
	while (tab_rgb[i])
	{
		while (tab_rgb[i][j])
			rgb[i] = ft_atoi(&tab_rgb[i][j++]); // j'ai mis & car il attend un const char mais c'est l'erreur de compil qui me conseillait ca, testes si ca marche
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
	cub_sets->f_color = (rgb[0] << 16) | (rgb[1] << 8) | (rgb[2]);
	return (0);
}

static int	right_content(char **elements, t_settings *cub_sets)
{
	int		i;
	char	**tab_rgb;

	i = 0;
	tab_rgb = NULL;
	while (elements[i])
		i++;
	if (i != 2)
		return (-1);
	i = 0;
	if (ft_strcmp(elements[0], "F") != 0)
		return (-1);
	tab_rgb = ft_split(elements[1], ',');
	while (elements[i])
		i++;
	if (i != 3)
		return (-1);
	if (is_tab_digit(tab_rgb) == -1)
		return (-1);
	if (store_rgb(tab_rgb, cub_sets) == -1)
		return (-1);
	return (0);
}

void	p_floor(char *line, t_settings *cub_sets)
{
	char	**elements;

	if (cub_sets->b_floor == true)
		abort_prog(line, cub_sets, "Identifiers should be used only once");
	elements = ft_split(line, ' ');
	if (right_content(elements, cub_sets) == -1)
	{
		free_char_p2p(elements);
		abort_prog(line, cub_sets, "F line :\nF r,g,b\n 0 >= r/g/b <= 255");
	}
	cub_sets->b_floor = true;
	free_char_p2p(elements);
}
