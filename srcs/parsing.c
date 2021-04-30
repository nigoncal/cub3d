#include "../cub3D.h"

int	parse_line(char *line, t_info *info)
{
	int		skip;
	char	**elements;

	skip = 0;
	printf("Values parsées precedement: %d\n", info->ids.nb_parsed_ids);
	printf("Ligne que l'on va parser ci-dessous : [%s]\n", line);
	// attention a traiter si la map est separee par une ligne vide ! + verif vilidite ligne de map (only 0;1;' ',NSEW)
	if (info->ids.nb_parsed_ids == 8)
	{	
		// AJOUTER un moyen de passer les lignes entierements vides AVANT la map
		// Et ajouter un check pour ne pas accepter les lignes vides si on retrouve autre chose que des lignes vides a la fin
		parse_map(line, info);
		return (0);
	}
	//on passe les whitespaces du debut de ligne, puis on verif si il reste qqch dans la line
	line = is_line_empty(line);
	if (!*line)
	{
		info->map.start_line++;
		return (0);
	}
	//A FAIRE : modifier la fonction ci dessous pour changer plusieurs char en 1 fonction
	line = change_char(line, ' ', 9, 0);
	line = change_char(line, ' ', 11, 0);
	elements = ft_split(line, ' ');
	//printf("premiere case du tab : [%s]\n", elements [0]);
	//printf("Ligne parsée WS skip : [%s]\n", line);
	//printf("premiere case du tab : [%c]\n", elements [0][0]);

	/* SEPARER LA FONCTION ICI !!!! */
	if (elements[0][0] == 'R')
	{
		if (parse_id(elements[0], "R", 2) || info->ids.res == 1)
		{
			if (info->ids.res == 1)
			{
				printf("Error\nResolution parsing failed because program found the \"R\" ID \
More than once. Only one occurency of each ID is accepted.\n");
			}
			return (-1);
		}
		if (parse_resolution(elements, info) < 0)
		{
			printf("Error\nResolution parsing failed, too many/few arguments. Expected \
the \"R\" ID, a width and then a height.\n");
			//checker remontee erreur + haut
			return (-1);
		}
		if (cap_resolution(info) < 0)
			return (-1);
		info->ids.res = 1;
		info->ids.nb_parsed_ids++;
	}
	/* SEPARER LA AUSSI */
	else if (elements[0][0] == 'N' || elements[0][0] == 'W' || elements[0][0] == 'E' \
	|| elements[0][0] == 'S')
	{
		if (parse_tex_id(elements, info))
			return (-1);
		if (parse_textures(elements, info) < 0)
		{
			ft_putstr_fd("Error\nTexture files parsing failed, check your .cub file \
please <3\n", 0);
			return (-1);
		}
		info->ids.nb_parsed_ids++;
		info->map.start_line++;
	}
	/*else if (elements[0][0] == 'S' && elements[0][1] != 'O')
	{
		printf("hey ho sprite line info. id is : %d\n", setup->ids.sprite);
		if (setup->ids.sprite == 1)
		{
			printf("Error\nsprite image file parsing failed : two lines with the\
sprite id appear in your .cub. Only one is accepted.\n");
			return (-1);
		}
		//parse_sprite(elements, setup);
		setup->ids.sprite = 1;
		setup->nb_parsed_values++;
		setup->map_start_line++;
	}*/
	else if (elements[0][0] == 'F' || elements[0][0] == 'C')
	{
		if (parse_color_id(elements))
			return (-1);


		//ajouter ici une fonction du genre parse_color(elements, setup);
		info->ids.nb_parsed_ids++;
		info->map.start_line++;
	}
	else
	{
		printf("Error\nCouldn't find any correct ID in one of .cub file's lines : expected \"R\" for resolution, \"S\" for sprites, \"C\" for ceiling color and \"F\" for floor color, \"NO\", \
\"SO\", \"EA\" or \"WE\" for wall textures.\n \"%s\" is invalid.\n", line);
		return (-1);
	}
	return (0);
}

int	open_file(t_info *info, int fd)
{
	int 	skipped_lines;
	char	*line;
	//printf("nom fichier a ouvrir : %s\n", argv[argc - 1]);
	//fd = open(argv[argc - 1], O_RDONLY);
	//printf("fd = %d\n", fd);
	skipped_lines = 0;
	line = NULL;
	if (info->map.size_known)
	{
		//sauter les lines jusqu'a atteindre setup.start_line
		while (get_next_line(fd, &line) == 1 \
&& skipped_lines < (info->map.start_line - 1))
		{
			skipped_lines++;
		}
	}
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		if (parse_line(line, info) < 0)
		{
			free(line);
			close(fd);
			return (-1);
		}
		//printf("Nb infos parsed before map : %d\n", setup->nb_parsed_values);
		//printf("Ligne ou debute la map : %d\n", setup->map_start_line);
		//free(line);
	}
	free(line);
	close(fd);
	//if (setup->map_size_known)
		//open again and GNL map_start_line times so read is back to the map start
		//go copy_map
	return (0);
}

int	check_file(char *path, char *extension)
{
	int	fd;
	int	i;

	fd = 0;
	i = 0;
	i = ft_strlen(path);
	i -= ft_strlen(extension);
	if (ft_strncmp(path + i, extension, i + 1))
	{
		printf("Error\nInvalid file : %s doesn't have the right extension.\n\
Expected a %s file.\n", path, extension);
		return (-1);
	}
	//printf("nom fichier a ouvrir : %s\n", path);
	fd = open(path, O_DIRECTORY);
	if (fd != -1)
	{
		printf("Error\nInvalid file : %s is a directory\n", path);
		return (-1);
	}
	fd = 0;
	fd = open(path, O_RDONLY);
	return (fd);
}

// rtop long : lancer gnl ds autre fonction ?
int	parse_args(int argc, char **argv, t_info *info)
{
	int		fd;

	if (argc > 3 || argc < 2)
		return (-1);
	if (argc == 3)
	{
		//strncmp renvoie 0 si identique, autre chose si trouve une diff
		if (ft_strncmp(argv[2], "--save", 7) != 0)
		{
			printf("Error\nProgram arguments are invalid. Usage : \
./cub3D *.cub --save(optionnal)\n");
			return (-1);
		}
		//don't open window just save .bmp
		//do not cap resolution !! (set setup->max_w/max_h à INTMAX par exemple ?)
	}
	//else if argc == 2 :
		//open window normally + cap resolution
	fd = 0;
	fd = check_file(argv[1], ".cub");
	if (fd < 2)
		return (-1);
	info->cub_fd = fd;
	if (open_file(info, fd) < 0)
	{
		return (-1);
	}
	return (0);
}