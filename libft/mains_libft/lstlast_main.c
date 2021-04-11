/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lstlast_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 16:57:29 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 16:57:33 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>

int		main(void)
{
	t_list	*begin;
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	int		*i;
	int		*j;
	int		*k;

	i = malloc(sizeof(int));
	j = malloc(sizeof(int));
	k = malloc(sizeof(int));
	*i = 42;
	*j = 66;
	*k = 5;
	elem1 = ft_lstnew(i);
	begin = ft_lstnew(elem1);
	elem2 = ft_lstnew(j);
	elem3 = ft_lstnew(k);
	begin = elem1;
	elem1->next = elem2;
	elem2->next = elem3;
	ft_putnbr(*((int*)(begin->content)));
	ft_putchar('\n');
	begin = ft_lstlast(begin);
	ft_putnbr(*((int*)(begin->content)));
	ft_putchar('\n');
	free(i);
	free(j);
	free(k);
	free(elem1);
	free(elem2);
	free(elem3);
	return (0);
}
