/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strlcpy_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 12:44:05 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 13:14:26 by sylducam    ###    #+. /#+    ###.fr     */
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
		printf("%zu\n", ft_strlcpy(dst1, src, n));
		printf("%s\n", dst1);
		printf("%lu\n", strlcpy(dst2, src, n));
		printf("%s\n", dst2);
	}
	else
		printf("need 4 args");
	return (0);
}
