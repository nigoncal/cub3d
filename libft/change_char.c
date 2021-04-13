/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:58:47 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/13 17:03:07 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"

char	*change_char(char *str, char in, char out)
{
	char	*changed_str;
	int		i;

	i = 0;
	if (!str || !*str || !in || !out)
		return (NULL);
	changed_str = ft_strdup(str);
	while (changed_str[i])
	{
		if (changed_str[i] == out)
			changed_str[i] = in;
		i++;
	}
	free(str);
	return (changed_str);
}
