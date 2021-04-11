/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lstdelone_main.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 21:30:00 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 21:30:05 by sylducam    ###    #+. /#+    ###.fr     */
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
	t_list	*elem;
	elem = ft_lstnew(strdup("test"));
	printf("%s\n", elem->content);
	ft_lstdelone(elem, del);
	printf("%s\n", elem->content);
	return (0);
}
