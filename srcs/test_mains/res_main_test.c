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
}				t_setup;

void	p_resolution(char *line, t_setup *setup);

int main()
{
//    void    *mlx; // a ajouter dans ton main a toi

//    mlx = mlx_init(); // a ajouter dans ton main a toi
	t_setup *setup;
	setup = wrmalloc(sizeof(*setup));
	setup->mlx = mlx_init();
	dprintf(1, "--- test 1 ---\n");
	ft_bzero(setup, sizeof(*setup));
	p_resolution("R  138 145   ", setup);
	dprintf(1, "R = %d\n", setup->res);
	dprintf(1, "width = %d\n", setup->width);
	dprintf(1, "height = %d\n", setup->height);
	dprintf(1, "--- test 2 ---\n");
	ft_bzero(setup, sizeof(*setup));
	p_resolution("     RS   ", setup);
	dprintf(1, "R = %d\n", setup->res);
	dprintf(1, "width = %d\n", setup->width);
	dprintf(1, "height = %d\n", setup->height);
	dprintf(1, "--- test 3 ---\n");
	ft_bzero(setup, sizeof(*setup));
	p_resolution("148   ", setup);
	dprintf(1, "R = %d\n", setup->res);
	dprintf(1, "width = %d\n", setup->width);
	dprintf(1, "height = %d\n", setup->height);
	dprintf(1, "--- test 4 ---\n");
	ft_bzero(setup, sizeof(*setup));
	p_resolution("R  148   13  14   ", setup);
	dprintf(1, "R = %d\n", setup->res);
	dprintf(1, "width = %d\n", setup->width);
	dprintf(1, "height = %d\n", setup->height);
	dprintf(1, "--- test 5 ---\n");
	ft_bzero(setup, sizeof(*setup));
	p_resolution("R -148   13   ", setup);
	dprintf(1, "R = %d\n", setup->res);
	dprintf(1, "width = %d\n", setup->width);
	dprintf(1, "height = %d\n", setup->height);
	dprintf(1, "--- test 6 ---\n");
	ft_bzero(setup, sizeof(*setup));
	p_resolution("R  #   148  +39   ", setup);
	dprintf(1, "R = %d\n", setup->res);
	dprintf(1, "width = %d\n", setup->width);
	dprintf(1, "height = %d\n", setup->height);
	dprintf(1, "--- test 7 ---\n");
	ft_bzero(setup, sizeof(*setup));
	p_resolution("Rouge     148  39   ", setup);
	dprintf(1, "R = %d\n", setup->res);
	dprintf(1, "width = %d\n", setup->width);
	dprintf(1, "height = %d\n", setup->height);
	dprintf(1, "--- test 8 ---\n");
	ft_bzero(setup, sizeof(*setup));
	p_resolution("R  50555     20555     ", setup);
	dprintf(1, "R = %d\n", setup->res);
	dprintf(1, "width = %d\n", setup->width);
	dprintf(1, "height = %d\n", setup->height);
	free(setup);
}
