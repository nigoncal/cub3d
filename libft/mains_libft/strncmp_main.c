/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memcmp_main.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 19:19:12 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 18:27:11 by sylducam    ###    #+. /#+    ###.fr     */
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

	s1 = "test";
	s2 = "testss";
	n = 7;
	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", strncmp(s1, s2, n));
	return (0);
}
