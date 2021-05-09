/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_colors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:13:32 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/09 10:23:05 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

// Tu en es a right content et ton plan c'est de faire un split sur le 2e
// element du tableau avec ',' pour separer r, g et b. De la il te faudra
// - verifier qu'il y en a bien 3
// - que les valeurs sont comprises entre 0 et 255
//

// il te faut passer trois fois dedans avec un tableau d'int, donc i = 0 et tu check si tu n'as pas deja enregistre un C ou un F et si ca passe plus de 3 fois ca veut dire qu'il y a plus que rgb, donc erreur

static int	store_rgb(char **rgb, t_settings *cub_sets)
{
	int	r;
	int	g;
	int	b;

	r = -1;
	g = -1;
	b = -1;
	// verifies bien si les 3 lignes du split sont des int, car il est possible
	// que tu sortes d'ici avec lesvaleurs de rgb que tu as preset. Normalement 
	// avec -1 ca doit le faire
}

static int	right_content(char **rgb, t_settings *cub_sets)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (rgb[i])
	{
		while (rgb[i][j])
		{
			if (ft_isdigit(rgb[i][j++]) == 0)
				return (-1);
		}
		j = 0;
		i++;
	}
	cub_sets->width = ft_atoi(rgb[1]);
	cub_sets->height = ft_atoi(rgb[2]);
	return (0);
}

static int	right_amount(char **elements, t_settings *cub_sets)
{
	int	i;
	char **rgb;

	i = 0;
	rgb = NULL;
	while (elements[i])
		i++;
	if (i != 2)
		return (-1);
	i = 0;
	if (ft_strcmp(elements[0], "F") != 0)
		return (-1);
	rgb = ft_split(elements[1], ',');
	while (elements[i])
		i++;
	if (i != 3)
		return (-1);
	if (right_content(rbg, cub_sets) == -1)
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
	{
		free_char_p2p(elements);
		abort_prog(line, cub_sets, "F line :\nR <width> <height>\nOnly > 0");
	}
	cub_sets->b_floor = true;
	free_char_p2p(elements);
}
