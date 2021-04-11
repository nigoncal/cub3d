/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:04:17 by sylducam          #+#    #+#             */
/*   Updated: 2021/03/13 11:59:34 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"

static char	*ft_fill(char const *s1, char const *s2, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free((char*)s1);
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	return (ft_fill(s1, s2, str));
}
