/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abort_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:17:45 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/15 14:08:34 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

// faire un bzero de toute ta structure

void	abort_all(char *line, cub_settings *settings, char *s)
{
	if (settings->path_id)
		ft_strlcat(s, (which_path(settings))); // il faut les parentheses ou pas ?
// si tu free &line, est-ce que ca free bien **line alors que tu prends *line en parametre ?
}
