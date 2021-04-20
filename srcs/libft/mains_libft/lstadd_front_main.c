/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lstadd_front_main.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 14:18:04 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 14:18:10 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>

int		main(void)
{
	t_list	**alst;
	t_list	*new;
	t_list	*first;
	
	char *s1 = "Bonjour";
	char *s2 = "Au revoir";
	first = ft_lstnew(s1);
	new = ft_lstnew(s2);
	alst = &first;
	ft_lstadd_front(alst, new);
	printf("first->content %s\nfirst->next->content %s\n",
		first->content, first->next->content);
}
