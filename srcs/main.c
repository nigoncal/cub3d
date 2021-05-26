/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:17:28 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/26 17:35:53 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"

int	main(int argc, char **argv)
{
	int			fd;
	char		*line;
	t_setup		*setup;

	line = NULL;
	setup = wrmalloc(sizeof(*setup));
	if (setup == NULL)
		abort_prog("Failed to malloc setup structure");
	ft_bzero(setup, sizeof(*setup));
	if (argc < 2 || argc > 3 || (format_check(argv[1], ".cub")) == 1)
		abort_prog("./cub3d file.cub --save(optionnal)");
	fd = open(argv[1], O_RDONLY);
	if (fd < 2)
		abort_prog("Error while opening the .cub file");
	start(fd, &line, setup);
	close(fd);
	return (0);
}
