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
}				t_settings;

int	north_texture(char *line, t_settings *cub_sets);

int main()
{
	int ret = 0;
	t_settings cub_sets;
	cub_sets.mlx = mlx_init();
	dprintf(1, "--- test 1 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = north_texture("N     ./././     ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", cub_sets.NO);
	dprintf(1, "north_texture_fd = %d\n", cub_sets.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", cub_sets.north_texture_path);
	dprintf(1, "--- test 2 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = north_texture("NO    ../textures/grass.xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", cub_sets.NO);
	dprintf(1, "north_texture_fd = %d\n", cub_sets.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", cub_sets.north_texture_path);
	dprintf(1, "--- test 3 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = north_texture("NO    38     xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", cub_sets.NO);
	dprintf(1, "north_texture_fd = %d\n", cub_sets.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", cub_sets.north_texture_path);
	dprintf(1, "--- test 4 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = north_texture("NO   38   ../textures/stone.png   ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", cub_sets.NO);
	dprintf(1, "north_texture_fd = %d\n", cub_sets.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", cub_sets.north_texture_path);
	dprintf(1, "--- test 5 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = north_texture("NO   ../textures/stone.png   ../textures/grass.xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", cub_sets.NO);
	dprintf(1, "north_texture_fd = %d\n", cub_sets.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", cub_sets.north_texture_path);
	dprintf(1, "--- test 6 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = north_texture("NO    ../textures/file.txt    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", cub_sets.NO);
	dprintf(1, "north_texture_fd = %d\n", cub_sets.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", cub_sets.north_texture_path);
	dprintf(1, "--- test 7 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = north_texture("NO    ../textures./grass.xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", cub_sets.NO);
	dprintf(1, "north_texture_fd = %d\n", cub_sets.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", cub_sets.north_texture_path);
	dprintf(1, "--- test 8 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = north_texture("NO    ../textures.xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", cub_sets.NO);
	dprintf(1, "north_texture_fd = %d\n", cub_sets.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", cub_sets.north_texture_path);
	dprintf(1, "--- test 9 ---\n");
	ft_bzero(&cub_sets, sizeof(cub_sets));
	ret = north_texture("NOrdine    ../textures/grass.xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", cub_sets.NO);
	dprintf(1, "north_texture_fd = %d\n", cub_sets.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", cub_sets.north_texture_path);
}
