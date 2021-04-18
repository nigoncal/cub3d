/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char_p2p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:16:22 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/18 18:48:37 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdlib.h>


// This function frees char pointer to pointers

int		free_char_p2p(char **str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (-1);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

int main()
{
	char **line = ft_split("   R   150   166   ", ' ');
	free_char_p2p(line);
}
