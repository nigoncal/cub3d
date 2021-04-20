/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memmove_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 19:08:17 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 19:11:27 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char	*src;
	char	*dst1;
	char	*dst2;
	size_t	n;

	if (ac == 5)
	{
		src = av[3];
		dst1 = av[1];
		dst2 = av[2];
		n = atoi(av[4]);
		printf("%s\n", ft_memmove(dst1, src, n));
		printf("%s\n", memmove(dst2, src, n));
	}
	else
		printf("need 4 args");
	return (0);
char *src = "ssalut";
char dst[] = "salut";
size_t n = 6;
printf("sylducam : %s\n", ft_memmove(dst, src, n));
printf("jdel : %s\n", ft_memmove_jdel(dst, src, n));
printf("original : %s\n", memmove(dst, src, n));
}
