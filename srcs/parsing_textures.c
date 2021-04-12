#include "../cub3D.h"

int	parse_textures(char *line, t_setup *setup)
{
	int fd;

	printf("line passee a parse_texture = [%s]\n", line);
	fd = 0;
	// check la clé precise
	if (*line == 'N')
	{
		line += 2;
		while (line[0] == ' ')
			line++;
	}
	//verif validite fichier
	fd = open(line, O_RDONLY);
	/*printf("fd = %d\n", fd);
	printf("path opened = [%s]\n", line);*/
	if (fd == -1)
		return (-1);
	// calcul len str du path
	// malloc l'emplacement
	// copier le path dans la struct pr l'utiliser + tard
	setup->nb_parsed_values++;
	close(fd);
	return (1);
}