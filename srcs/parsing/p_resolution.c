/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_resolution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:06:19 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/16 13:27:48 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

/*
 * la fonction principale :
 * verifie que la ligne resolution n'a pas deja ete rencontree avec le bool cub_sets->res
 * split en utilisant les espaces
 * appelle check_elements
 *
 * check_elements :
 * verifie que le nombre d'elements est bien 3 pour (identifiant, width, height)
 * utilise ft_strcmp pour verifier que l'identifiant est bien juste "R"
 * verifie que les deux autre elements sont bien des digits avec ft_isdigit
 * qu'ils sont superieurs a 0
 * appelle too_big_for_screen
 * passe le bool cub_sets->res a true si aucune erreur n'a ete rencontree
 *
 * too_big_for_screen :
 * verifie si width et hieght sont superieurs a la taille de l'ecran et les bloque a la taille de l'ecran si c'est le cas
 *
*/

// vires tous les bouts de code d'autres fichiers pour ne garder que les fonctions de ce fichier. Ils t'ont servi a tester
// fais bien attention a ce que tout fonctionne avec ton main normal et header normal (parametres des fonctions)

static int	right_content(t_settings *cub_sets)
{
	int	i;
	int trigger;
	int	screen_width;
	int	screen_height;
	
	i = 0;
	trigger = mlx_get_screen_size(cub_sets->mlx, &screen_width, &screen_height);
	while (cub_sets->elements[1][i])
	{
		if (ft_isdigit(cub_sets->elements[1][i++]) == 0)
			return (-1);
	}
	i = 0;
	while (cub_sets->elements[2][i])
	{
		if (ft_isdigit(cub_sets->elements[2][i++]) == 0)
			return (-1);
	}
	cub_sets->width = atoi_limit(cub_sets->elements[1], screen_width);
	cub_sets->height = atoi_limit(cub_sets->elements[2], screen_height);
	return (0);
}

static int	right_amount(t_settings *cub_sets)
{
	int	i;

	i = 0;
	while (cub_sets->elements[i])
		i++;
	if (i != 3)
		return (-1);
	if (ft_strcmp(cub_sets->elements[0], "R") != 0)
		return (-1);
	if (right_content(cub_sets) == -1)
		return (-1);
	if (cub_sets->width <= 0 || cub_sets->height <= 0)
		return (-1);
	return (0);
}

void	p_resolution(char *line, t_settings *cub_sets)
{
	if (cub_sets->res == true)
		abort_prog("R identifier is used more than once");
	cub_sets->elements = ft_split(line, ' ');
	if (right_amount(cub_sets) == -1)
		abort_prog("Usage : R <width> <height> (both > 0)");
	cub_sets->res = true;
	free_char_p2p(cub_sets->elements);
}
