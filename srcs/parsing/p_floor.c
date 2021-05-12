/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_floor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:18:48 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/12 10:28:06 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

static int	store_rgb(char **tab_rgb, t_settings *cub_sets)
{
	int	i;
	int	j;
	int	rgb[3];
	//int debog;

	i = 0;
	j = 0;
	while (tab_rgb[i])
	{
		rgb[i] = ft_atoi(&(*tab_rgb[i])); // j'ai mis & car il attend un const char mais c'est l'erreur de compil qui me conseillait ca, testes si ca marche
		i++;
	}
	i = 0;
	while (rgb[i])
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (-1);
		i++;
	}
	//cub_sets->f_color.color = (rgb[0] << 16) | (rgb[1] << 8) | (rgb[2]);
	/*debog*/
	/*debog = 0;
	while (debog < 3)
	{
		printf("canal %d = %d\n", debog, rgb[debog]);
		debog++;
	}*/
	cub_sets->f_color.chan.red = rgb[0];
	cub_sets->f_color.chan.green = rgb[1];
	cub_sets->f_color.chan.blue = rgb[2];
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
	if (ft_strcmp(cub_sets->elements[0], "F") != 0)
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

void	p_floor(char *line, t_settings *cub_sets)
{
	if (cub_sets->b_floor == true)
		abort_prog(line, cub_sets, "Identifiers should be used only once");
	cub_sets->elements = ft_split(line, ' ');
	if (right_content(cub_sets) == -1)
		abort_prog(line, cub_sets, "F line :\nF r,g,b\n 0 >= r/g/b <= 255");
	cub_sets->b_floor = true;
	free_char_p2p(cub_sets->elements);
}
