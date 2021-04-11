/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bzero_main.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 16:10:40 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 16:34:32 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	char	*s1;
	char	*s2;
	size_t	n;

	if (ac == 4)
	{
		s1 = av[1];
		s2 = av[2];
		n = atoi(av[3]);
		ft_bzero(s1, n);
		printf("%s\n", s1);
		bzero(s2, n);
		printf("%s\n", s2);
	}
	else
		printf("need 3 args");
	return (0);
}
