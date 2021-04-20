/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memchr.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 19:12:40 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 19:17:23 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	char	*str;
	int		c;
	size_t	n;

	if (ac == 4)
	{
		str = av[1];
		c = atoi(av[2]);
		n = atoi(av[3]);
		printf("%s\n", ft_memchr(str, c, n));
		printf("%s\n", memchr(str, c, n));
	}
	else
		printf("need 3 args");
	return (0);
}
