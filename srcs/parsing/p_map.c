/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:06:01 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/04 17:34:36 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

//	1 - check ce qu'il y a a la ligne d'avant dans **map
//	    Il peut y avoir : - rien (parsing de la map pas encore commence)
//	    				  - Une ligne de map
//	2 - Sauvegarde l'information (map ou rien, dans un bool)
//	3 - Deux comportements a partir de la :
//		- Si la map a commence, si je rencontre autre chose que de la map,
//		cela veut dire que la map est terminee
//		a) une ligne vide veut dire a priori fin du fichier mais je dois encore
//		aller jusqu'au bout pour en etre sur, entre temps je n'ajoute plus rien
//		a la map et : - Si je rencontre de nouveau de la map, c'est une erreur
//		car il y a deux maps
//					  - Si je rencontre une ligne non vide autre que de la map,
//		c'est potentiellement un id de nouveau ou n'importe quoi, dans les deux
//		cas, rien ne doit etre apres la map > erreur "Nothing else should be in
//		your .cub file after the map"
//		b) une ligne non vide mais qui ne soit pas de la map, juste apres la map
//		(sans ligne vide entre les deux), c'est une erreur car on retombe dans
//		le second cas du a).
//		- Si la map n'a pas commence :
//		a) Je rencontre une ligne non vide qui n'est pas de la map > erreur car
//		trop d'id (ou autre chose qu'id mais erreur aussi) "There can only be 8
//		identifier lines in your .cub file" (Si tu y arrives, si tu as le temps,
//		precises si c'est un identifiant ou pas dans l'erreur. Donc seconde
//		erreur : "Too many identifier lines and at least one is not even a
//		proper identifier")
//		b) Je rencontre une ligne vide, je skip et je continue
//		c) Je rencontre de la map, je commence a fill **map et je set le bool
//		de map a true

static int	is_map(char *line)
{
	int			i;
	int			j;
	const char	*set;

	i = 0;
	set = " 102NSEW";
	while (line[i])
	{
		j = 0;
		while (set[j])
		{
			if (line[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			return (-1);
		i++;
	}
	return (0);
}

static void	continue_map(char *line, t_settings *cub_sets)
{
	int	error;

	error = 0;
	if (cub_sets->map_over == false)
	{
		if (non_empty_line(line) == 1)
		{
			if (is_map(line) == 0)
				store_map(line,  cub_sets);
			else
				error = -1;
		}
		else
			cub_sets->map_over = true;
	}
	else
		if (non_empty_line(line) == 1)
			error = -1;
	if (error == -1)
		abort_prog(line, cub_sets, "Nothing else should be after the map");
}

static void	start_map(char *line, t_settings *cub_sets)
{
	if (non_empty_line(line) == 1)
	{
		if (is_map(line) == 0)
		{
			store_map(line, cub_sets);
			cub_sets->map_started = true;
		}
		else
			abort_prog(line, cub_sets, "Too many identifier lines");
	}
}

void	parse_map(char *line, t_settings *cub_sets)
{
	if (cub_sets->map_started == true)
		continue_map(line, cub_sets);
	else
		start_map(line, cub_sets);
}
