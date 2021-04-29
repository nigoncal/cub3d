#include "../cub3D.h"

int	parse_ID(char *ID, char *expected, int max)
{
	if (ft_strncmp(ID, expected, max) != 0)
	{
		printf("Error\nWrong ID in .cub file : expected \"R\" for resolution, \"S\" for sprites, \"C\" for ceiling color and \"F\" for floor color, \"NO\", \
\"SO\", \"EA\" or \"WE\" for wall textures.\n \"%s\" is invalid.\n", ID);
		return (-1);
	}
	return (0);
}

int	parse_tex_ID(char **elements, t_info *info)
{
	(void)info;
	if (elements[0][0] == 'N')
	{
		return (parse_ID(elements[0], "NO", 3));
	}
	if (elements[0][0] == 'W')
	{
		return (parse_ID(elements[0], "WE", 3));
	}
	if (elements[0][0] == 'E')
	{
		return (parse_ID(elements[0], "EA", 3));
	}
	return (-1);
}
/*
int	parse_res_ID(char **elements, t_setup *setup)
{
	(void)setup;
	if (ft_strncmp(elements[0], "R", 2) != 0)
		{
			printf("Error\nWrong ID in .cub file : try with \"R\"\n");
			return (-1);
		}
	return (0);
}*/