#include "../cub3D.h"

// skip_what = 0 => skip les non digits MAIS pas les - suivis d'un chiffre
// skip_what = 1 => skip les digits et les '-'

int	skip_non_digits(char const *str, int skip_what)
{
	int	i;

	i = 0;
	if (skip_what == 1)
	{
		if (str[i] && str[i] == '-')
			i++;
	}
	while (str[i])
	{
		if (skip_what == 0 && str[i] == '-' && str[i + 1] && \
		ft_isdigit(str[i + 1]) == 1)
			return (i);
		else if (ft_isdigit(str[i]) == skip_what)
		{
			i++;
		}
		else
			return (i);
	}
	return (i);
}

/*int	skip_non_digits(char const *str, int skip_what)
{
	int i;

	i = 0;
	if (skip_what == 1)
	{
		if (str[i] && str[i] == '-')
			i++;
	}
	while (str[i] && ft_isdigit(str[i]) == skip_what)
		i++;
	return (i);
}*/

int	ft_nblen(double value)
{
	int	i;

	i = 0;
	while (value > 1)
	{
		value /= 10;
		i++;
	}
	return (i);
}

size_t	ft_atoi_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '-'))
	{
		i++;
	}
	return (i);
}

double	ft_pow(double power, double value)
{
	while (power > 1)
	{
		value *= value;
		power--;
	}
	return (value);
}

//on doit lui envoyer str avec str[0] etant le debut du chiffre !
double	ft_atof(char *str)
{
	double	ent;
	double	dec;
	size_t	i;
	int		neg;

	//on fait un atoi pour la partie unité
	ent = ft_atoi(str);
	//printf("%f\n", ent);
	//printf("Taille de la str du nbr : %zu\n", ft_atoi_len(str));
	neg = 0;
	//si l'unité = 0, on repart a str[0] et on verif qu'il n'y ait pas de - apres ??
	if (ent == 0)
	{
		i = 0;
		while (str[i] && i < ft_atoi_len(str))
		{
			if (str[i++] == '-')
				neg++;
		}
	}
	//on bouge le debut de str a la fin de l'unité
	str += ft_atoi_len(str);
	//printf("QQCH CLOCHE PAR LA : [%s]\n", str);
	//si on tombe pas sur un '.', c'est qu'il n'y a pas de virgule
	if (*str != '.')
		return (ent);
	// si on tombe sur un '.', on passe et on stock le chiffre des virgules dans dec
	dec = ft_atoi(++str);
	dec /= ft_pow(ft_nblen(dec), 10);
	if (ent < 0 || neg > 0)
		return (ent - dec);
	else
		return (ent + dec);
}
