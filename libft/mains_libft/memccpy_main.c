/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memccpy_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 18:58:16 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 19:05:54 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
//	char	*src = "pomme de terrex";
//	char	dst1[] = "hello world                  ";
//	char	dst2[] = "hello world                  ";
//	int		c = '\0';
//	size_t	n = 20;

//	printf("%zu\n", ft_strlen(dst1));
//	printf("%zu\n", ft_strlen(dst2));
//	printf("%s\n", ft_memccpy(dst1, src, c, n));
	//printf("%s\n", dst1);
//	printf("%s\n", memccpy(dst2, src, c, n));
	//printf("%s\n", dst2);
	//return (0);

	char	source[3];
	source[0] = 'a';
	source[1] = 'b';
	source[2] = 'c';

	char     dest[100];
	
	printf("%s %s\n", ft_memccpy(dest, source, 'c', 3), memccpy(dest, source, 'c', 3));
}
