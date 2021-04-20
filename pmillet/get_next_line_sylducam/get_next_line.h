/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:13:06 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/07 10:38:13 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

int				get_next_line(int fd, char **line);
int				find_eol(char *s);
int				count_eol(char *s);
char			*ft_strdup(const char *s);
char			*ft_strjoin(const char *s1, const char *s2);

# endif
#endif
