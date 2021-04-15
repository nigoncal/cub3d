/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:11:38 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/14 16:39:38 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h" // a ajouter dans ton header
//#include "header_cub3d.h"
#include <stdbool.h>
#include "libft/header_libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h> // a virer

typedef struct	s_settings
{
	bool	R;
	int		width;
	int		height;
	void	*mlx; // si ca marche, a bien ajouter a ta structure dans le header
}				cub_settings;

void	resolution(char *line, cub_settings *settings);

int main()
{
//    void    *mlx; // a ajouter dans ton main a toi

//    mlx = mlx_init(); // a ajouter dans ton main a toi
	cub_settings settings;
	settings.mlx = mlx_init();
	dprintf(1, "--- test 1 ---\n");
	ft_bzero(&settings, sizeof(settings));
	resolution("R  138 145   ", &settings);
	dprintf(1, "R = %d\n", settings.R);
	dprintf(1, "width = %d\n", settings.width);
	dprintf(1, "height = %d\n", settings.height);
	dprintf(1, "--- test 2 ---\n");
	ft_bzero(&settings, sizeof(settings));
	resolution("     RS   ", &settings);
	dprintf(1, "R = %d\n", settings.R);
	dprintf(1, "width = %d\n", settings.width);
	dprintf(1, "height = %d\n", settings.height);
	dprintf(1, "--- test 3 ---\n");
	ft_bzero(&settings, sizeof(settings));
	resolution("148   ", &settings);
	dprintf(1, "R = %d\n", settings.R);
	dprintf(1, "width = %d\n", settings.width);
	dprintf(1, "height = %d\n", settings.height);
	dprintf(1, "--- test 4 ---\n");
	ft_bzero(&settings, sizeof(settings));
	resolution("R  148   13  14   ", &settings);
	dprintf(1, "R = %d\n", settings.R);
	dprintf(1, "width = %d\n", settings.width);
	dprintf(1, "height = %d\n", settings.height);
	dprintf(1, "--- test 5 ---\n");
	ft_bzero(&settings, sizeof(settings));
	resolution("R -148   13   ", &settings);
	dprintf(1, "R = %d\n", settings.R);
	dprintf(1, "width = %d\n", settings.width);
	dprintf(1, "height = %d\n", settings.height);
	dprintf(1, "--- test 6 ---\n");
	ft_bzero(&settings, sizeof(settings));
	resolution("R  #   148  +39   ", &settings);
	dprintf(1, "R = %d\n", settings.R);
	dprintf(1, "width = %d\n", settings.width);
	dprintf(1, "height = %d\n", settings.height);
	dprintf(1, "--- test 7 ---\n");
	ft_bzero(&settings, sizeof(settings));
	resolution("Rouge     148  39   ", &settings);
	dprintf(1, "R = %d\n", settings.R);
	dprintf(1, "width = %d\n", settings.width);
	dprintf(1, "height = %d\n", settings.height);
	dprintf(1, "--- test 8 ---\n");
	ft_bzero(&settings, sizeof(settings));
	resolution("R  50555     20555     ", &settings);
	dprintf(1, "R = %d\n", settings.R);
	dprintf(1, "width = %d\n", settings.width);
	dprintf(1, "height = %d\n", settings.height);
}
