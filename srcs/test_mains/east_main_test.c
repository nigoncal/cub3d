/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   east_main_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:17:45 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/21 17:36:21 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

typedef struct	s_settings
{
	bool	EA;
	int		east_fd;
	char	*east_texture_path;
	void	*mlx;
}				t_setup;

int	p_east_texture(char *line, t_setup *setup);

int main()
{
	int ret = 0;
	t_setup setup;
	setup.mlx = mlx_init();
	dprintf(1, "--- test 1 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_east_texture("E     ./././     ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", setup.EA);
	dprintf(1, "east_texture_fd = %d\n", setup.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", setup.east_texture_path);
	dprintf(1, "--- test 2 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_east_texture("EA    ../textures/grass.xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", setup.EA);
	dprintf(1, "east_texture_fd = %d\n", setup.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", setup.east_texture_path);
	dprintf(1, "--- test 3 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_east_texture("EA    38     xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", setup.EA);
	dprintf(1, "east_texture_fd = %d\n", setup.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", setup.east_texture_path);
	dprintf(1, "--- test 4 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_east_texture("EA   38   ../textures/stone.png   ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", setup.EA);
	dprintf(1, "east_texture_fd = %d\n", setup.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", setup.east_texture_path);
	dprintf(1, "--- test 5 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_east_texture("EA   ../textures/stone.png   ../textures/grass.xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", setup.EA);
	dprintf(1, "east_texture_fd = %d\n", setup.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", setup.east_texture_path);
	dprintf(1, "--- test 6 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_east_texture("EA    ../textures/file.txt    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", setup.EA);
	dprintf(1, "east_texture_fd = %d\n", setup.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", setup.east_texture_path);
	dprintf(1, "--- test 7 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_east_texture("EA    ../textures./grass.xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", setup.EA);
	dprintf(1, "east_texture_fd = %d\n", setup.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", setup.east_texture_path);
	dprintf(1, "--- test 8 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_east_texture("EA    ../textures.xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", setup.EA);
	dprintf(1, "east_texture_fd = %d\n", setup.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", setup.east_texture_path);
	dprintf(1, "--- test 9 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_east_texture("EArdine    ../textures/grass.xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", setup.EA);
	dprintf(1, "east_texture_fd = %d\n", setup.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", setup.east_texture_path);
}
