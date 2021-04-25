/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:27:17 by nigoncal          #+#    #+#             */
/*   Updated: 2021/04/25 10:38:16 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


char			*ft_strjoin_g(char const *s1, char const *s2, int *return_buff)
{
	char	*tab_sortie;
	int		temp;
	int		i;
	int		l;

	i = 0;
	l = 0;
	temp = ft_strlen(s1);
	temp = temp + ft_strlen(s2);
	if (!(tab_sortie = malloc(sizeof(char) * temp + 1)))
	{
		*return_buff = -1;
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		tab_sortie[i] = s1[i];
		i++;
	}
	while (s2[l] != '\0')
		tab_sortie[i++] = s2[l++];
	tab_sortie[i] = '\0';
	free((char *)s2);
	free((char *)s1);
	return (tab_sortie);
}

char	*s_tab(char *buffer, int pos, int start)
{
	char	*tab;
	int		i;
	int		size;

	size = pos - start;
	i = 0;
	if (buffer == NULL)
		return (0);
	if (!(tab = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (start != pos)
		tab[i++] = buffer[start++];
	tab[i] = 0;
	return (tab);
}

char	*new_buffer(int fd, int *pos, int *start, int *return_buff)
{
	char	*buffer;
	int		result;

	*pos = 0;
	*start = 0;
	if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE + 1)))
	{
		*return_buff = -1;
		return (NULL);
	}
	result = read(fd, buffer, BUFFER_SIZE);
	buffer[result] = 0;
	if (result == 0)
	{
		*return_buff = 0;
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
