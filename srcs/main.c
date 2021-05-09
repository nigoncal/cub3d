/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:17:28 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/09 15:55:20 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"

int	main(int argc, char **argv)
{
	int			fd;
	char		*line;
	t_settings	*cub_sets;

	line = NULL;
	cub_sets = malloc(sizeof(cub_sets));
	ft_bzero(cub_sets, sizeof(*cub_sets));
	if (argc < 2 || argc > 3 || (format_check(argv[1], ".cub")) == 1)
		abort_prog(line, cub_sets, "./cub3d file.cub --save(optionnal)");
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") != 0)
		{
			ft_putstr("Error\nUsage : ./cub3d file.cub --save(optionnal)\n");
			return (0);
		}
		cub_sets->screenshot = true;
	}
	fd = open(argv[1], O_RDONLY);
	start(fd, &line, cub_sets);
	close(fd);
	return (0);
}
