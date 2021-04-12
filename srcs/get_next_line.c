/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 09:28:46 by pmillet           #+#    #+#             */
/*   Updated: 2021/01/04 12:19:53 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strjoin(char **s1, char const *s2, int limit)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(res = malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1))))
	{
		return (-1);
	}
	while (*s1 != 0 && (*s1)[i])
	{
		res[i] = (*s1)[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2 != 0 && s2[i] && i < limit)
		res[j++] = s2[i++];
	res[j] = '\0';
	free(*s1);
	*s1 = res;
	return (1);
}

int		ft_substr(char **s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;

	i = 0;
	sub = NULL;
	if (*s == NULL)
		return (-1);
	if (ft_strlen(*s) < len)
		len = ft_strlen(*s);
	if (!(sub = malloc(sizeof(char) * (len + 1))))
		return (-1);
	while ((*s)[i + start] && i < len)
	{
		sub[i] = (*s)[i + start];
		i++;
	}
	sub[i] = 0;
	free(*s);
	*s = sub;
	return (1);
}

int		transfer_line(char **current, char **line)
{
	int	i_nl;
	int	len_rest;
	int len_current;

	len_current = ft_strlen(*current);
	if ((i_nl = find_nl(*current)) == -1)
		i_nl = len_current;
	if (!(*line = malloc(sizeof(char) * (i_nl + 1))))
	{
		return (-1);
	}
	if (current == 0 || len_current == 0)
	{
		**line = 0;
		return (0);
	}
	ft_strlcpy(*line, *current, (i_nl + 1));
	if ((len_rest = len_current - i_nl) <= 0)
	{
		return (0);
	}
	return (ft_substr(current, (i_nl + 1), len_rest));
}

int		read_fd(int fd, char **current, char **line)
{
	int		status;
	char	buffer[BUFFER_SIZE + 1];

	status = 1;
	while (find_nl(*current) == -1 && status > 0)
	{
		if ((status = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[status] = '\0';
			status = ft_strjoin(current, buffer, (status + 1));
			if (status == -1)
				return (-1);
		}
	}
	if (status == -1)
		return (-1);
	status = transfer_line(current, line);
	return (status);
}

int		get_next_line(int fd, char **line)
{
	static char	*current;
	int			status;

	if (line == NULL)
		return (-1);
	if (check_args(fd) == 0)
	{
		*line = NULL;
		return (-1);
	}
	status = read_fd(fd, &current, line);
	if (status < 1 && current != NULL)
	{
		free(current);
		current = NULL;
	}
	return (status);
}
