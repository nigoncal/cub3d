/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:05:37 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 14:05:41 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return ((char *)s1);
	while (i < len && s1[i])
	{
		if (s1[i] == s2[j])
			j++;
		else if (s2[j] == '\0')
			return ((char *)&s1[i - j]);
		else
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	if (s2[j] == '\0')
		return ((char *)&s1[i - j]);
	return (0);
}
