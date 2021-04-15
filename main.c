/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:17:28 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/15 17:53:06 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"
#include "libft/header_libft.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
//#include <stdio.h>

int	main(int argc, char **argv)
{
//	int				fd;
	int				format;
	char			*line;
	cub_settings	settings;

	line = NULL;
	ft_bzero(&settings, sizeof(cub_settings));
	format = format_check(argv[1], ".cub");
	if (argc < 2 || argc > 3 || format == 1)
		abort_prog(line, &settings, "./cub3d file.cub --save(optionnal)");
	if (argc == 3)
	{
		format = ft_strcmp(argv[2], "--save");
		if (format != 0)
		{
			ft_putstr("Error\nUsage : ./cub3d file.cub --save(optionnal)\n");
			return (0);
		}
		settings.screenshot = true;
	}
//	fd = open(argv[2], O_RDONLY);
//	start(fd, &line);
//	close(fd);
	return (0);
}
