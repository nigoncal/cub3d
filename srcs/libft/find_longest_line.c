/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_longest_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:52:40 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/09 13:57:04 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_longest_line(char **tab)
{
	int	i;
	int	j;
	int	record;

	i = 0;
	j = 0;
	record = 0;
	while (tab[i])
	{
		while (tab[i][j])
			j++;
		if (j > record)
			record = j;
		j = 0;
		i++;
	}
	return (record);
}
