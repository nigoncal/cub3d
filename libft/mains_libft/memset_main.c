/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memset_main.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/16 17:34:21 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 16:07:14 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	char	*b1;
	char	*b2;
	int		c;
	size_t	n;

	if (ac == 5)
	{
		b1 = av[1];
		b2 = av[2];
		c = atoi(av[3]);
		n = atoi(av[4]);
		printf("%s\n", ft_memset(b1, c, n));
		printf("%s\n", memset(b2, c, n));
	}
	else
		printf("need 4 args");
	return (0);
}
