/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:56:47 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 13:56:53 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"

static int	size(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*fill(unsigned int n, char *str, int size)
{
	str[size] = '\0';
	while (--size + 1)
	{
		str[size] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				len;
	unsigned int	nb;

	i = 0;
	if (n < 0)
	{
		len = size(n) + 1;
		if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		nb = n * -1;
		fill(nb, str, len);
		str[0] = '-';
	}
	else
	{
		len = size(n);
		if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		fill(n, str, len);
	}
	return (str);
}
