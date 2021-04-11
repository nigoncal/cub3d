/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memcpy_main.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 13:49:44 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 19:19:52 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	char		*dst;

	if (ac == 2)
	{
		dst = av[1];
		printf("%d\n", ft_atoi(dst));
		printf("%d\n", atoi(dst));
	}
	else
		printf("need 1 arg");
	return (0);
}
