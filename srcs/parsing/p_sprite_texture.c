/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sprite_texture.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:02:15 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/18 17:12:41 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

/*
 * la fonction principale :
 *
 * verifie d'abord que l'identifiant n'a pas deja ete rencontre avec le booleen cub_sets->sprite
 * split la line avec espace comme separateur
 * elle appelle right_amount qui verifie qu'il y a bien 2 cub_sets->elements (l'identifiant et le path)
 *
 * celle-ci appelle right_file qui verifie - que l'idenfifiant est bien "S"
 * 										   - que le format du fichier de texture est bien .xpm ou .png via la fonction format_check qui est dans ma libft
 * 										   - que le path soit bon, que ce ne soit pas un directory que l'on essaye d'ouvrir comme fichier et que le fichier soit ouvrable, grace a deux appels d'open, un avec flag O_DIRECTORY, l'autre avec O_RDONLY
 *
 * a chaque fois s'il y a une erreur, 1 est renvoye, 0 si tout se passe bien
 * si tout s'est bien passe, le path est stocke dans cub_sets->sprite_texture_path et cub_sets->sprite est mis a true
*/

static int	right_file(t_settings *cub_sets)
{
	int	fd;

	fd = 0;
	if (ft_strcmp(cub_sets->elements[0], "S") != 0)
		return (-1);
	if ((format_check(cub_sets->elements[1], ".xpm")) +
			(format_check(cub_sets->elements[1], ".png")) == -2) // - 2 veut
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

static int	right_amount(t_settings *cub_sets)
{
	int	i;

	i = 0;
	while (cub_sets->elements[i])
		i++;
	if (i != 2)
		return (-1);
	if (right_file(cub_sets) == -1)
		return (-1);
	return (0);
}

void	p_sprite_texture(char *line, t_settings *cub_sets)
{
	if (cub_sets->sprite == true)
		abort_prog("S (sprite) identifier is used more than once");
	cub_sets->elements = ft_split(line, ' ');
	if (right_amount(cub_sets) == -1)
		abort_prog("Usage : S ./path_without_spaces.xpm OR .png");
	cub_sets->sprite_texture_path = ft_strdup(cub_sets->elements[1]);
	cub_sets->sprite = true;
//	free_char_p2p(cub_sets->elements);
}
