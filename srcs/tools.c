/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:57:36 by sylducam          #+#    #+#             */
/*   Updated: 2021/03/19 13:40:22 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "header_cub3d.h"

int		ft_count_lines(int fd, int lines)
{
	char		*reader;
	int			eoread;
	
	reader = NULL;
	if ((reader = malloc(sizeof(char) * 4)) == NULL)
		return (0); // specifier erreur
	while ((eoread = read(fd, reader, 4)) > 0)
		lines += count_eol(reader);
	free(reader);
	return (lines);
}
