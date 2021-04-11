/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:06:47 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 14:06:51 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	a;
	int		i;

	str = (char *)s;
	a = c;
	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == a)
			return (&str[i]);
		i--;
	}
	return (0);
}
