/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lstnew_main.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:57:44 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 12:57:46 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"

int		main(int argc, char **argv)
{
	t_list	*elem;
	void	*str;

	if (argc == 2)
	{
		str = argv[1];
		elem = ft_lstnew(str);
		ft_putstr(elem->content);
		ft_putchar('\n');
	}
	else
		ft_putstr("need 1 arg");
	return (0);
}
