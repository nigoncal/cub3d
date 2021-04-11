/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:08:15 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 14:08:19 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;
	size_t	i;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	str_len = ft_strlen(s) - start;
	if (len < str_len)
		str_len = len;
	i = 0;
	if ((str = malloc(sizeof(char) * (str_len + 1))) == NULL)
		return (NULL);
	if ((size_t)start <= ft_strlen(s))
		while (str_len-- && s[start])
			str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
