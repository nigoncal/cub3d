/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:02:15 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/13 18:55:42 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include "header_cub3d.h"
#include <stdbool.h>
#include "libft/header_libft.h"
#include "get_next_line/get_next_line.h" // en a-t-il besoin ?
#include <strings.h>
#include "minilibx/mlx.h" // a virer

// j'ai un segfault depuis que j'ai ajoute ret au main, ca segfault au memset de la structure, je ne comprends pas pour l'instant

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
	if (!(settings->north_fd = open(elements[1], O_RDONLY)))
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

int			north(char *line, cub_settings *settings)
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
	char *line = "  NO  38 xpm     ";
	cub_settings *settings;
//	settings = NULL;
	ft_bzero(settings, sizeof(cub_settings));
//	settings->NO = false;
	settings->mlx = mlx_init();
	ret = north(line, settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings->NO);
	dprintf(1, "north_fd = %d\n", settings->north_fd);
}
