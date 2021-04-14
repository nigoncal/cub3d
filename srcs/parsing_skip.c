/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_skip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:30:06 by pmillet           #+#    #+#             */
/*   Updated: 2021/04/14 10:33:18 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char *is_line_empty(char *line)
{
	int skip;

	skip = 0;
	skip = skip_ws(line);
	while (*line != '\0' && skip > 0)
	{
		line++;
		skip--;
	}
	return (line);
}

int	skip_ws(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\v')
		{
			i++;
		}
		else
			return (i);
	}
	return (i);
}
// skip_what = 0 => skip les non digits MAIS pas les - suivis d'un chiffre
// skip_what = 1 => skip les digits et les '-'

int	skip_non_digits(char const *str, int skip_what)
{
	int	i;

	i = 0;
	if (skip_what == 1)
	{
		if (str[i] && str[i] == '-')
			i++;
	}
	while (str[i])
	{
		if (skip_what == 0 && str[i] == '-' && str[i + 1] && \
		ft_isdigit(str[i + 1]) == 1)
			return (i);
		else if (ft_isdigit(str[i]) == skip_what)
		{
			i++;
		}
		else
			return (i);
	}
	return (i);
}

/*int	skip_non_digits(char const *str, int skip_what)
{
	int i;

	i = 0;
	if (skip_what == 1)
	{
		if (str[i] && str[i] == '-')
			i++;
	}
	while (str[i] && ft_isdigit(str[i]) == skip_what)
		i++;
	return (i);
}*/