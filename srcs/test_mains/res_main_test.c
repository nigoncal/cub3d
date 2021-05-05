/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_main_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:58:01 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/22 11:53:09 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

typedef struct	s_settings
{
	bool	R;
	int		width;
	int		height;
	void	*mlx; // si ca marche, a bien ajouter a ta structure dans le header
}				t_settings;

void	p_resolution(char *line, t_settings *cub_sets);

int main()
{
//    void    *mlx; // a ajouter dans ton main a toi

//    mlx = mlx_init(); // a ajouter dans ton main a toi
	t_settings *cub_sets;
	cub_sets = malloc(sizeof(*cub_sets));
	cub_sets->mlx = mlx_init();
	dprintf(1, "--- test 1 ---\n");
	ft_bzero(cub_sets, sizeof(*cub_sets));
	p_resolution("R  138 145   ", cub_sets);
	dprintf(1, "R = %d\n", cub_sets->R);
	dprintf(1, "width = %d\n", cub_sets->width);
	dprintf(1, "height = %d\n", cub_sets->height);
	dprintf(1, "--- test 2 ---\n");
	ft_bzero(cub_sets, sizeof(*cub_sets));
	p_resolution("     RS   ", cub_sets);
	dprintf(1, "R = %d\n", cub_sets->R);
	dprintf(1, "width = %d\n", cub_sets->width);
	dprintf(1, "height = %d\n", cub_sets->height);
	dprintf(1, "--- test 3 ---\n");
	ft_bzero(cub_sets, sizeof(*cub_sets));
	p_resolution("148   ", cub_sets);
	dprintf(1, "R = %d\n", cub_sets->R);
	dprintf(1, "width = %d\n", cub_sets->width);
	dprintf(1, "height = %d\n", cub_sets->height);
	dprintf(1, "--- test 4 ---\n");
	ft_bzero(cub_sets, sizeof(*cub_sets));
	p_resolution("R  148   13  14   ", cub_sets);
	dprintf(1, "R = %d\n", cub_sets->R);
	dprintf(1, "width = %d\n", cub_sets->width);
	dprintf(1, "height = %d\n", cub_sets->height);
	dprintf(1, "--- test 5 ---\n");
	ft_bzero(cub_sets, sizeof(*cub_sets));
	p_resolution("R -148   13   ", cub_sets);
	dprintf(1, "R = %d\n", cub_sets->R);
	dprintf(1, "width = %d\n", cub_sets->width);
	dprintf(1, "height = %d\n", cub_sets->height);
	dprintf(1, "--- test 6 ---\n");
	ft_bzero(cub_sets, sizeof(*cub_sets));
	p_resolution("R  #   148  +39   ", cub_sets);
	dprintf(1, "R = %d\n", cub_sets->R);
	dprintf(1, "width = %d\n", cub_sets->width);
	dprintf(1, "height = %d\n", cub_sets->height);
	dprintf(1, "--- test 7 ---\n");
	ft_bzero(cub_sets, sizeof(*cub_sets));
	p_resolution("Rouge     148  39   ", cub_sets);
	dprintf(1, "R = %d\n", cub_sets->R);
	dprintf(1, "width = %d\n", cub_sets->width);
	dprintf(1, "height = %d\n", cub_sets->height);
	dprintf(1, "--- test 8 ---\n");
	ft_bzero(cub_sets, sizeof(*cub_sets));
	p_resolution("R  50555     20555     ", cub_sets);
	dprintf(1, "R = %d\n", cub_sets->R);
	dprintf(1, "width = %d\n", cub_sets->width);
	dprintf(1, "height = %d\n", cub_sets->height);
	free(cub_sets);
}
