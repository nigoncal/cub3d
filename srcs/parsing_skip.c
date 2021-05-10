#include "../cub3D.h"

char is_this_line_empty(char *line)
{
	if (*line == '\0')
	{
		printf("There's nothing in this line\n");
		return (*line);
	}
	while (*line != '\0' && (*line == ' ' || *line == '\t' || *line == '\v'))
	{
		line++;
	}
	printf("On trouve ce char apres avoir skip ws %c\n", *line);
	return (*line);
}

char *is_line_empty(char *line)
{
	int skip;

	if (*line == '\0')
	{
		printf("yep that's empty\n");
		return (line);
	}
	skip = 0;
	skip = skip_ws(line);
	while (*line != '\0' && skip > 0)
	{
		line++;
		skip--;
	}
	return (line);
}

int	skip_ws(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\v')
		{
			i++;
		}
		else
			return (i);
	}
	return (i);
}
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
			i++;
		else
			return (i);
	}
	return (i);
}
