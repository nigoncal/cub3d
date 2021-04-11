/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strtrim_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 18:03:38 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 17:56:19 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>

int		main(void)
{
	const char *s1;
	const char *set;

	s1 = "Bonjour";
	set = "";
	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}
