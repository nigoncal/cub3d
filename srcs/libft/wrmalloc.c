/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrmalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:04:32 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/16 13:13:30 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Small wrapper for malloc purpose
**	4 functions
**	-wrgetter : protect list malloc from extern files
**	-wrmalloc : create a malloc, return ptr of the malloc.
**				fail to create malloc : destoy all malloc and return 0
**	-wrfree : free a malloc, return 1.
**				fail to find the element: return 0
**	-wrdestroy : free all malloc created by wrmalloc
*/

static t_list	**wrgetter(void)
{
	static t_list *wrm;

	return (&wrm);
}

void			*wrmalloc(unsigned long size)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (new_elem == NULL)
	{
		wrdestroy();
		return (0);
	}
	new_elem->content = malloc(size);
	if (new_elem == NULL)
	{
		wrdestroy();
		return (0);
	}
	new_elem->next = 0;
	ft_lstadd_front(wrgetter(), new_elem);
	return (new_elem->content);
}

int				wrfree(void *ptr)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;
	t_list	**wrstart;

	prev = 0;
	wrstart = wrgetter();
	current = *wrstart;
	while (current)
	{
		next = current->next;
		if (current->content == ptr)
		{
			free(ptr);
			free(current);
			if (prev)
				prev->next = next;
			else
				*wrstart = next;
			return (1);
		}
		prev = current;
		current = next;
	}
	return (0);
}

void			wrdestroy(void)
{
	t_list	*current;
	t_list	*next;
	t_list	**wrstart;

	wrstart = wrgetter();
	current = *wrstart;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*wrstart = 0;
}
