/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:58:24 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 13:58:29 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**alst;
	t_list	*tmp;
	t_list	*test;

	if (!lst || !f || !*f)
		return (NULL);
	tmp = NULL;
	alst = &tmp;
	while (lst)
		if ((test = ft_lstnew(f(lst->content))) == NULL)
		{
			ft_lstclear(alst, del);
			return (NULL);
		}
		else
		{
			ft_lstadd_back(alst, test);
			lst = lst->next;
		}
	return (*alst);
}
