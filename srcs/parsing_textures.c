#include "../cub3D.h"

int	parse_textures(char **tab, t_info *info)
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
	fd = 0;
	fd = check_file(&tab[1][i], ".png");
	if (fd < 2)
		return (-1);
	
	if (tab[0][0] == 'N' && tab[0][1] == 'O')
	{
		//tester l'ID avec strncmp + donner le chemin de copie
		
		info->setup.north_texture_path = &tab[1][i];
		printf("chemin NO : [%s]\n", info->setup.north_texture_path);
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