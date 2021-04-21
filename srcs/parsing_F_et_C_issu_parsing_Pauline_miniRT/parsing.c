/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:35:22 by pmillet           #+#    #+#             */
/*   Updated: 2021/04/02 16:40:05 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	cap_resolution(t_setup *setup, t_miniRT *mini)
{
	if (setup->res_w <= 0 || setup->res_h <= 0)
	{
		ft_putstr_fd("Error \nResolution parsing failed because of negative \
values, check your .rt file please <3\n", 0);
		return (-1);
	}
	mlx_get_screen_size(&mini->mlx, &mini->max_w, &mini->max_h);
	if (setup->res_w > mini->max_w)
		setup->res_w = mini->max_w;
	else if (mini->max_w != setup->res_w)
		mini->max_w = setup->res_w;
	if (setup->res_h > mini->max_h)
		setup->res_h = mini->max_h;
	else if (mini->max_h != setup->res_h)
		mini->max_h = setup->res_h;
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
		ft_putstr_fd("Error \nResolution parsing failed, check your .rt file please <3\n", 0);
		return (-1);
	}
	printf("PARSED res WIDTH neg ? : %d\n", setup->res_w);
	printf("PARSED res HEIGHT neg ? : %d\n", setup->res_h);
	return (1);
}

int	check_ambLightValues(t_setup *setup)
{
	if (setup->ambLight.intensity < 0 || setup->ambLight.intensity > 1)
	{
		ft_putstr_fd("Error \nAmbient light intensity value parsing failed because of negative \
or values above 1, check your .rt file please <3\n", 0);
		return (-1);
	}
	if (setup->ambLight.color.R < 0 || setup->ambLight.color.R > 255 || \
setup->ambLight.color.G < 0 || setup->ambLight.color.G > 255 || \
setup->ambLight.color.B < 0 || setup->ambLight.color.B > 255)
	{
		ft_putstr_fd("Error \nAmbient light color values parsing failed because of negative \
or values above 255, check your .rt file please <3\n", 0);
		return (-1);
	}
	return (1);
}

int	parse_ambLight(char *line, t_setup *setup)
{
	int	i;

	i = 0;
	setup->ambLight.intensity = 0;
	RGB_init(&setup->ambLight.color);
	//tant quon est pas sur un chiffre on passe
	i += skip_non_digits(&line[i], 0);
	// 1er chiffre = go atoi pour get l'intensité
	setup->ambLight.intensity = ft_atof (&line[i]);
	// on passe tous les chiffres du 1er nombre INTENSITY
	i += skip_non_digits(&line[i], 1);
	// si il y a des espaces, une virgule on les passe
	while (line[i] && (line[i] == ' ' || line[i] == '.'))
		i++;
	i += skip_non_digits(&line[i], 1);
	// 2e chiffre = go atoi (fonciton a part ?)
	i += skip_non_digits(&line[i], 0);
	setup->ambLight.color.R = ft_atof (&line[i]);
	// on passe tous les chiffres du 2e nombre R
	i += skip_non_digits(&line[i], 1);
	if (line[i] == ',')
		i++;
	// on traite le 3e chiffre G
	setup->ambLight.color.G = ft_atof (&line[i]);
	// on passe tous les chiffres du 3e nombre G
	i += skip_non_digits(&line[i], 1);
	if (line[i] == ',')
		i++;
	// on traite le 4e chiffre B
	setup->ambLight.color.B = ft_atof (&line[i]);
	// on passe tous les chiffres du 4e nombre B
	i += skip_non_digits(&line[i], 1);
	if (line[i] == ',')
		i++;
	//fin du parsing, il ne doit rien rester dans la ligne sauf ptet des espaces pcq on est sympas
	if (!line[i])
		return (1);
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && line[i] != ' ')
	{
		ft_putstr_fd("Error \nAmbient light parsing failed, check your .rt file please <3\n", 0);
		return (-1);
	}
	return (1);
}

int	parse_line(char *line, t_setup *setup, t_miniRT *mini)
{
	if (line[0] == 'R')
	{
		parse_resolution(line, setup);
		if (cap_resolution(setup, mini) < 0)
			return (-1);
		printf("PARSED res WIDTH : %d\n", setup->res_w);
		printf("PARSED res HEIGHT : %d\n", setup->res_h);
	}
	if (line[0] == 'A')
	{
		parse_ambLight(&line[1], setup);
		if (check_ambLightValues(setup) < 0)
			return (-1);
		printf("PARSED ambLight intensity : %f\n", setup->ambLight.intensity);
		printf("PARSED ambLight R : %d\n", setup->ambLight.color.R);
		printf("PARSED ambLight G : %d\n", setup->ambLight.color.G);
		printf("PARSED ambLight B : %d\n", setup->ambLight.color.B);
	}
	if (line[0] == 'c' && line[1] != 'y')
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
	/*if (line[0] == 'p' && line[1] == 'l')
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

int	parse_args(int argc, char **argv, t_setup *setup, t_miniRT *mini)
{
	int		fd;
	char	*line;

	if (argc > 3 || argc < 2)
		return (-1);
	//if (argv[2] == "--save")
		//don't open window just save .bmp
		//do not cap resolution !!
	//else
		//open window normally
	fd = 0;
	//printf("nom fichier a ouvrir : %s\n", argv[1]);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		if (parse_line(line, setup, mini) < 1)
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
	}
	free(line);
	close(fd);
	return (1);
}
