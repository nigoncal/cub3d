/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strdup_main.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 21:41:53 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 22:00:01 by sylducam    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header_libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char *s1;

	s1 = "Bonjour tout le monde !";
	printf("%s\n", ft_strdup(s1));
	printf("%s\n", strdup(s1));
	return (0);
}
