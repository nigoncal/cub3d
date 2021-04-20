/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   putstr_fd_main.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 14:19:08 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 15:15:35 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*s;
	int		fd;

	if (argc == 3)
	{
		s = argv[1];
		fd = atoi(argv[2]);
		ft_putendl_fd(s, fd);
	}
	else
		printf("need 2 args");
	return (0);
}
