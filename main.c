/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:17:28 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/06 13:02:48 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3D.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
//#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	line = NULL;
	i = ft_strlen(argv[1]);
	i -= 4;
	if ((argc < 2 && argc > 3) && ft_strncmp(argv[1] + i, ".cub", 5))
	{
		ft_putstr("Error\nUsage : ./cub3D file.cub --save(optionnal)\n");
		return (0);
	}
	if (argc == 3)
		if (ft_strncmp(argv[2], "--save", 7))
		{
			ft_putstr("Error\nUsage : ./cub3D file.cub --save(optionnal)\n");
			return (0);
		}
	else
	{
		// if --save traitement avec non lancement du jeu, comment faire l'appel ? 
		fd = open(argv[2], O_RDONLY);
		cub3D(fd, &line);
		close(fd);
	}
	return (0);
}
