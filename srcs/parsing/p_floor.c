/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_colors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:13:32 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/08 16:50:58 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

// Tu en es a right content et ton plan c'est de faire un split sur le 2e
// element du tableau avec ',' pour separer r, g et b. De la il te faudra
// - verifier qu'il y en a bien 3
// - que les valeurs sont comprises entre 0 et 255
//

// il te faut passer trois fois dedans avec un tableau d'int, donc i = 0 et tu check si tu n'as pas deja enregistre un C ou un F et si ca passe plus de 3 fois ca veut dire qu'il y a plus que rgb, donc erreur

static int	right_content(char **elements, t_settings *cub_sets)
{
	char *rgb;

	rgb = NULL;
	rgb = ft_split(elements[1], ',');
	while (elements[1][i])
	{
		if (ft_isdigit(elements[1][i++]) == 0)
			return (-1);
	}
	i = 0;
	while (elements[2][i])
	{
		if (ft_isdigit(elements[2][i++]) == 0)
			return (-1);
	}
	cub_sets->width = ft_atoi(elements[1]);
	cub_sets->height = ft_atoi(elements[2]);
	return (0);
}

static int	right_amount(char **elements, t_settings *cub_sets)
{
	int	i;

	i = 0;
	while (elements[i])
		i++;
	if (i != 2)
		return (-1);
	if (ft_strcmp(elements[0], "F") != 0)
		return (-1);
	if (right_content(elements, cub_sets) == -1)
		return (-1);
	// ICI
	if (cub_sets->width <= 0 || cub_sets->height <= 0)
		return (-1);
	too_big_for_screen(cub_sets);
	return (0);
}

void	p_floor(char *line, t_settings *cub_sets)
{
	char	**elements;

	if (cub_sets->b_floor == true)
		abort_prog(line, cub_sets, "Identifiers should be used only once");
	elements = ft_split(line, ' ');
	if (right_amount(elements, cub_sets) == -1)
		abort_prog(line, cub_sets, "F line :\nR <width> <height>\nOnly > 0");
	cub_sets->b_floor = true;
	free_char_p2p(elements);
}
