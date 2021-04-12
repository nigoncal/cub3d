/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:58:47 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/12 13:14:00 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"

//ok le probleme c'est que vu que tu fais avancer le pointeur, a la fin ca return une s sur le dernier char. Donc soit tu trouves comment faire, soit tu utilises un index

char	*change_char(char *s, char a, char b)
{
	char	*changed_s;
	int		i;

	i = 0;
	if (!s || !*s || !a || !b) // test tes !a !b et poses toi la question de quels types de char tu acceptes. Tous ?
		return (NULL);
	changed_s = ft_strdup(s); // cette ligne je ne suis pas sur qu'elle soit utile
	while (changed_s[i])
	{
		if (changed_s[i] == a)
			changed_s[i] = b;
		i++;
	}
//	free s ?
	return (changed_s);
}

/*char	*change_char(char *s, char a, char b)
{
	char *changed_s;

	if (!s || !*s || !a || !b) // test tes !a !b et poses toi la question de quels types de char tu acceptes. Tous ?
		return (NULL);
	changed_s = ft_strdup(s); // cette ligne je ne suis pas sur qu'elle soit utile
	while (*changed_s)
	{
		if (*changed_s == a)
			*changed_s = b;
		changed_s++;
	}
//	free s ?
	return (changed_s);
}*/

int main()
{
	char *s;
	char *ret;
	s = ft_strdup("	 	 Nordine	tab space		2tab  2space	 		 ./path.xpm	tab space		2tab  2space ");
	ret = change_char(s, '\t', ' '); // strdup avant ? malloc ? non, ca se fait dans change_char normalement avec le ft_strdup present dedans
	dprintf(1, "ret = |%s|\n", ret);
}
