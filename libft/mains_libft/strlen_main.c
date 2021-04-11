/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strlen_main.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 11:53:36 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 12:15:08 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	char	*str;

	if (ac == 2)
	{
		str = av[1];
		printf("%zu\n", ft_strlen(str));
		printf("%lu", strlen(str));
	}
	else
		printf("need 1 arg");
	return (0);
}
