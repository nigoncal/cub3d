/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:46:12 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/17 17:49:16 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"

// faire un bzero de toute ta structure
// penses a free elements aussi, dans le parsing des textures (free_char_p2p)
// > free le juste avant d'appeler abort_prog

/*void	free_struct(t_settings *cub_sets) // a tester
{
	if (cub_sets->mlx)
		free(cub_sets->mlx);
	if (cub_sets->elements)
		free_char_p2p(cub_sets->elements);
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
}*/

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

void	abort_prog(char *error_msg)
	// elle elle putstr
	// elle en appelle une qui free cub_sets mais element par element, s'il s'agit de pointeurs
	// et a la fin elle se free elle-mem, je veux dire la structure
	// puis elle appelle une fonction qui free toute la partie graphique, les images
	// a la fin tu exit(0);
{
	ft_putstr("Error\n");
//	if (errno)
//		perror("");
//	else
//	{
		ft_putstr(error_msg);
		write (1, "\n", 1);
//	}
//	if (line)
//		wrfree(line);
	wrdestroy();
//	free_graph(t_info *info);
//	si appelee dans le main, line n'a pas encore ete malloc, donc fais un if
	exit(1);
}
