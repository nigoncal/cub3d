#include "../cub3D.h"

int	get_map_size(char *line, t_info *info)
{
	int	len;

	len = 0;
	//if (map_valid_line && line not empty)
	printf("on passe dans get map size\n");
	info->map.nb_lines++;
	len = ft_strlen(line);
	if (len > info->map.longest_line)
		info->map.longest_line = len;
	return (0);
}


// FONCTION A CHANGER POUR STOCKER DIRECT LA MAP (genre dans une liste chainee) AU 1ER GNL
int	parse_map(char *line, t_info *info)
{
	// CA CA GICLE
	/*if (info->map.size_known != 1)
	{
		get_map_size(line, info);
		// go to map parsing
	}*/
	/*else */if (info->map.begun == 0)
	{
		info->tmp_map.content = malloc(sizeof(line));
		if (info->tmp_map.content == NULL)
		{
			printf("chained list creation failed\n");
			return (-1);
		}
		printf("chained list creation SUCCEDED\n");
		info->map.begun = 1;
		//malloc le char ** de la struct pour stocker la map
		/*info->setup.map = malloc(sizeof(char *) * \
	(info->map.nb_lines + 1));
		if (info->setup.map == NULL)
			return (-1);
		else
			info->map.malloced = 1;*/
	}
	if (info->map.begun)
	{
		//go to map_copy

		/*if (info->map.nb_lines > 0)
		{
			info->setup.map[info->map.tab_line] = line;
			if (info->setup.map[info->map.tab_line] == NULL)
			{
				free_2d_tab(info->setup.map, info->map.tab_line);
				return (-1);
			}
			info->map.tab_line++;
			info->map.nb_lines--;
		}
		else if (info->map.nb_lines == 0)
		{
			info->setup.map[info->map.tab_line] = 0;
		}*/
	}
	return (0);
}
