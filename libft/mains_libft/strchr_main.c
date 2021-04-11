/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strchr_main.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 12:27:32 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 12:30:35 by sylducam    ###    #+. /#+    ###.fr     */
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
		printf("%s\n", ft_strchr(str, c));
		printf("%s\n", strchr(str, c));
	}
	else
		printf("need 2 args");
	return (0);
}
