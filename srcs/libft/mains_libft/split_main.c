/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_main.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/18 10:34:32 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 19:11:05 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char const	*s;
	char		c;
	int			i;
	char		**tab;

	i = 0;
	if (argc == 3)
	{
		s = argv[1];
		c = argv[2][0];
		tab = ft_split(s, c);
		if (s[0] != '\0')
		{
			while (tab[i])
			{
				printf("|%s|\n", tab[i]);
				i++;
			}
		}
	}
	else
		printf("need 2 args");
	return (0);
}
