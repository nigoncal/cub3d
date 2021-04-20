#include "../cub3D.h"

int	parse_line(char *line, t_setup *setup)
{
	int	skip;
	char **elements;

	skip = 0;
	printf("Ligne parsée : [%s]\n", line);
	//printf("Values parsées : %d\n", setup->nb_parsed_values);
	// attention a traiter si la map est separee par une ligne vide ! + verif vilidite ligne de map (only 0;1;' ')
	
	if (setup->nb_parsed_values == 8)
	{	
		//passer les lignes vides en incrementant setup->map_start_line
		//verif qu'on ne retombe pas sur un ID deja rencontré !!!
		//printf("on a nos 8 values\n");
		parse_map(line, setup);
		return (0);
	}
	//on passe les whitespaces du debut de ligne, puis on verif si il reste qqch dans la line
	line = is_line_empty(line);
	if (!*line)
	{
		setup->map_start_line++;
		return (0);
	}
	elements = ft_split(line, ' ');
	//printf("premiere case du tab : [%s]\n", elements [0]);
	//printf("Ligne parsée WS skip : [%s]\n", line);
	//printf("premiere case du tab : [%c]\n", elements [0][0]);
	if (elements[0][0] == 'R')
	{
		if (parse_res_ID(elements, setup))
			return (-1);
	}
	else if (elements[0][0] == 'N' || elements[0][0] == 'W' || elements[0][0] == 'E' \
	|| elements[0][0] == 'S')
	{
		if (parse_tex_ID(elements, setup))
			return (-1);
		/*if (parse_textures(elements, setup) < 0)
		{
			ft_putstr_fd("Error\nTexture files parsing failed, check your .cub file \
please <3\n", 0);
			return (-1);
		}
		setup->nb_parsed_values++;
		setup->map_start_line++;*/
	}
	/*else if (elements[0][0] == 'S' && elements[0][1] != 'O')
	{
		printf("hey ho Sprite line info. ID is : %d\n", setup->IDs.Sprite);
		if (setup->IDs.Sprite == 1)
		{
			printf("Error\nSprite image file parsing failed : two lines with the\
Sprite ID appear in your .cub. Only one is accepted.\n");
			return (-1);
		}
		//parse_sprite(elements, setup);
		setup->IDs.Sprite = 1;
		setup->nb_parsed_values++;
		setup->map_start_line++;
	}*/
	else if (elements[0][0] == 'F' || elements[0][0] == 'C')
	{
		//parse_color(elements, setup);
		setup->nb_parsed_values++;
		setup->map_start_line++;
	}
	else
		return (-1);
	return (0);
}

int	open_file(t_setup *setup, int fd)
{
	int 	skipped_lines;
	char	*line;
	//printf("nom fichier a ouvrir : %s\n", argv[argc - 1]);
	//fd = open(argv[argc - 1], O_RDONLY);
	//printf("fd = %d\n", fd);
	skipped_lines = 0;
	line = NULL;
	if (setup->map_size_known)
	{
		//sauter les lines jusqu'a atteindre setup.map_start_line
		while (get_next_line(fd, &line) == 1 \
		&& skipped_lines < (setup->map_start_line - 1))
		{
			skipped_lines++;
		}
	}
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		if (parse_line(line, setup) < 0)
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
int	parse_args(int argc, char **argv, t_setup *setup)
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
	//printf("fd = %d\n", fd);
	setup->cub_fd = fd;
	if (open_file(setup, fd) < 0)
		return (-1);
	return (0);
}