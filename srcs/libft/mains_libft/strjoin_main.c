/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strjoin_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 18:17:37 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 19:29:35 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>

int		main(void)
{
	const char *s1;
	const char *s2;

	s1 = "Bonjour tout";
	s2 = " le monde !";
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}
