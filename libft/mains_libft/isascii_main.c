/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   isalpha_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 17:24:48 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 16:48:58 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int		main(int ac, char **av)
{
	int c;

	if (ac == 2)
	{
		c = atoi(av[1]);
		printf("%d\n", ft_isascii(c));
		printf("%d\n", isascii(c));
	}
	else
		printf("need 1 arg");
	return (0);
}
