/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:17:28 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/27 13:24:48 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_info		*info;
	int			fd;
	char		*line;

	line = NULL;
	info = wrmalloc(sizeof(*info));
	if (info == NULL)
		abort_prog("Failed to malloc info structure");
	ft_bzero(info, sizeof(*info));
	if (argc != 2 || (format_check(argv[1], ".cub")) == -1)
		abort_prog("Launch the program as follows\n./cub3d file.cub");
	fd = open(argv[1], O_RDONLY);
	if (fd < 2)
		abort_prog("While opening the .cub file");
	start(fd, &line, info);
	/* commenter la ligne suivante pour travailler tranquillement sur le parsing */
	graph_main(info);
	wrdestroy();
	close(fd);
	return (0);
}
