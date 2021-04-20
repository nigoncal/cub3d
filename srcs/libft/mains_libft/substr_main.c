/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   substr_main.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 18:19:34 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 19:59:50 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>

int		main(void)
{
	char const		*s;
	unsigned int	start;
	size_t			len;

	s = "lorem ipsum dolor sit amet";
	start = 400;
	len = 20;
	printf("%s\n", ft_substr(s, start, len));
	return (0);
}
