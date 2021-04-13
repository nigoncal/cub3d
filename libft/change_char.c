/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:58:47 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/13 14:01:01 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"

// lis les comms des lignes

char	*change_char(char *str, char in, char out)
{
	char	*changed_str;
	int		i;

	i = 0;
	if (!str || !*str || !in || !out) // test tes !a !b et poses toi la question de quels types de char tu acceptes. Tous ?
		return (NULL);
	changed_str = ft_strdup(str); // cette ligne je ne suis pas sur qu'elle soit utile
	while (changed_str[i])
	{
		if (changed_str[i] == out)
			changed_str[i] = in;
		i++;
	}
//	free str ?
	free(str);
	return (changed_str);
}

int main()
{
	char *str;
//	char *ret;
	str = ft_strdup("	 	 Nord\vine	tab space	 \vvtab	2tab  2space	\v\v2vtab 		 ./path.xpm	tab space		2tab  2space ");
	dprintf(1, "str_ori\n|%s|\n", str);
	str = change_char(str, ' ', '\t'); // strdup avant ? malloc ? non, ca se fait dans change_char normalement avec le ft_strdup present dedans
	dprintf(1, "str_1er_passage\n|%s|\n", str);
	str = change_char(str, ' ', '\v');
	dprintf(1, "str_2e_passage\n|%s|\n", str);
	free(str);
}
