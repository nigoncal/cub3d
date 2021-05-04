/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:46:12 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/04 11:15:18 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_cub3d.h"

// faire un bzero de toute ta structure

/*void	free_struct()
{
	if (*north_texture_path)
		free(north_texture_path);
	if (*south_texture_path)
		free(south_texture_path);
	if (*east_texture_path)
		free(east_texture_path);
	if (*west_texture_path)
		free(west_texture_path);
	if (*sprite_texture_path)
		free(sprite_texture_path);
	if (**map)
		fonction_a_coder_pour_free_tableau_de_chaine_de_char;
}*/

void	abort_prog(char *line, t_settings *cub_sets, char *error)
	// elle elle putstr
	// elle en appelle une qui free cub_sets mais element par element, s'il s'agit de pointeurs
	// et a la fin elle se free elle-mem, je veux dire la structure
	// puis elle appelle une fonction qui free toute la partie graphique, les images
	// a la fin tu exit(0);
{
	ft_putstr("Error\n");
	if (errno)
		perror("");
	else
		ft_putstr(error);
//	perror("Error\nUsage ");
//	free_struct(cub_sets);
//	free_images(???);
	free(line);
	exit(1);
}
