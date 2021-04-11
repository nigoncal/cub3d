/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_map_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 19:16:52 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 19:16:59 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>

void	del(void *content)
{
	free(content);
}

void	*lstmap_f(void *ptr)
{
	return (ft_strjoin((char*)ptr, " toto"));
}

int		main(void)
{
	t_list	*tmp = NULL;
	t_list	**lst = NULL;
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*swp;
	elem1 = ft_lstnew(ft_strdup("un"));
	elem2 = ft_lstnew(ft_strdup("deux"));
	elem3 = ft_lstnew(ft_strdup("trois"));
	lst = &elem1;
	elem1->next = elem2; // a revoir
	elem2->next = elem3; // pareil
	elem3->next = 0;
	tmp = ft_lstmap(*lst, lstmap_f, del);
	printf("before %s\n", elem1->content);
	printf("before %s\n", elem2->content);
	printf("before %s\n", elem3->content);
	printf("lst[0]->next = %p\n", lst[0]->next);
	ft_lstclear(lst, del);
	swp = tmp;
	while (tmp)
	{
		printf("after %s\n", tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&swp, del);
	return (0);
}

