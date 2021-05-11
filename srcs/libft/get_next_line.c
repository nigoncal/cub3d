/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:12:42 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/11 11:32:42 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	update(char **line, char **buffer)
{
	int		eol;
	char	*temp;

	eol = find_eol(*buffer);
	if (eol == -1)
	{
		if (*buffer != NULL)
			*line = gnl_strdup(*buffer);
		else
			*line = gnl_strdup("");
		free(*buffer);
		*buffer = NULL;
		return (0);
	}
	(*buffer)[eol] = '\0';
	*line = gnl_strdup(*buffer);
	temp = *buffer;
	*buffer = gnl_strdup(&(*buffer)[eol + 1]);
	free(temp);
	temp = NULL;
	return (1);
}

/*int				get_next_line(int fd, char **line)
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
		buffer = gnl_strjoin(buffer, reader);
	}
	free(reader);
	reader = NULL;
	if (eoread == -1)
		return (-1);
	return (update(line, &buffer));
}*/

static 	int	still_line(char *buffer, int *eoread, char *reader, int fd)
{
	*eoread = read(fd, reader, BUFFER_SIZE);
	if (find_eol(buffer) == -1)
		if (*eoread > 0)
			return (0);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*buffer;
	char		*reader;
	int			eoread;

	reader = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line || fd < 0 || BUFFER_SIZE <= 0 || reader == NULL)
		return (-1);
	while (still_line(buffer, &eoread, reader, fd) == 0)
	{
		reader[eoread] = '\0';
		buffer = gnl_strjoin(buffer, reader);
	}
	free(reader);
	reader = NULL;
	if (eoread == -1)
		return (-1);
	return (update(line, &buffer));
}
