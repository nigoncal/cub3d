/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memcpy_main.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 13:49:44 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 19:33:56 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	char	*src;
	char	*dst1;
	char	*dst2;
	size_t	n;

	if (ac == 5)
	{
		dst1 = av[1];
		dst2 = av[2];
		src = av[3];
		n = atoi(av[4]);
		printf("%s\n", ft_memcpy(dst1, src, n));
		printf("%s\n", memcpy(dst2, src, n));
	}
	else
		printf("need 4 args");
	return (0);
}
