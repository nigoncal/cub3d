/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:17:28 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/18 15:07:37 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"

int	main(int argc, char **argv)
{
	int			fd;
	char		*line;
	t_settings	*cub_sets;

	line = NULL;
	cub_sets = wrmalloc(sizeof(*cub_sets));
	if (cub_sets == NULL)
		abort_prog("Failed to malloc cub_sets structure");
	ft_bzero(cub_sets, sizeof(*cub_sets));
	if (argc < 2 || argc > 3 || (format_check(argv[1], ".cub")) == 1)
		abort_prog("./cub3d file.cub --save(optionnal)");
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") != 0)
		{
			abort_prog("./cub3d file.cub --save(optionnal)");
			return (0);
		}
		cub_sets->screenshot = true;
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 2)
		abort_prog("Error while opening the .cub file");
	start(fd, &line, cub_sets);
	printf("nb de colonnes de map/ X : %zu\n", ft_strlen(cub_sets->map[0]));
	if (find_player(cub_sets) == RAS)
	{
		printf("Pos X du player = %d\n", cub_sets->play_x);
		printf("Pos Y du player = %d\n", cub_sets->play_y);
		//printf("Si on regarde a cet emplacement de la map, on trouve '%c'\n", cub_sets->map[cub_sets->play_y][cub_sets->play_x]);
		printf("Orientation de depart du player = %c\n", cub_sets->start_orientation);
	}
	close(fd);
	return (0);
}
