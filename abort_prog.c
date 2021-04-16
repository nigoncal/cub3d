/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abort_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:52:37 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/15 17:53:15 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"
#include "libft/header_libft.h"
#include "get_next_line/get_next_line.h"

// faire un bzero de toute ta structure

void	abort_prog(char *line, t_settings *cub_sets, char *s)
{
	int	atexit_ret;

	atexit_ret = 0;
	fprintf(stderr, "%s\n", s);
	atexit_ret += atexit((*free)(line));
	atexit_ret += atexit((*free)(cub_sets));
	perror("Error\nUsage ");
	exit(atexit_ret);
}
