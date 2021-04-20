/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   itoa_main.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/24 14:29:06 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/24 17:13:15 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int n;

	if (argc == 2)
	{
		n = atoi(argv[1]);
		printf("%s\n", ft_itoa(n));
	}
	else
		printf("need 1 arg");
	return (0);
}
