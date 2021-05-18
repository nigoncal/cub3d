/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_north_texture.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:02:15 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/18 17:44:29 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

/*
 * la fonction principale :
 *
 * verifie d'abord que l'identifiant n'a pas deja ete rencontre avec le booleen cub_sets->north
 * split la line avec espace comme separateur
 * elle appelle right_amount qui verifie qu'il y a bien 2 cub_sets->elements (l'identifiant et le path)
 *
 * celle-ci appelle right_file qui verifie - que l'idenfifiant est bien "NO"
 * 										   - que le format du fichier de texture est bien .xpm ou .png via la fonction format_check qui est dans ma libft
 * 										   - que le path soit bon, que ce ne soit pas un directory que l'on essaye d'ouvrir comme fichier et que le fichier soit ouvrable, grace a deux appels d'open, un avec flag O_DIRECTORY, l'autre avec O_RDONLY
 *
 * a chaque fois s'il y a une erreur, 1 est renvoye, 0 si tout se passe bien
 * si tout s'est bien passe, le path est stocke dans cub_sets->north_texture_path et cub_sets->north est mis a true
*/

static int	checking(t_settings *cub_sets)
{
	int	fd;

	fd = 0;
	if (line_amount(cub_sets->elements) != 2
		|| ft_strcmp(cub_sets->elements[0], "NO") != 0
		|| ((format_check(cub_sets->elements[1], ".xpm"))
		+ (format_check(cub_sets->elements[1], ".png")) == -2)) // - 2 veut
		// dire que les deux formats ne correspondent pas (2 retours d'erreur).
		// Si c'est -1 c'est ok car l'un d'eux match (-1 + 0).
		return (-1);
	fd = open(cub_sets->elements[1], O_DIRECTORY);
	if (fd >= 0)
		return (-1);
	fd = open(cub_sets->elements[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	return (0);
}

void	p_north_texture(char *line, t_settings *cub_sets)
{
	if (cub_sets->north == true)
		abort_prog("NO (north) identifier is used more than once");
	cub_sets->elements = ft_split(line, ' ');
	if (checking(cub_sets) == -1)
		abort_prog("Usage : NO ./path_without_spaces.xpm OR .png");
	cub_sets->north_texture_path = ft_strdup(cub_sets->elements[1]);
	cub_sets->north = true;
}
