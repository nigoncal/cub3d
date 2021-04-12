/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 08:38:37 by pmillet           #+#    #+#             */
/*   Updated: 2021/03/20 09:22:34 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	word_count(char *s, char c)
{
	int		i;
	int		wcount;

	i = 0;
	wcount = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == 0 && wcount == 0)
			return (0);
		if (s[i] != c && s[i])
		{
			wcount += 1;
			while (s[i] != c && s[i])
			{
				i++;
			}
		}
	}
	return (wcount);
}

static int	free_2d_tab(char **tab, int l)
{
	while (tab[l] >= 0)
	{
		free(tab[l]);
		l--;
	}
	free(tab);
	return (0);
}

static char	**fill_tab(char *s, char **tab, char c)
{
	int	i;
	int	l;
	int	start;

	l = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (start != i)
		{
			tab[l] = ft_substr(s, start, (i - start));
			if (tab[l] == NULL)
			{
				free_2d_tab(tab, l);
				return (NULL);
			}
			l++;
		}
	}
	tab[l] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
	{
		tab = malloc(sizeof(char *));
		if (tab == NULL)
			return (NULL);
		tab[0] = NULL;
		return (tab);
	}
	tab = malloc(sizeof(char *) * ((word_count((char *)s, c)) + 1));
	if (tab == NULL)
		return (NULL);
	return (fill_tab((char *)s, tab, c));
}
