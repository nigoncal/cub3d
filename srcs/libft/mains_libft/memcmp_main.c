/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memcmp_main.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 19:19:12 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 17:01:27 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char	*s1;
	char	*s2;
	size_t	n;

	s1 = "t\200";
	s2 = "t\0";
	n = 2;
	printf("%d\n", ft_memcmp(s1, s2, n));
	printf("%d\n", memcmp(s1, s2, n));
	return (0);
}
