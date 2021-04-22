/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:06:21 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/22 13:17:05 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h> // a virer

/*void	color(char **line, t_settings *cub_sets)
{
	if (*(*line) == 'C')
	{
		cub_sets->ceiling_red = ft_pf_atoi(line);
		cub_sets->ceiling_green = ft_pf_atoi(line);
		cub_sets->ceiling_blue = ft_pf_atoi(line);
	}
	if (*(*line) == 'F')
	{
		cub_sets->floor_red = ft_pf_atoi(line);
		cub_sets->floor_green = ft_pf_atoi(line);
		cub_sets->floor_blue = ft_pf_atoi(line);
	}
}*/

/*void	add_line_map(char **line, t_settings *cub_sets)
{
	int		size;
	int		i;
	char	**temp;

	size = 0;
	i = 0;
	while (cub_sets->map[size])
		size++;
	size++;
	if ((temp = (char**)malloc(sizeof(char*) * size + 1)) == NULL)
		return ; // error message
	while (size--)
	{
		temp[i] = ft_strdup(cub_sets->map[i]);
		i++;
	}
	temp[i - 1] = ft_strdup(*line);
	temp[i] = 0;
	free(cub_sets->map);
	cub_sets->map = temp;
}*/

/*void	ft_map(char **line, t_settings *cub_sets)
{
	if (cub_sets->map == NULL)
	{
		if ((cub_sets->map = (char**)malloc(sizeof(char*) + 1)) == NULL)
			return ; // error message
		cub_sets->map[0] = ft_strdup(*line);
		cub_sets->map[1] = 0;
	}
	else
		ft_add_line_map(line, cub_sets);
	while (*(*line) != '\0')
		(*line)++;
}*/

void	parse_map(char *line, t_settings *cub_sets)
{
	while (line)
	{
		if (ft_isalnum(line)) // map : peut commencer par et contenir |' '/1/0/2/N/S/W/E|.
			ft_map(line, cub_sets);
	}
}

void	parse_id(char *line, t_settings *cub_sets)
{
	line = change_char(line, ' ', '\t'); // line est malloc a la base ? change_char ft_strdup une nouvelle ligne. Quid de l'adresse de line ? ecrasee ? faut-il free les deux ? check les leaks
	line = change_char(line, ' ', '\v'); // pareil
	while (line)
	{
		while (line == ' ') // test depuis l'ajout du \t surtout le ||, plutot que le &&
			line++;
		if (line == 'R')
			resolution(line, cub_sets);
		if (line == 'N' || line == 'S' || line == 'E' || line == 'W')
			texture(line, cub_sets);
		// tu en es la
		if (line == 'F' || line == 'C')
			color(line, cub_sets);
		else
			abort_all(line, cub_sets, "Identifiers allowed : R, NO, SO, WE, EA, S, F, C");
	}
}
