/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:46:13 by pmillet           #+#    #+#             */
/*   Updated: 2021/04/29 12:31:36 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	free_2d_tab(char **tab, int l)
{
	while (tab[l] >= 0)
	{
		free(tab[l]);
		l--;
	}
	free(tab);
	return (0);
}