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
}				t_settings;

int	east_texture(char *line, t_settings *cub_sets);

int main()
{
	int ret = 0;
	t_settings cub_sets;
	cub_sets.mlx = mlx_init();
	dprintf(1, "--- test 1 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = east_texture("E     ./././     ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", cub_sets.EA);
	dprintf(1, "east_texture_fd = %d\n", cub_sets.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", cub_sets.east_texture_path);
	dprintf(1, "--- test 2 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = east_texture("EA    ../textures/grass.xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", cub_sets.EA);
	dprintf(1, "east_texture_fd = %d\n", cub_sets.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", cub_sets.east_texture_path);
	dprintf(1, "--- test 3 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = east_texture("EA    38     xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", cub_sets.EA);
	dprintf(1, "east_texture_fd = %d\n", cub_sets.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", cub_sets.east_texture_path);
	dprintf(1, "--- test 4 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = east_texture("EA   38   ../textures/stone.png   ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", cub_sets.EA);
	dprintf(1, "east_texture_fd = %d\n", cub_sets.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", cub_sets.east_texture_path);
	dprintf(1, "--- test 5 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = east_texture("EA   ../textures/stone.png   ../textures/grass.xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", cub_sets.EA);
	dprintf(1, "east_texture_fd = %d\n", cub_sets.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", cub_sets.east_texture_path);
	dprintf(1, "--- test 6 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = east_texture("EA    ../textures/file.txt    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", cub_sets.EA);
	dprintf(1, "east_texture_fd = %d\n", cub_sets.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", cub_sets.east_texture_path);
	dprintf(1, "--- test 7 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = east_texture("EA    ../textures./grass.xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", cub_sets.EA);
	dprintf(1, "east_texture_fd = %d\n", cub_sets.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", cub_sets.east_texture_path);
	dprintf(1, "--- test 8 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = east_texture("EA    ../textures.xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", cub_sets.EA);
	dprintf(1, "east_texture_fd = %d\n", cub_sets.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", cub_sets.east_texture_path);
	dprintf(1, "--- test 9 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = east_texture("EArdine    ../textures/grass.xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "EA = %d\n", cub_sets.EA);
	dprintf(1, "east_texture_fd = %d\n", cub_sets.east_fd);
	dprintf(1, "east_texture_path = |%s|\n", cub_sets.east_texture_path);
}
