/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north_main_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:17:45 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/21 17:21:46 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

typedef struct	s_settings
{
	bool	NO;
	int		north_fd;
	char	*north_texture_path;
	void	*mlx;
}				t_setup;

int	p_north_texture(char *line, t_setup *setup);

int main()
{
	int ret = 0;
	t_setup setup;
	setup.mlx = mlx_init();
	dprintf(1, "--- test 1 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_north_texture("N     ./././     ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", setup.NO);
	dprintf(1, "north_texture_fd = %d\n", setup.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", setup.north_texture_path);
	dprintf(1, "--- test 2 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_north_texture("NO    ../textures/grass.xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", setup.NO);
	dprintf(1, "north_texture_fd = %d\n", setup.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", setup.north_texture_path);
	dprintf(1, "--- test 3 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_north_texture("NO    38     xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", setup.NO);
	dprintf(1, "north_texture_fd = %d\n", setup.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", setup.north_texture_path);
	dprintf(1, "--- test 4 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_north_texture("NO   38   ../textures/stone.png   ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", setup.NO);
	dprintf(1, "north_texture_fd = %d\n", setup.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", setup.north_texture_path);
	dprintf(1, "--- test 5 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_north_texture("NO   ../textures/stone.png   ../textures/grass.xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", setup.NO);
	dprintf(1, "north_texture_fd = %d\n", setup.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", setup.north_texture_path);
	dprintf(1, "--- test 6 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_north_texture("NO    ../textures/file.txt    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", setup.NO);
	dprintf(1, "north_texture_fd = %d\n", setup.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", setup.north_texture_path);
	dprintf(1, "--- test 7 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_north_texture("NO    ../textures./grass.xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", setup.NO);
	dprintf(1, "north_texture_fd = %d\n", setup.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", setup.north_texture_path);
	dprintf(1, "--- test 8 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_north_texture("NO    ../textures.xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", setup.NO);
	dprintf(1, "north_texture_fd = %d\n", setup.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", setup.north_texture_path);
	dprintf(1, "--- test 9 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_north_texture("NOrdine    ../textures/grass.xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", setup.NO);
	dprintf(1, "north_texture_fd = %d\n", setup.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", setup.north_texture_path);
}
