/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 09:01:58 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/16 09:04:31 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h" // a ajouter dans ton header
//#include "../header_cub3d.h"
#include <stdbool.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h> // a virer

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

void		texture(char *line, t_settings *cub_sets)
{
	int	error;

	error = 0;
	if (*line == 'N')
	{ // ce sera trop long, fais une fonction pour chaque cardinal, dans laquelle il y aura l'int error
		error = north_texture(elements, cub_sets);
		if (error == -1)
			abort_all(line, cub_sets, "Issue in north texture line. Usage : \
					NO ./path.xpm OR .png");
	}
	if (*line == 'S' && *line + 1 == 'O')
		if (south_texture(elements, cub_sets))
			abort_all(line, cub_sets, "Issue in south texture line. Usage : \
					SO ./path.xpm OR .png");
	if (*line == 'E')
		if (east_texture(elements, cub_sets));
			abort_all(line, cub_sets, "Issue in east texture line. Usage : \
					EA ./path.xpm OR .png");
	if (*line == 'W')
		if (west_texture(elements, cub_sets));
			abort_all(line, cub_sets, "Issue in west texture line. Usage : \
					WE ./path.xpm OR .png");
	if (*line == 'S')
		if (sprite_texture(elements, cub_sets));
			abort_all(line, cub_sets, "Issue in sprite texture line. Usage : \
					S ./path.xpm OR .png");
	// si ca ne rentre dans aucun des if precedents ?
	cub_sets->path_id = 0;
}

-------------------------------------------------------------------------------

	if (cub_sets->id_path == 1) // modifies le reste avec ca
		cub_sets->north_texture_path = ft_strdup(*line);
	if (type == 'S')
		cub_sets->south_texture_path = ft_strdup(*line);
	if (type == 'W')
		cub_sets->west_texture_path = ft_strdup(*line);
	if (type == 'E')
		cub_sets->east_texture_path = ft_strdup(*line);
	if (type == 's')
		cub_sets->sprite_texture_path = ft_strdup(*line);

-------------------------------------------------------------------------------
	
typedef struct	s_settings
{
	bool	R;
	int		width;
	int		height;
	void	*mlx; // si ca marche, a bien ajouter a ta structure dans le header
}				t_settings;

void	too_big_for_screen(t_settings *cub_sets)
{
	int trigger;
	int	*screen_width;
	int	*screen_height;
	
	screen_width = malloc(sizeof(int));
	screen_height = malloc(sizeof(int));
	trigger = mlx_get_screen_size(cub_sets->mlx, screen_width, screen_height);
	if (cub_sets->width > *screen_width)
		cub_sets->width = *screen_width;
	if (cub_sets->height > *screen_height)
		cub_sets->height = *screen_height;
	free(screen_width);
	free(screen_height);
}

int main()
{
//    void    *mlx; // a ajouter dans ton main a toi

//    mlx = mlx_init(); // a ajouter dans ton main a toi
	char *line = "  R  50555     20555     ";
	t_settings *cub_sets;
//	cub_sets = NULL;
	ft_bzero(cub_sets, sizeof(t_settings));
	cub_sets->R = false;
	cub_sets->width = 0;
	cub_sets->height = 0;
	cub_sets->mlx = mlx_init();
	resolution(line, cub_sets);
	dprintf(1, "R = %d\n", cub_sets->R);
	dprintf(1, "width = %d\n", cub_sets->width);
	dprintf(1, "height = %d\n", cub_sets->height);
}
