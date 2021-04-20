/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   putchar_fd_main.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 13:52:00 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 14:14:39 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	c;
	int		fd;

	if (argc == 3)
	{
		c = argv[1][0];
		fd = atoi(argv[2]);
		ft_putchar_fd(c, fd);
	}
	else
		printf("need 2 args");
	return (0);
}
