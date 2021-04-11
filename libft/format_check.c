/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:42:17 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/11 16:06:21 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"

int	format_check(char *file, char *format)
{
	if (file && format && *file && *format)
	{
		while (*file)
			file++;
		file -= strlen(format);
		while (*file && *format)
		{
			if (*file != *format)
				return (1);
			file++;
			format++;
		}
	}
	return (0);
}
