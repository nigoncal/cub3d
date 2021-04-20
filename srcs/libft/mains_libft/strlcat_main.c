/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strlcpy_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 12:44:05 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 22:02:25 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char	*src;
	char	dst1[100];
	char	dst2[100];
	size_t	n;

	dst1 = "Bonjour tout le monde";
	dst2 = "Bonjour tout le monde";
	src = "xaxaxa";
	n = 50;
	printf("%zu\n", ft_strlcat(dst1, src, n));
	printf("%s\n", dst1);
	printf("%lu\n", strlcat(dst2, src, n));
	printf("%s\n", dst2);
	return (0);
}
