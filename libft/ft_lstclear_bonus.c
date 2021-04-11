/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:57:26 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 13:57:30 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*delnext;
	t_list	*tmp;

	delnext = *lst;
	if (!lst || !*lst)
		return ;
	while (delnext)
	{
		tmp = delnext->next;
		ft_lstdelone(delnext, del);
		delnext = tmp;
	}
	*lst = 0;
}
