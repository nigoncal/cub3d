/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abort_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:17:45 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/09 14:19:12 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

// faire un bzero de toute ta structure

char	*which_path(cub_settings *settings)
{
	if (settings->path == 1)
		return ("In north texture path line. Usage : NO ./path");
	if (settings->path == 2)
		return ("In south texture path line. Usage : SO ./path");
	if (settings->path == 3)
		return ("In east texture path line. Usage : EA ./path");
	if (settings->path == 4)
		return ("In west texture path line. Usage : WE ./path");
	if (settings->path == 5)
		return ("In sprite texture path line. Usage : S ./path");
}

void	abort_all(char *line, cub_settings *settings, char *s)
{
	if (settings->path_id)
		ft_strlcat(s, (which_path(settings))); // il faut les parentheses ou pas ?
// si tu free &line, est-ce que ca free bien **line alors que tu prends *line en parametre ?
}
