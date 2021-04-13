/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:47:23 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/06 16:50:46 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "cub3d.h"

int		map_part(char *line)
{
	static int non_empty_lines = 0;
	while (*line)
	{
		if (*line != ' ' && *line != '\n')
		{
			non_empty_lines++;
			break ;
		}
		line++;
	}
	return (non_empty_lines);
}
