/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 09:01:58 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/25 13:25:40 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

// reprends tout et fait une fonction par path (north, south...), donc les memes principes que tu utilises la mais pas regroupes en une fonction, divises en 5. Tu pourras plus facilement verifier les bool et les passer en true. Tu pourras aussi plus facilement envoyer les erreurs justes, reliees aux bonnes lignes.

//	abort_prog(line, cub_sets, "Identifiers should be used only once");

// une mini fonction pour le type de texure qui renvoie a la grande N,S,E,W ou s
	if (cub_sets->R == true)

static int	check_everything(t_settings *cub_sets, char **elements)
{
	if (cub_sets->path_id == 1)
		return ((ft_strncmp(elements[0], "NO", ft_strlen(elements[0]))) +
				(cub_sets->north_fd = open(elements[1], O_RDONLY)));
	if (cub_sets->path_id == 2)
		return ((ft_strncmp(elements[0]), "SO", ft_strlen(elements[0])) +
				(cub_sets->south_fd = open(elements[1], O_RDONLY)));
	if (cub_sets->path_id == 3)
		return ((ft_strncmp(elements[0]), "WE", ft_strlen(elements[0])) +
				(cub_sets->west_fd = open(elements[1], O_RDONLY)));
	if (cub_sets->path_id == 4)
		return ((ft_strncmp(elements[0]), "EA", ft_strlen(elements[0])) +
				(cub_sets->east_fd = open(elements[1], O_RDONLY)));
	if (cub_sets->path_id == 5)
		return ((ft_strncmp(elements[0]), "S", ft_strlen(elements[0])) +
				(cub_sets->sprite_fd = open(elements[1], O_RDONLY)));
	return (0);
}

static void	check_elements(char **elements, t_settings *cub_sets)
{
	int	i;

	i = 0;
	while (elements[i])
		i++;
	if (i != 2)
		return (1);
	if (check_everything(cub_sets, elements))
		return (1);
	set_bool_true(t_settings *cub_sets, char **elements);
	return (0);
}

void		p_textures(char *line, t_settings *cub_sets)
{
	if (*line == 'N')
		if ((north_texture(elements, cub_sets) == -1)
			abort_prog(line, cub_sets, "North line : NO ./path.xpm OR .png");
	if (*line == 'S' && *line + 1 == 'O')
		if ((south_texture(elements, cub_sets)) == -1)
			abort_prog(line, cub_sets, "South line : SO ./path.xpm OR .png");
	if (*line == 'E')
		if ((east_texture(elements, cub_sets)) == -1);
			abort_prog(line, cub_sets, "East line : EA ./path.xpm OR .png");
	if (*line == 'W')
		if ((west_texture(elements, cub_sets)) == -1);
			abort_prog(line, cub_sets, "West line : WE ./path.xpm OR .png");
	if (*line == 'S')
		if ((sprite_texture(elements, cub_sets)) == -1);
			abort_prog(line, cub_sets, "Sprite line : S ./path.xpm OR .png");
}
