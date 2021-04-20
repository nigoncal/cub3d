/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strrchr_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 12:31:28 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 12:34:13 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	char	*str;
	int		c;

	if (ac == 3)
	{
		str = av[1];
		c = atoi(av[2]);
		printf("%s\n", ft_strrchr(str, c));
		printf("%s\n", strrchr(str, c));
	}
	else
		printf("need 2 args");
	return (0);
}
