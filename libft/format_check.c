/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:57:13 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/13 18:36:25 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"

int	format_check(char *file, char *format)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (file && format && *file && *format)
	{
		while (file[i])
			i++;
		i -= strlen(format);
		while (file[i] && format[j])
		{
			if (file[i] != format[j])
				return (1);
			i++;
			j++;
		}
	}
	return (0);
}
