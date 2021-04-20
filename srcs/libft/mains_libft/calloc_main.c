/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calloc_main.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 18:13:09 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 14:32:36 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	size_t	i;
	char	*mem;

	i = 0;
	mem = ft_calloc(42 * 3, 4);
	while (i <= 300)
	{
		printf("%d ", mem[i]);
		i++;
	}
	printf("\n");
	return (0);
}
