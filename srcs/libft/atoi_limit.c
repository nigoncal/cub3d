/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_limit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 15:45:54 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/15 16:11:09 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// elle est eclatee, il faut vraiment que tu la fasses mieux, pour qu'elle fasse
// tout le taf elle-meme, ne comptes pas sur ce que tu fais avant dans
// p_resolution.c

// bon la la fonction est un peu courte, j'aurais aime y ajouter la verification
// des negatifs, mais c'est deja gere par ce que je fais precedemment dans 
// p_resolution.c. Sauf que la du coup elle est moins utilisable generalement,
// hors cub3d.
// On va laisser comme ca pour l'instant et puis on verra par la suite si je la
// modifie dans des projets futurs, si besoin
//
// TESTES LA avec toutes tes valeurs et surtout l'int max + 1 et puis des
// valeurs bien plus grandes

int	atoi_limit(const char *str, long limit)
{
	int	i;
	int	nb;
	int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (str[i])
	{
		if (nb < limit)
			nb = (nb * 10) + (str[i] - '0');
		else
			return (limit);
	i++;
	}
	return (nb * neg);
}
