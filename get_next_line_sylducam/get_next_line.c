/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:12:42 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/07 11:11:46 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
//#include <stdio.h> // a virer

static int		update(char **line, char **buffer)
{
	int		eol;
	char	*temp;

	eol = find_eol(*buffer);
	if (eol == -1)
	{
		if (*buffer != NULL)
			*line = ft_strdup(*buffer);
		else
			*line = ft_strdup("");
		free(*buffer);
		*buffer = NULL;
		return (0);
	}
	(*buffer)[eol] = '\0';
	*line = ft_strdup(*buffer);
	temp = *buffer;
	*buffer = ft_strdup(&(*buffer)[eol + 1]);
	free(temp);
	temp = NULL;
	//dprintf(1, "gnl update\nline = |%s|\n", *line); // a virer
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*buffer;
	char		*reader;
	int			eoread;

	reader = NULL;
	if (!line || fd < 0 || BUFFER_SIZE <= 0
			|| ((reader = malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL))
		return (-1);
	while (find_eol(buffer) == -1
			&& (eoread = read(fd, reader, BUFFER_SIZE)) > 0)
	{
		reader[eoread] = '\0';
		buffer = ft_strjoin(buffer, reader);
	}
	free(reader);
	reader = NULL;
	if (eoread == -1)
		return (-1);
	return (update(line, &buffer));
}