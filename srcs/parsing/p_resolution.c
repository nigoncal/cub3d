/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_resolution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:06:19 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/25 13:24:09 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

/*
 * la fonction principale :
 * verifie que la ligne resolution n'a pas deja ete rencontree avec le bool cub_sets->R
 * split en utilisant les espaces
 * appelle check_elements
 *
 * check_elements :
 * verifie que le nombre d'elements est bien 3 pour (identifiant, width, height)
 * utilise ft_strcmp pour verifier que l'identifiant est bien juste "R"
 * verifie que les deux autre elements sont bien des digits avec ft_isdigit
 * qu'ils sont superieurs a 0
 * appelle too_big_for_screen
 * passe le bool cub_sets->R a true si aucune erreur n'a ete rencontree
 *
 * too_big_for_screen :
 * verifie si width et hieght sont superieurs a la taille de l'ecran et les bloque a la taille de l'ecran si c'est le cas
 *
*/

// vires tous les bouts de code d'autres fichiers pour ne garder que les fonctions de ce fichier. Ils t'ont servi a tester
// fais bien attention a ce que tout fonctionne avec ton main normal et header normal (parametres des fonctions)

void	too_big_for_screen(t_settings *cub_sets)
{
	int trigger;
	int	screen_width;
	int	screen_height;
	
	trigger = mlx_get_screen_size(cub_sets->mlx, &screen_width, &screen_height);
	if (cub_sets->width > screen_width)
		cub_sets->width = screen_width;
	if (cub_sets->height > screen_height)
		cub_sets->height = screen_height;
}

static int	right_content(char **elements, t_settings *cub_sets)
{
	int	i;

	i = 0;
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
	if (i != 3)
		return (-1);
	if (ft_strcmp(elements[0], "R") != 0)
		return (-1);
	if (right_content(elements, cub_sets) == -1)
		return (-1);
	if (cub_sets->width <= 0 || cub_sets->height <= 0)
		return (-1);
	too_big_for_screen(cub_sets);
	return (0);
}

void	resolution(char *line, t_settings *cub_sets)
{
	char	**elements;

	if (cub_sets->R == true)
		abort_prog(line, cub_sets, "Identifiers should be used only once");
	elements = ft_split(line, ' ');
	if (right_amount(elements, cub_sets) == -1)
		abort_prog(line, cub_sets, "R line :\nR <width> <height>\nOnly > 0");
	cub_sets->R = true;
	free_char_p2p(elements);
}