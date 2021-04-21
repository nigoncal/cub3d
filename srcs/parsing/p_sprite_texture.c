/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sprite_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:15:58 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/21 13:16:36 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include "../header_cub3d.h"
#include <stdbool.h>
#include "libft/header_libft.h"
#include "get_next_line/get_next_line.h" // en a-t-il besoin ?
#include <strings.h>
#include "minilibx/mlx.h" // a virer

/*
 * la fonction principale :
 *
 * verifie d'abord que l'identifiant n'a pas deja ete rencontre avec le booleen cub_sets->NO
 * split la line avec espace comme separateur
 * elle appelle right_amount qui verifie qu'il y a bien 2 elements (l'identifiant et le path)
 *
 * celle-ci appelle right_file qui verifie - que l'idenfifiant est bien "NO"
 * 										   - que le format du fichier de texture est bien .xpm ou .png via la fonction format_check qui est dans ma libft
 * 										   - que le path soit bon, que ce ne soit pas un directory que l'on essaye d'ouvrir comme fichier et que le fichier soit ouvrable, grace a deux appels d'open, un avec flag O_DIRECTORY, l'autre avec O_RDONLY
 *
 * a chaque fois s'il y a une erreur, 1 est renvoye, 0 si tout se passe bien
 * si tout s'est bien passe, le path est stocke dans cub_sets->north_texture_path et cub_sets->NO est mis a true
*/

// mets la en mode sprite

typedef struct	s_settings
{
	bool	NO;
	int		north_fd;
	char	*north_texture_path;
	void	*mlx;
}				t_settings;

static int	right_file(char **elements, t_settings *cub_sets)
{
	int	error;
	int	fd;

	error = 0;
	fd = 0;
	error = ft_strcmp(elements[0], "NO");
	if (error != 0)
		return (-1);
	error = format_check(elements[1], ".xpm");
	error += format_check(elements[1], ".png");
	if (error == -2) // - 2 veut dire que les deux formats ne correspondent pas (2 retours d'erreur). Si c'est -1 c'est ok car l'un deux match (-1 + 0).
		return (-1);
	fd = open(elements[1], O_DIRECTORY);
	cub_sets->north_fd = fd; // a virer, juste pour les test
	if (fd >= 0)
		return (-1);
	fd = open(elements[1], O_RDONLY);
	cub_sets->north_fd = fd; // a virer, juste pour les test
	if (fd < 0)
		return (-1);
	return (0);
}

static int	right_amount(char **elements, t_settings *cub_sets)
{
	int	error;

	error = 0;
	while (elements[error])
		error++;
	if (error != 2)
		return (-1);
	error = right_file(elements, cub_sets);
	if (error == -1)
		return (-1);
	return (0);
}

int			north_texture(char *line, t_cub_sets *cub_sets)
{
	int		error;
	char	**elements; // a free ?

	error = 0;
	if (cub_sets->NO == true)
		return (-1);
	elements = ft_split(line, ' ');
	error = right_amount(elements, settings);
	if (error == -1)
		return (-1);
	cub_sets->north_texture_path = ft_strdup(elements[1]);
	cub_sets->NO = true;
	free(elements);
	return (0);
}
