/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strnstr_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 13:26:00 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 13:30:29 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	char	*s1;
	char	*s2;
	size_t	len;

	if (ac == 4)
	{
		s1 = av[1];
		s2 = av[2];
		len = atoi(av[3]);
		printf("%s\n", ft_strnstr(s1, s2, len));
		printf("%s\n", strnstr(s1, s2, len));
	}
	else
		printf("need 3 args");
	return (0);
}
