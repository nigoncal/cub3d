/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:17:28 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/11 16:17:46 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	main (int argc, char **argv)
{
	t_setup	setup;
	int		fd;

	fd = 0;
	ft_bzero(&setup, sizeof(t_setup));
	ft_bzero(&setup.ids, sizeof(setup.ids));
	if (parse_args(argc, argv, &setup) < 0)
	{
		ft_putstr_fd("Error\nParsing failed, please check your args and/or .cub file \
and try again. Keep going !\n", 0);
		return (-1);
	}
	printf("\n1ere line map : %d\n", setup.map.start_line);
	printf("longueur line la plus longue de la map : %d\n", setup.map.longest_line);
	if (/*setup.map.nb_lines > 0 && */setup.map.longest_line > 0 && setup.map.start_line > 0)
	{
		setup.map.size_known = 1;
		printf("\n\n EZEPARTI ok on lance le 2e GNL\n");
		fd = open(argv[1], O_RDONLY);
		if (fd > 1)
		{
			open_file(&setup, fd);
		}
		else
			printf("Error\nProblem with your .cub while working with it.\n");
	}
			printf("\n\n BLOP\n");
	//printf("normalement apres ca crash\n");
	printf("La 1e ligne du tab malloqué : [%s]\n", setup.map.map[0]);
	printf("La 14e ligne du tab malloqué : [%s]\n", setup.map.map[5]);
	//init_windows(&mini);
	//init_ray(&direction, mini);
	//assigned_vector(&sphere.origine, 0, 0, -60);
	//gen_ray(&mini, &sphere);
	//mlx_put_image_to_window(mini.mlx, mini.win, mini.image, 0, 0);
	//mlx_loop(mini.mlx);
	if (setup.map.malloced == 1)
	{
		//free_2d_tab(setup.map, setup.map_nb_lines + 1);
		free(setup.map.map);
	}
	return (0);
}
