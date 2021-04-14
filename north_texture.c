/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north_texture.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:02:15 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/14 12:47:58 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include "header_cub3d.h"
#include <stdbool.h>
#include "libft/header_libft.h"
#include "get_next_line/get_next_line.h" // en a-t-il besoin ?
#include <strings.h>
#include "minilibx/mlx.h" // a virer

/*
 *
 *
 *
 *
 *
 *
 *
*/


// tu es en train de faire une serie de tests et particulierement, conrpendre les retours d'open car il y a un probleme avec le test 8 je crois
// testes avec un directory.xpm ou .png Pauline dit qu'il faut faire deux open pour regler ce souci

typedef struct	s_settings
{
	bool	NO;
	int		north_fd;
	void	*mlx; // si ca marche, a bien ajouter a ta structure dans le header
}				cub_settings;

/*static int	right_format(char *file, char *format)
{
	if (file && format && *file && *format)
	{
		while (*file)
			file++;
		file -= strlen(format);
		while (*file && *format)
		{
			if (*file != *format)
				return (1);
			file++;
			format++;
		}
	}
	return (0);
}*/

static int	right_file(char **elements, cub_settings *settings)
{
	if (ft_strcmp(elements[0], "NO")) // ok niveau parentheses ? trop ?
		return (1);
	if (((format_check(elements[1], ".xpm")) +
			(format_check(elements[1], ".png"))) == 2) // formulation un peu bizarre mais ca ne marchait pas avec && ou juste +. 2 veut dire que les deux formats ne correspondent pas (2 retours d'erreur). Si c'est 1 c'est ok car l'un deux match.
		return (1);
	if ((settings->north_fd = open(elements[1], O_RDONLY)) < 1)
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
	settings->NO = true;
	free(elements);
	return (0);
}

int main()
{
//    void    *mlx; // a ajouter dans ton main a toi

//    mlx = mlx_init(); // a ajouter dans ton main a toi
	int ret = 0;
//	char *line = "NO    ./textures/grass.xpm    ./textures/stone.png    ";
	cub_settings settings;
//	settings.NO = false;
	settings.mlx = mlx_init();
/*	dprintf(1, "--- test 1 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("N     ./././     ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);
	dprintf(1, "--- test 2 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("NO    textures/grass.xpm    ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);
	dprintf(1, "--- test 3 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("NO    38     xpm    ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);
	dprintf(1, "--- test 4 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("NO   38   textures/stone.png   ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);
	dprintf(1, "--- test 5 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("NO   ./textures/stone.png   ./textures/grass.xpm    ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);
	dprintf(1, "--- test 6 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("NO    ./textures/file.txt    ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);*/
	dprintf(1, "--- test 7 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("NO    ./textures./grass.xpm    ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);
/*	dprintf(1, "--- test 8 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("NOrdine    ./textures./grass.xpm    ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);*/
}
