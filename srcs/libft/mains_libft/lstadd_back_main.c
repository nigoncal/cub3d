/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lstadd_back_main.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 15:37:49 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 15:38:00 by sylducam    ###    #+. /#+    ###.fr     */
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
	t_list	*second;	
	char *s1 = "debut";
	char *s2 = "milieu";
	char *s3 = "fin";

	first = ft_lstnew(s1);
	second = ft_lstnew(s2);
	new = ft_lstnew(s3);
	alst = &first;
	first = second;
	second->next = 0;
	printf("first->content %s\nsecond->content %s\nthird->content %s\n", alst[0]->content,
		alst[1]->content, alst[2]->content);
	ft_lstadd_back(alst, new);
	printf("first->content %s\nsecond->content %s\nthird->content %s\n", alst[0]->content,
		alst[1]->content, alst[2]->content);
	return (0);
}
