/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:00:37 by pmillet           #+#    #+#             */
/*   Updated: 2021/04/13 11:47:55 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		find_nl(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t i;

	if (src == NULL || dest == NULL || dstsize <= 0)
		return (0);
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (dest[i])
		dest[i] = '\0';
	return (1);
}

int		check_args(int fd)
{
	char	*buffer;

	buffer = NULL;
	if (fd < 0 || fd > OPEN_MAX || read(fd, buffer, 0) < 0 || BUFFER_SIZE < 1)
		return (0);
	return (1);
}
