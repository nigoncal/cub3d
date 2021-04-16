/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:17:28 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/16 15:35:40 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include "../libft/libft.h"
//#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
//#include <stdio.h>

int	main (int argc, char **argv)
{
	t_setup	setup;
	int		fd;

	fd = 0;
	/*init_struct(&setup);*/
	ft_bzero(&setup, sizeof(t_setup));
	if (parse_args(argc, argv, &setup) < 0)
	{
		ft_putstr_fd("Error \nParsing failed, please check your args and/or .cub file \
and try again. Keep going !\n", 0);
		return (-1);
	}
	printf("\nnb lines map : %d\n", setup.map_nb_lines);
	printf("longueur line la plus longue de la map : %d\n", setup.map_longest_line);
	if (setup.map_nb_lines > 0 && setup.map_longest_line > 0)
	{
		setup.map_size_known = 1;
		printf("\n\n EZEPARTI ok on lance le 2e GNL\n");
		fd = open(argv[argc - 1], O_RDONLY);
		open_file(&setup, fd);
	}
	//printf("normalement apres ca crash\n");
	printf("La 1e ligne du tab malloqué : [%s]\n", setup.map[0]);
	printf("La derniere ligne du tab malloqué : [%s]\n", setup.map[13]);
	//init_windows(&mini);
	//init_ray(&direction, mini);
	//assigned_vector(&sphere.origine, 0, 0, -60);
	//gen_ray(&mini, &sphere);
	//mlx_put_image_to_window(mini.mlx, mini.win, mini.image, 0, 0);
	//mlx_loop(mini.mlx);
	if (setup.map_malloced == 1)
		free(setup.map);
		//free_2d_tab(setup.map, setup.map_nb_lines);
	return (0);
}

/*
int	main(int argc, char **argv)
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
	{
		if (ft_strncmp(argv[2], "--save", 7))
		{
			ft_putstr("Error\nUsage : ./cub3D file.cub --save(optionnal)\n");
			return (0);
		}
	}
	else
	{
		// if --save
		fd = open(argv[2], O_RDONLY);
		cub3D(fd, &line);
		close(fd);
	}
	return (0);
}*/
