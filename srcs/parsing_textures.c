#include "../cub3D.h"

int	parse_textures(char **tab, t_setup *setup)
{
	int fd;
	int l;
	int i;

	l = 0;
	i = 0;
	while (tab[l] != 0)
		l++;
	//printf("l = %d\n", l);
	if (l != 2)
		return (-1);
	//l = 1;
	i += skip_ws(tab[1]);
	printf("skip i = %d\n", i);
	// verif qu'on essaie pas d'open un dossier
	fd = 0;
	fd = open(&tab[1][i], O_DIRECTORY);
	if (fd != -1)
		return (-1);
	//verif validite fichier
	fd = 0;
	fd = open(&tab[1][i], O_RDONLY);
	printf("fd = %d\n", fd);
	//printf("path opened = [%s]\n", tab[1]);
	if (fd == -1)
		return (-1);
	if (tab[0][0] == 'N' && tab[0][1] == 'O')
	{
		//i = 0;
		//i += skip_ws(tab[1]);
		setup->north_texture_path = &tab[1][i];
		printf("chemin NO : [%s]\n", setup->north_texture_path);
		// calcul len str du path
		// malloc l'emplacement ?
		// copier le path dans la struct pr l'utiliser + tard
	}
	else if ((tab[0][0] == 'S' && tab[0][1] == 'O'))
	{
		//copier le path au bon endroit
	}
	else if (tab[0][0] == 'W' && tab[0][1] == 'E')
	{
		//copier le path au bon endroit
	}
	else if (tab[0][0] == 'E' && tab[0][1] == 'A')
	{
		//copier le path au bon endroit
	}
	//setup->nb_parsed_values++;
	close(fd);
	return (1);
}