#include "../cub3D.h"

int	cap_resolution(t_setup *setup)
{
	if (setup->res_w <= 0 || setup->res_h <= 0)
	{
		ft_putstr_fd("Error \nResolution parsing failed because of negative \
values, check your .cub file please <3\n", 0);
		return (-1);
	}
	mlx_get_screen_size(setup->mlx, &setup->max_w, &setup->max_h);
	if (setup->res_w > setup->max_w)
		setup->res_w = setup->max_w;
	else if (setup->max_w != setup->res_w)
		setup->max_w = setup->res_w;
	if (setup->res_h > setup->max_h)
		setup->res_h = setup->max_h;
	else if (setup->max_h != setup->res_h)
		setup->max_h = setup->res_h;
	return (1);
}

int	parse_resolution(char **tab, t_setup *setup)
{
	int	i;
	int l;

	i = 0;
	l = 0;
	setup->res_w = 0;
	setup->res_h = 0;
	while (tab[l] != 0)
		l++;
	if (l != 3)
		return (-1);
	l = 1;
	i += skip_ws(tab[l]);
	setup->res_w = ft_atoi(tab[l]);
	printf("res W = %d\n", setup->res_w);
	l++;
	i += skip_ws(tab[l]);
	setup->res_h = ft_atoi(tab[l]);
	printf("res H = %d\n", setup->res_h);
	return (1);
}

/*
int	parse_resolution_old(char *line, t_setup *setup)
{
	int	i;

	i = 0;
	setup->res_w = 0;
	setup->res_h = 0;
	//tant quon est pas sur un chiffre on passe
	//i += skip_non_digits(&line[i], 0);

	i += skip_non_digits(&line[i], 0);
	// 1er chiffre = go atoi
	setup->res_w = ft_atoi (&line[i]);
	// on passe tous les chiffres du 1er nombre
	//while (line[i] && ft_isdigit(line[i]) == 1)
	//	i++;
	i += skip_non_digits(&line[i], 1);
	// si il y a des espaces, on les passe
	while (line[i] && line[i] == ' ')
		i++;
	// 2e chiffre = go atoi (fonciton a part ?)
	//while (line[i] && ft_isdigit(line[i]) == 0)
	//	i++;
	i += skip_non_digits(&line[i], 0);
	setup->res_h = ft_atoi (&line[i]);
	// on passe tous les chiffres du 2e nombre
	//while (line[i] && ft_isdigit(line[i]) == 1)
	//	i++;
	i += skip_non_digits(&line[i], 1);
	if (!line[i])
		return (1);
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && line[i] != ' ')
	{
		ft_putstr_fd("Error \nResolution parsing failed, check your .cub file please <3\n", 0);
		return (-1);
	}
	//printf("PARSED res WIDTH neg ? : %d\n", setup->res_w);
	//printf("PARSED res HEIGHT neg ? : %d\n", setup->res_h);
	return (1);
}*/

/* R NO SO WE EA S F C*/
int	parse_line(char *line, t_setup *setup)
{
	int	skip;
	char **elements;

	skip = 0;
	if (setup->nb_parsed_values == 8)
		// go to map parsing
	printf("Ligne parsée : [%s]\n", line);
	skip = skip_ws(line);
	while (*line != '\0' && skip > 0)
	{
		line++;
		skip--;
	}
	if (!*line)
		return (1);
	elements = ft_split(line, ' ');
	//printf("premiere case du tab : [%s]\n", elements [0]);
	//printf("Ligne parsée WS skip : [%s]\n", line);
	//printf("premiere case du tab : [%c]\n", elements [0][0]);
	if (elements[0][0] == 'R')
	{
		parse_resolution(elements, setup);
		if (cap_resolution(setup) < 0)
			return (-1);
		printf("PARSED and CAPPED res WIDTH : %d\n", setup->res_w);
		printf("PARSED and CAPPED res HEIGHT : %d\n", setup->res_h);
		setup->nb_parsed_values++;
	}
	if ((elements[0][0] == 'N' || elements[0][0] == 'W' || elements[0][0] == 'E' \
	|| (elements[0][0] == 'S' && elements[0][1] == 'O')))
	{
		if (parse_textures(elements, setup) < 0)
		{
			ft_putstr_fd("Error \nTexture files parsing failed, check your .cub file \
			please <3\n", 0);
			return (-1);
		}
		setup->nb_parsed_values++;
	}
	if (elements[0][0] == 'S')
	{
		//parse_sprite(elements, setup);
		// AJOUTER UN OPEN DIRECTORY pour verif qu'on essaie pas d'open un dossier !!!!!!
		setup->nb_parsed_values++;
	}
	if (elements[0][0] == 'F' || elements[0][0] == 'C')
	{
		//parse_color(elements, setup);
		setup->nb_parsed_values++;
	}
	return (1);
}

// rtop long : lancer gnl ds autre fonction ?
int	parse_args(int argc, char **argv, t_setup *setup)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	i = ft_strlen(argv[argc - 1]);
	i -= 4;
	if (argc > 3 || argc < 2)
		return (-1);
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 7))
			return (-1);
		//don't open window just save .bmp
		//do not cap resolution !!
	}
	//else if argc == 2 :
		//open window normally + cap resolution
	if (ft_strncmp(argv[argc - 1] + i, ".cub", 5))
	{
		ft_putstr_fd("Error\nArgument parsing failed. Usage : ./cub3D file.cub --save(optionnal)\n", 0);
		return (0);
	}
	fd = 0;
	printf("nom fichier a ouvrir : %s\n", argv[argc - 1]);
	fd = open(argv[argc - 1], O_RDONLY);
	//printf("fd = %d\n", fd);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		if (parse_line(line, setup) < 1)
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
	}
	//printf("ligne : %s\n", line);
	free(line);
	close(fd);
	return (1);
}