/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:59:32 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 13:59:38 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"

void	*ft_memmove(void *dst, const void *source, size_t len)
{
	unsigned char	*dest;
	unsigned char	*src;

	if (!dst && !source)
		return (NULL);
	dest = (unsigned char *)dst;
	src = (unsigned char *)source;
	if (dest < src)
	{
		return (ft_memcpy(dst, source, len));
	}
	while (len--)
		dest[len] = src[len];
	return (dst);
}
