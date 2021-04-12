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

int	parse_resolution(char *line, t_setup *setup)
{
	int	i;

	i = 0;
	setup->res_w = 0;
	setup->res_h = 0;
	//tant quon est pas sur un chiffre on passe
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
}

/* R NO SO WE EA S F C*/
int	parse_line(char *line, t_setup *setup)
{
	while (*line == ' ')
		line++;
	if (line[0] == 'R')
	{
		parse_resolution(line, setup);
		if (cap_resolution(setup) < 0)
			return (-1);
		printf("PARSED and CAPPED res WIDTH : %d\n", setup->res_w);
		printf("PARSED and CAPPED res HEIGHT : %d\n", setup->res_h);
		setup->nb_parsed_values++;
	}
	if (line[0] == 'N' || line[0] == 'W' || line[0] == 'E' || (line[0] == 'S' && line[1] == 'O'))
	{
		if (parse_textures(line, setup) < 0)
		{
			ft_putstr_fd("Error \nTexture parsing failed, check your .cub file please <3\n", 0);
			return (-1);
		}
		//if (check_ambLightValues(setup) < 0)
		//	return (-1);
		/*printf("PARSED ambLight intensity : %f\n", setup->ambLight.intensity);
		printf("PARSED ambLight R : %d\n", setup->ambLight.color.R);
		printf("PARSED ambLight G : %d\n", setup->ambLight.color.G);
		printf("PARSED ambLight B : %d\n", setup->ambLight.color.B);*/
	}
	/*if (line[0] == 'c' && line[1] != 'y')
	{
		parse_cam(&line[1], setup);
		printf("PARSED cam Coordinate x : %f\n", setup->cam.camCoordo.x);
		printf("PARSED cam Coordinate y : %f\n", setup->cam.camCoordo.y);
		printf("PARSED cam Coordinate z : %f\n", setup->cam.camCoordo.z);
		printf("PARSED cam Orientation x : %f\n", setup->cam.camOrientation.x);
		printf("PARSED cam Orientation y : %f\n", setup->cam.camOrientation.y);
		printf("PARSED cam Orientation z : %f\n", setup->cam.camOrientation.z);
		printf("PARSED cam FOV : %d\n", setup->cam.FOV);
	}
	if (line[0] == 'l')
	{
		parse_light(&line[1], setup);
		printf("PARSED Light Coordinate x : %f\n", setup->light.lightCoordo.x);
		printf("PARSED Light Coordinate y : %f\n", setup->light.lightCoordo.y);
		printf("PARSED Light Coordinate z : %f\n", setup->light.lightCoordo.z);
		printf("PARSED Light intensity : %f\n", setup->light.intensity);
		printf("PARSED Light R : %d\n", setup->light.color.R);
		printf("PARSED Light G : %d\n", setup->light.color.G);
		printf("PARSED Light B : %d\n", setup->light.color.B);
	}
	if (line[0] == 'p' && line[1] == 'l')
	{
		parse_plane(&line[1], setup);
		printf("PARSED Plane Coordinate x : %f\n", setup->light.lightCoordo.x);
		printf("PARSED Light Coordinate y : %f\n", setup->light.lightCoordo.y);
		printf("PARSED Light Coordinate z : %f\n", setup->light.lightCoordo.z);
		printf("PARSED Light intensity : %f\n", setup->light.intensity);
		printf("PARSED Light R : %d\n", setup->light.color.R);
		printf("PARSED Light G : %d\n", setup->light.color.G);
		printf("PARSED Light B : %d\n", setup->light.color.B);
	}*/
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
		//printf("ligne : %s\n", line);
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