/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_east_texture.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:02:15 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/21 17:35:14 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include "../header_cub3d.h"
#include <stdbool.h>
#include "../libft/header_libft.h"
#include "../get_next_line/get_next_line.h" // en a-t-il besoin ?
#include <strings.h>
#include "../minilibx/mlx.h" // a virer

/*
 * la fonction principale :
 *
 * verifie d'abord que l'identifiant n'a pas deja ete rencontre avec le booleen cub_sets->EA
 * split la line avec espace comme separateur
 * elle appelle right_amount qui verifie qu'il y a bien 2 elements (l'identifiant et le path)
 *
 * celle-ci appelle right_file qui verifie - que l'idenfifiant est bien "EA"
 * 										   - que le format du fichier de texture est bien .xpm ou .png via la fonction format_check qui est dans ma libft
 * 										   - que le path soit bon, que ce ne soit pas un directory que l'on essaye d'ouvrir comme fichier et que le fichier soit ouvrable, grace a deux appels d'open, un avec flag O_DIRECTORY, l'autre avec O_RDONLY
 *
 * a chaque fois s'il y a une erreur, 1 est renvoye, 0 si tout se passe bien
 * si tout s'est bien passe, le path est stocke dans cub_sets->east_texture_path et cub_sets->EA est mis a true
*/

typedef struct	s_settings
{
	bool	EA;
	int		east_fd;
	char	*east_texture_path;
	void	*mlx;
}				t_settings;

static int	right_file(char **elements, t_settings *cub_sets)
{
	int	fd;

	fd = 0;
	if (ft_strcmp(elements[0], "EA") != 0)
		return (-1);
	if ((format_check(elements[1], ".xpm")) +
			(format_check(elements[1], ".png")) == -2) // - 2 veut dire que les deux formats ne correspondent pas (2 retours d'erreur). Si c'est -1 c'est ok car l'un deux match (-1 + 0).
		return (-1);
	fd = open(elements[1], O_DIRECTORY);
	cub_sets->east_fd = fd; // a virer, juste pour les test
	if (fd >= 0)
		return (-1);
	fd = open(elements[1], O_RDONLY);
	cub_sets->east_fd = fd; // a virer, juste pour les test
	if (fd < 0)
		return (-1);
	return (0);
}

static int	right_amount(char **elements, t_settings *cub_sets)
{
	int	i;

	i = 0;
	while (elements[i])
		i++;
	if (i != 2)
		return (-1);
	if (right_file(elements, cub_sets) == -1)
		return (-1);
	return (0);
}

int			east_texture(char *line, t_settings *cub_sets)
{
	char	**elements; // a free ?

	if (cub_sets->EA == true)
		return (-1);
	elements = ft_split(line, ' ');
	if (right_amount(elements, cub_sets) == -1)
		return (-1);
	cub_sets->east_texture_path = ft_strdup(elements[1]);
	cub_sets->EA = true;
	free(elements);
	return (0);
}