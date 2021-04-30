/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:53:15 by nigoncal          #+#    #+#             */
/*   Updated: 2021/04/30 15:51:50 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static t_stat_var	s;
	int					start;

	start = s.pos;
	s.return_buff = 1;
	if (!(BUFFER_SIZE > 0 && BUFFER_SIZE <= 2147483647) || read(fd, 0, 0) < 0)
		return (-1);
	if (s.buffer == NULL)
		if (!(s.buffer = new_buffer(fd, &s.pos, &start, &s.return_buff)))
		{
			*line = ft_calloc(1, 1);
			return (0);
		}
	while (s.buffer[s.pos] != '\n' && s.buffer[s.pos] != '\0')
		s.pos++;
	if (s.buffer[s.pos] == '\n')
	{
		*line = s_tab(s.buffer, s.pos, start);
		s.pos++;
		return (s.return_buff);
	}
	*line = join_buff(start, fd, &s);
	return (s.return_buff);
}

char	*join_buff(int start, int fd, t_stat_var *s)
{
	char	*r;

	r = s_tab(s->buffer, s->pos, start);
	while (s->buffer[s->pos] == '\0' && s->return_buff != 0)
	{
		free(s->buffer);
		s->buffer = new_buffer(fd, &s->pos, &start, &s->return_buff);
		if (s->buffer == NULL)
		{
			free(s->buffer);
			return (r);
		}
		while (s->buffer[s->pos] != '\n' && s->buffer[s->pos] != '\0')
			s->pos++;
		r = ft_strjoin_g(r, s_tab(s->buffer, s->pos, start), &s->return_buff);
		if (s->return_buff == -1)
			return (NULL);
		if (s->buffer[s->pos] == '\n')
		{
			s->pos++;
			return (r);
		}
	}
	return (r);
}
