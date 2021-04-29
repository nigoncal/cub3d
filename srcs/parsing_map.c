#include "../cub3D.h"

int	get_map_size(char *line, t_info *info)
{
	int	len;

	len = 0;
	//if (map_valid_line && line not empty)
	printf("on passe dans get map size\n");
	info->map_info.map_nb_lines++;
	len = ft_strlen(line);
	if (len > info->map_info.map_longest_line)
		info->map_info.map_longest_line = len;
	return (0);
}

int	parse_map(char *line, t_info *info)
{
	//static int	tab_line;
	
	if (info->map_info.map_size_known != 1)
	{
		get_map_size(line, info);
		// go to map parsing
	}
	else if (info->map_info.map_malloced == 0)
	{
		//malloc le char ** de la struct pour stocker la map
		info->setup.map = malloc(sizeof(char *) * \
	(info->map_info.map_nb_lines + 1));
		if (info->setup.map == NULL)
			return (-1);
		else
			info->map_info.map_malloced = 1;
	}
	if (info->map_info.map_malloced)
	{
		//go to map_copy
		if (info->map_info.map_nb_lines > 0)
		{
			info->setup.map[info->map_info.map_tab_line] = line;
			if (info->setup.map[info->map_info.map_tab_line] == NULL)
			{
				free_2d_tab(info->setup.map, info->map_info.map_tab_line);
				return (-1);
			}
			info->map_info.map_tab_line++;
			info->map_info.map_nb_lines--;
		}
		else if (info->map_info.map_nb_lines == 0)
		{
			info->setup.map[info->map_info.map_tab_line] = 0;
		}
	}
	return (0);
}
