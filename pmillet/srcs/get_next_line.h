/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:11:49 by pmillet           #+#    #+#             */
/*   Updated: 2021/04/13 11:57:53 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 64

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

size_t		ft_strlen_gnl(const char *s);
int			find_nl(const char *s);
size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize);
int			check_args(int fd);
int			transfer_line(char **current, char **line);
int			read_fd(int fd, char **current, char **line);
int			get_next_line(int fd, char **line);

#endif
