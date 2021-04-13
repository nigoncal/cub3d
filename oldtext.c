/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:24:57 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/12 09:35:06 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h" // a ajouter dans ton header
//#include "header_cub3d.h"
#include <stdbool.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h> // a virer

// reprends tout et fait une fonction par path (north, south...), donc les memes principes que tu utilises la mais pas regroupes en une fonction, divises en 5. Tu pourras plus facilement verifier les bool et les passer en true. Tu pourras aussi plus facilement envoyer les erreurs justes, reliees aux bonnes lignes.

//	abort_prog(line, settings, "Identifiers should be used only once");

// une mini fonction pour le type de texure qui renvoie a la grande N,S,E,W ou s
	if (settings->R == true)

static int	check_everything(cub_settings *settings, char **elements)
{
	if (settings->path_id == 1)
		return ((ft_strncmp(elements[0], "NO", ft_strlen(elements[0]))) +
				(settings->north_fd = open(elements[1], O_RDONLY)));
	if (settings->path_id == 2)
		return ((ft_strncmp(elements[0]), "SO", ft_strlen(elements[0])) +
				(settings->south_fd = open(elements[1], O_RDONLY)));
	if (settings->path_id == 3)
		return ((ft_strncmp(elements[0]), "WE", ft_strlen(elements[0])) +
				(settings->west_fd = open(elements[1], O_RDONLY)));
	if (settings->path_id == 4)
		return ((ft_strncmp(elements[0]), "EA", ft_strlen(elements[0])) +
				(settings->east_fd = open(elements[1], O_RDONLY)));
	if (settings->path_id == 5)
		return ((ft_strncmp(elements[0]), "S", ft_strlen(elements[0])) +
				(settings->sprite_fd = open(elements[1], O_RDONLY)));
	return (0);
}

static void	check_elements(char **elements, cub_settings *settings)
{
	int	i;

	i = 0;
	while (elements[i])
		i++;
	if (i != 2)
		return (1);
	if (check_everything(settings, elements))
		return (1);
	set_bool_true(cub_settings *settings, char **elements);
	return (0);
}

void		texture(char *line, cub_settings *settings)
{
	if (*line == 'N')
		if (north(elements, settings))
			abort_all(line, settings, "Issue in north texture line. Usage : \
					NO ./path.xpm OR .png");
	if (*line == 'S' && *line + 1 == 'O')
		if (south(elements, settings))
			abort_all(line, settings, "Issue in south texture line. Usage : \
					SO ./path.xpm OR .png");
	if (*line == 'E')
		if (east(elements, settings));
			abort_all(line, settings, "Issue in east texture line. Usage : \
					EA ./path.xpm OR .png");
	if (*line == 'W')
		if (west(elements, settings));
			abort_all(line, settings, "Issue in west texture line. Usage : \
					WE ./path.xpm OR .png");
	if (*line == 'S')
		if (sprite(elements, settings));
			abort_all(line, settings, "Issue in sprite texture line. Usage : \
					S ./path.xpm OR .png");
	// si ca ne rentre dans aucun des if precedents ?
	settings->path_id = 0;
}

-------------------------------------------------------------------------------

	if (settings->id_path == 1) // modifies le reste avec ca
		settings->north_texture_path = ft_strdup(*line);
	if (type == 'S')
		settings->south_texture_path = ft_strdup(*line);
	if (type == 'W')
		settings->west_texture_path = ft_strdup(*line);
	if (type == 'E')
		settings->east_texture_path = ft_strdup(*line);
	if (type == 's')
		settings->sprite_texture_path = ft_strdup(*line);

-------------------------------------------------------------------------------
	
typedef struct	s_settings
{
	bool	R;
	int		width;
	int		height;
	void	*mlx; // si ca marche, a bien ajouter a ta structure dans le header
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

int main()
{
//    void    *mlx; // a ajouter dans ton main a toi

//    mlx = mlx_init(); // a ajouter dans ton main a toi
	char *line = "  R  50555     20555     ";
	cub_settings *settings;
//	settings = NULL;
	ft_bzero(settings, sizeof(cub_settings));
	settings->R = false;
	settings->width = 0;
	settings->height = 0;
	settings->mlx = mlx_init();
	resolution(line, settings);
	dprintf(1, "R = %d\n", settings->R);
	dprintf(1, "width = %d\n", settings->width);
	dprintf(1, "height = %d\n", settings->height);
}
