/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:04:57 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/11 11:40:27 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h> // a virer
#include <stdlib.h> // a virer

int		file_format(char *file, char *format)
{
	// penses a securiser
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
	return (0);
}

int	main()
{
	char *file;
	char *format;
	file = strdup("sylvain.jpg");
	format = strdup(".png");
	file_format(file, format);
	free(file);
	free(format);
}
