/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abort_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:52:37 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/17 18:50:01 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"
#include "libft/header_libft.h"
#include "get_next_line/get_next_line.h"

// faire un bzero de toute ta structure

void	abort_prog(char *line, t_settings *cub_sets, char *s)
{
//	if (errno)
	ft_putstr("Error\n");
	ft_putstr(s);
//	perror("Error\nUsage ");
	free(line);
	free(cub_sets);
	exit(1);
}
