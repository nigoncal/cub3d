/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lstclear_main.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 22:21:10 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 22:21:16 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>

void	del(void *content)
{
	free(content);
}

int		main(void)
{
	t_list	**lst = NULL;
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	elem1 = ft_lstnew(ft_strdup("un"));
	elem2 = ft_lstnew(ft_strdup("deux"));
	elem3 = ft_lstnew(ft_strdup("trois"));
	lst = &elem1;
	elem1->next = elem2; // a revoir
	elem2->next = elem3; // pareil
	elem3->next = 0;
	printf("before %s\n", elem1->content);
	printf("before %s\n", elem2->content);
	printf("before %s\n", elem3->content);
	printf("lst[0]->next = %p\n", lst[0]->next);
	ft_lstclear(lst, del);
/*	printf("after %s\n", elem1->content);
	printf("after %s\n", elem2->content);
	printf("after %s\n", elem3->content);
	printf("lst[0]->next = %p\n", lst[0]->next);
*/	return (0);
}
