/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lstsize_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 23:24:37 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 23:24:46 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>

int		main(void)
{
	t_list	*lst;
	t_list	elem1;
	t_list	elem2;
	t_list	elem3;
	t_list	elem4;

	lst = ft_lstnew("42");
	lst->next = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &elem4;
	elem4.next = 0;
	ft_putnbr(ft_lstsize(lst));
	return (0);
}
