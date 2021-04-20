/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strmapi_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 20:09:13 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 13:38:12 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>

char	f(unsigned int i, char c)
{
	c = 'x';
	i++;
	return (c);
}

int		main(int argc, char **argv)
{
	char const *s;

	if (argc == 2)
	{
		s = argv[1];
		printf("%s\n", ft_strmapi(s, f));
	}
	else
		printf("need 1 arg\n");
	return (0);
}
