/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   isalpha_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 17:24:48 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 17:24:56 by sylducam    ###    #+. /#+    ###.fr     */
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
		printf("%d\n", ft_isalpha(c));
		printf("%d\n", isalpha(c));
	}
	else
		printf("need 1 arg");
	return (0);
}
