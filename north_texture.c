/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north_texture.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:02:15 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/14 15:23:34 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include "header_cub3d.h"
#include <stdbool.h>
#include "libft/header_libft.h"
#include "get_next_line/get_next_line.h" // en a-t-il besoin ?
#include <strings.h>
#include "minilibx/mlx.h" // a virer

/*
 * la fonction principale :
 *
 * verifie d'abord que l'identifiant n'a pas deja ete rencontre avec le booleen settings->NO
 * split la line avec espace comme separateur
 * elle appelle right_amount qui verifie qu'il y a bien 2 elements (l'identifiant et le path)
 *
 * celle-ci appelle right_file qui verifie - que l'idenfifiant est bien "NO"
 * 										   - que le format du fichier de texture est bien .xpm ou .png via la fonction format_check qui est dans ma libft
 * 										   - que le path soit bon, que ce ne soit pas un directory que l'on essaye d'ouvrir comme fichier et que le fichier soit ouvrable, grace a deux appels d'open, un avec flag O_DIRECTORY, l'autre avec O_RDONLY
 *
 * a chaque fois s'il y a une erreur, 1 est renvoye, 0 si tout se passe bien
 * si tout s'est bien passe, le path est stocke dans settings->north_texture_path et settings->NO est mis a true
*/

typedef struct	s_settings
{
	bool	NO;
	int		north_fd;
	char	*north_texture_path;
	void	*mlx;
}				cub_settings;

static int	right_file(char **elements, cub_settings *settings)
{
	int	fd;

	fd = 0;
	if (ft_strcmp(elements[0], "NO"))
		return (1);
	if (((format_check(elements[1], ".xpm")) +
			(format_check(elements[1], ".png"))) == 2) // formulation un peu bizarre mais ca ne marchait pas avec && ou juste +. 2 veut dire que les deux formats ne correspondent pas (2 retours d'erreur). Si c'est 1 c'est ok car l'un deux match.
		return (1);
	fd = open(elements[1], O_DIRECTORY);
	settings->north_fd = fd; // a virer, juste pour les test
	if (fd >= 0)
		return (1);
	fd = open(elements[1], O_RDONLY);
	settings->north_fd = fd; // a virer, juste pour les test
	if (fd < 0)
		return (1);
	return (0);
}

static int	right_amount(char **elements, cub_settings *settings)
{
	int	i;

	i = 0;
	while (elements[i])
		i++;
	if (i != 2)
		return (1);
	if (right_file(elements, settings))
		return (1);
	return (0);
}

int			north_texture(char *line, cub_settings *settings)
{
	char **elements; // a free ?

	if (settings->NO == true)
		return (1);
	elements = ft_split(line, ' ');
	if (right_amount(elements, settings))
		return (1);
	settings->north_texture_path = ft_strdup(elements[1]);
	settings->NO = true;
	free(elements);
	return (0);
}
