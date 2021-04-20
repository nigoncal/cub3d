/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:13:06 by sylducam          #+#    #+#             */
/*   Updated: 2021/03/15 15:08:07 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/header_libft.h"

int				get_next_line(int fd, char **line);
int				find_eol(char *s);
int				count_eol(char *s);
char			*ft_strdup(const char *s);
char			*ft_strjoin(const char *s1, const char *s2);

#endif
