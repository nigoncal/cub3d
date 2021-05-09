/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:46:12 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/09 15:55:51 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"

// faire un bzero de toute ta structure
// penses a free elements aussi, dans le parsing des textures (free_char_p2p)
// > free le juste avant d'appeler abort_prog

void	free_struct(t_settings *cub_sets) // a tester
{
	if (cub_sets->mlx)
		free(cub_sets->mlx);
	if (cub_sets->north_texture_path)
		free(cub_sets->north_texture_path);
	if (cub_sets->south_texture_path)
		free(cub_sets->south_texture_path);
	if (cub_sets->east_texture_path)
		free(cub_sets->east_texture_path);
	if (cub_sets->west_texture_path)
		free(cub_sets->west_texture_path);
	if (cub_sets->sprite_texture_path)
		free(cub_sets->sprite_texture_path);
	if (cub_sets->map)
		free_char_p2p(cub_sets->map);
	free(cub_sets);
}

/*void	free_graph(t_info *info)
{
	if (info->buffer)
		free(info->buffer);
	if (info->mlx)
		free(info->mlx);
	if (info->win)
		free(info->win);
	if (info->image)
		free(info->image);
	free(info);
}*/

void	abort_prog(char *line, t_settings *cub_sets, char *error)
	// elle elle putstr
	// elle en appelle une qui free cub_sets mais element par element, s'il s'agit de pointeurs
	// et a la fin elle se free elle-mem, je veux dire la structure
	// puis elle appelle une fonction qui free toute la partie graphique, les images
	// a la fin tu exit(0);
{
	dprintf(1, "W\n");
	ft_putstr("Error\n");
	if (errno)
		perror("");
	else
		ft_putstr(error);
	free_struct(cub_sets);
//	free_graph(t_info *info);
	free(line); // tu peux la free dans chaque fonction plutot qu'ici
	exit(1);
}
