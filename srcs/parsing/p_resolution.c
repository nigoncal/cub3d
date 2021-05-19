/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_resolution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:06:19 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/19 16:00:34 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

/*
 * la fonction principale :
 * verifie que la ligne resolution n'a pas deja ete rencontree avec le bool setup->res
 * split en utilisant les espaces
 * appelle check_elements
 *
 * check_elements :
 * verifie que le nombre d'elements est bien 3 pour (identifiant, width, height)
 * utilise ft_strcmp pour verifier que l'identifiant est bien juste "R"
 * verifie que les deux autre elements sont bien des digits avec ft_isdigit
 * qu'ils sont superieurs a 0
 * appelle too_big_for_screen
 * passe le bool setup->res a true si aucune erreur n'a ete rencontree
 *
 * too_big_for_screen :
 * verifie si width et hieght sont superieurs a la taille de l'ecran et les bloque a la taille de l'ecran si c'est le cas
 *
*/

// vires tous les bouts de code d'autres fichiers pour ne garder que les fonctions de ce fichier. Ils t'ont servi a tester
// fais bien attention a ce que tout fonctionne avec ton main normal et header normal (parametres des fonctions)

// utilises atoi_limit de deux manieres differentes. pour resolution, tu
// recuperes son retour
// pour couleur, s'il a depasse la limite, tu dis faux
//

static void	screen_size(t_setup *setup)
{
	int trigger;
	int	screen_width;
	int	screen_height;

	trigger = mlx_get_screen_size(setup->mlx, &screen_width, &screen_height);
	setup->game.width = atoi_limit(setup->elements[1], screen_width + 1);
	setup->game.height = atoi_limit(setup->elements[2], screen_height + 1);
	if (setup->game.width == screen_width + 1)
		setup->game.width = screen_width;
	if (setup->game.height == screen_height + 1)
		setup->game.height = screen_height;
}

static int	right_content(t_setup *setup)
{
	int	i;
	
	i = 0;
	while (setup->elements[1][i])
	{
		if (ft_isdigit(setup->elements[1][i++]) == 0) // fais une fonction qui check la str entiere
			return (-1);
	}
	i = 0;
	while (setup->elements[2][i])
	{
		if (ft_isdigit(setup->elements[2][i++]) == 0)
			return (-1);
	}
	screen_size(setup);
	return (0);
}

static int	right_amount(t_setup *setup)
{
	int	i;

	i = 0;
	while (setup->elements[i])
		i++;
	if (i != 3 || ft_strcmp(setup->elements[0], "R") != 0
		|| right_content(setup) == -1
		|| setup->game.width <= 0 || setup->game.height <= 0)
		return (-1);
//	if (ft_strcmp(setup->elements[0], "R") != 0)
//		return (-1);
//	if (right_content(setup) == -1)
//		return (-1);
//	if (setup->width <= 0 || setup->height <= 0)
//		return (-1);
	return (0);
}

void	p_resolution(char *line, t_setup *setup)
{
	if (setup->res == true)
		abort_prog("R identifier is used more than once");
	setup->elements = ft_split(line, ' ');
	if (right_amount(setup) == -1)
		abort_prog("Usage : R <width> <height> (both > 0)");
	setup->res = true;
	free_char_p2p(setup->elements);
}
