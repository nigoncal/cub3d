/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:17:28 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/19 13:49:03 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"

int	main(int argc, char **argv)
{
	int			fd;
	char		*line;
	t_setup		*setup;

	line = NULL;
	cub_sets = wrmalloc(sizeof(*cub_sets));
	if (cub_sets == NULL)
		abort_prog("Failed to malloc cub_sets structure");
	ft_bzero(cub_sets, sizeof(*cub_sets));
	if (argc < 2 || argc > 3 || (format_check(argv[1], ".cub")) == 1)
		abort_prog("./cub3d file.cub --save(optionnal)");
	fd = open(argv[1], O_RDONLY);
	if (fd < 2)
		abort_prog("Error while opening the .cub file");
	start(fd, &line, cub_sets);
	close(fd);
	return (0);
}
