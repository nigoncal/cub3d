/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:11:38 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/14 16:48:34 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h" // a ajouter dans ton header
//#include "header_cub3d.h"
#include <stdbool.h>
#include "libft/header_libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h> // a virer

/*
 * la fonction principale :
 * verifie que la ligne resolution n'a pas deja ete rencontree avec le bool settings->R
 * split en utilisant les espaces
 * appelle check_elements
 *
 * check_elements :
 * verifie que le nombre d'elements est bien 3 pour (identifiant, width, height)
 * utilise ft_strcmp pour verifier que l'identifiant est bien juste "R"
 * verifie que les deux autre elements sont bien des digits avec ft_isdigit
 * qu'ils sont superieurs a 0
 * appelle too_big_for_screen
 * passe le bool settings->R a true si aucune erreur n'a ete rencontree
 *
 * too_big_for_screen :
 * verifie si width et hieght sont superieurs a la taille de l'ecran et les bloque a la taille de l'ecran si c'est le cas
 *
*/

// vires tous les bouts de code d'autres fichiers pour ne garder que les fonctions de ce fichier. Ils t'ont servi a tester
// fais bien attention a ce que tout fonctionne avec ton main normal et header normal (parametres des fonctions)

typedef struct	s_settings
{
	bool	R;
	int		width;
	int		height;
	void	*mlx;
}				cub_settings;

void	too_big_for_screen(cub_settings *settings)
{
	int trigger;
	int	*screen_width;
	int	*screen_height;
	
	screen_width = malloc(sizeof(int));
	screen_height = malloc(sizeof(int));
	trigger = mlx_get_screen_size(settings->mlx, screen_width, screen_height);
	if (settings->width > *screen_width)
		settings->width = *screen_width;
	if (settings->height > *screen_height)
		settings->height = *screen_height;
	free(screen_width);
	free(screen_height);
}

int		check_elements(char **elements, cub_settings *settings)
{
	int	i;

	i = 0;
	while (elements[i])
		i++;
	if (i != 3)
		return (1);
	i = 0;
	if (ft_strcmp(elements[0], "R"))
		return (1);
	while (elements[1][i])
		if (!(ft_isdigit(elements[1][i++])))
			return (1);
	i = 0;
	while (elements[2][i])
		if (!(ft_isdigit(elements[2][i++])))
			return (1);
	settings->width = ft_atoi(elements[1]);
	settings->height = ft_atoi(elements[2]);
	if (settings->width <= 0 || settings->height <= 0)
		return (1);
	too_big_for_screen(settings);
	settings->R = true;
	return (0);
}

void	resolution(char *line, cub_settings *settings)
{
	char **elements;

	if (settings->R == true)
		dprintf(1, "R already true\n");
	//	abort_prog(line, settings, "Identifiers should be used only once");
	elements = ft_split(line, ' ');
	if (check_elements(elements, settings))
		dprintf(1, "Error\n");
	//	abort_prog(line, settings, "Resolution line not well formated. Usage :\
	//			\nR <width> <height>\nOnly positive values");
	free(elements);
}
