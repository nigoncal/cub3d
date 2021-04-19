/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char_p2p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:16:22 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/19 12:12:59 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdlib.h>


// This function frees char pointer to pointers

int		free_char_p2p(char **str)
{
	int	i;

	i = 0;
	dprintf(1, "OK\n");
	dprintf(1, "str[0] = %p\n",  str[0]);
	dprintf(1, "str[1] = %p\n",  str[1]);
	dprintf(1, "str[2] = %p\n",  str[2]);
	dprintf(1, "\n");
	if (!str || !*str)
		return (-1);
	while (*str)
	{
//	dprintf(1, "str[i] = %p\n",  &str[i]);
		free(*str);
		str++;
	}
	dprintf(1, "str[0] = %p\n",  str[0]);
	dprintf(1, "str[1] = %p\n",  str[1]);
	dprintf(1, "str[2] = %p\n",  str[2]);
	dprintf(1, "str = %p\n",  str);
	free(str);
	dprintf(1, "str = %p\n",  str);
	return (0);
}

int main()
{
	char **str = ft_split("   R   150   166   ", ' ');
//	dprintf(1, "str[0] = %p\n",  str[0]);
//	dprintf(1, "str[1] = %p\n",  str[1]);
//	dprintf(1, "str[2] = %p\n",  str[2]);
//	dprintf(1, "\n");
	free_char_p2p(str);
//	dprintf(1, "str[0] = %p\n",  str[0]);
//	dprintf(1, "str[1] = %p\n",  str[1]);
//	dprintf(1, "str[2] = %p\n",  str[2]);
}
