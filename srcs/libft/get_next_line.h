/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:30:05 by nigoncal          #+#    #+#             */
/*   Updated: 2021/04/25 14:33:27 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4 

# include <stdlib.h>
# include <unistd.h>
#include "libft.h"

int				get_next_line(int fd, char **line);
char			*ft_strjoin_g(char const *s1, char const *s2, int *return_buff);
char			*new_buffer(int fd, int *pos, int *start, int *return_buff);
char			*s_tab(char *buffer, int pos, int start);

typedef	struct	s_stat_var
{
	char		*buffer;
	int			pos;
	int			return_buff;
}				t_stat_var;

char			*join_buff(int start, int fd, t_stat_var *s);
#endif
#endif