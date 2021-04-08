/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:11:38 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/08 17:17:01 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h" // a ajouter dans ton header
//#include "header_cub3D.h"
#include <stdbool.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h> // a virer

// vires tous les bouts de code d'autres fichiers pour ne garder que les fonctions de ce fichier. Ils t'ont servi a tester
// fais bien attention a ce que tout fonctionne avec ton main normal et header normal (parametres des fonctions)

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

int		check_elements(char **elements, cub_settings *settings)
{
	int	i;

	i = 0;
	while (elements[i])
		i++;
	if (i != 3)
		return (0);
	i = 0;
	if (ft_strncmp(elements[0], "R", ft_strlen(elements[0])))
		return (0);
	while (elements[1][i])
		if (!(ft_isdigit(elements[1][i++])))
			return (0);
	i = 0;
	while (elements[2][i])
		if (!(ft_isdigit(elements[2][i++])))
			return (0);
	settings->R = true;
	settings->width = ft_atoi(elements[1]);
	settings->height = ft_atoi(elements[2]);
	if (settings->width <= 0 || settings->height <= 0)
		return (0);
	too_big_for_screen(settings);
	return (1);
}

void	resolution(char *line, cub_settings *settings)
{
	char **elements;

	if (settings->R == true)
		dprintf(1, "R already true\n");
	//	abort_prog(line, settings, "Identifiers should be used only once");
	elements = ft_split(line, ' ');
	if (!(check_elements(elements, settings)))
		dprintf(1, "Error\n");
	//	abort_prog(line, settings, "Resolution line not well formated. Usage :\
	//			\nR <width> <height>\nOnly positive values");
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
