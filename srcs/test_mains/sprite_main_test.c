/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_main_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:17:45 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/21 17:39:38 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header_cub3d.h"

typedef struct	s_settings
{
	bool	S;
	int		sprite_fd;
	char	*sprite_texture_path;
	void	*mlx;
}				t_setup;

int	p_sprite_texture(char *line, t_setup *setup);

int main()
{
	int ret = 0;
	t_setup setup;
	setup.mlx = mlx_init();
	dprintf(1, "--- test 1 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_sprite_texture("S     ./././     ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "S = %d\n", setup.S);
	dprintf(1, "sprite_texture_fd = %d\n", setup.sprite_fd);
	dprintf(1, "sprite_texture_path = |%s|\n", setup.sprite_texture_path);
	dprintf(1, "--- test 2 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_sprite_texture("S    ../textures/grass.xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "S = %d\n", setup.S);
	dprintf(1, "sprite_texture_fd = %d\n", setup.sprite_fd);
	dprintf(1, "sprite_texture_path = |%s|\n", setup.sprite_texture_path);
	dprintf(1, "--- test 3 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_sprite_texture("S    38     xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "S = %d\n", setup.S);
	dprintf(1, "sprite_texture_fd = %d\n", setup.sprite_fd);
	dprintf(1, "sprite_texture_path = |%s|\n", setup.sprite_texture_path);
	dprintf(1, "--- test 4 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_sprite_texture("S   38   ../textures/stone.png   ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "S = %d\n", setup.S);
	dprintf(1, "sprite_texture_fd = %d\n", setup.sprite_fd);
	dprintf(1, "sprite_texture_path = |%s|\n", setup.sprite_texture_path);
	dprintf(1, "--- test 5 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_sprite_texture("S   ../textures/stone.png   ../textures/grass.xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "S = %d\n", setup.S);
	dprintf(1, "sprite_texture_fd = %d\n", setup.sprite_fd);
	dprintf(1, "sprite_texture_path = |%s|\n", setup.sprite_texture_path);
	dprintf(1, "--- test 6 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_sprite_texture("S    ../textures/file.txt    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "S = %d\n", setup.S);
	dprintf(1, "sprite_texture_fd = %d\n", setup.sprite_fd);
	dprintf(1, "sprite_texture_path = |%s|\n", setup.sprite_texture_path);
	dprintf(1, "--- test 7 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_sprite_texture("S    ../textures./grass.xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "S = %d\n", setup.S);
	dprintf(1, "sprite_texture_fd = %d\n", setup.sprite_fd);
	dprintf(1, "sprite_texture_path = |%s|\n", setup.sprite_texture_path);
	dprintf(1, "--- test 8 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_sprite_texture("S    ../textures.xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "S = %d\n", setup.S);
	dprintf(1, "sprite_texture_fd = %d\n", setup.sprite_fd);
	dprintf(1, "sprite_texture_path = |%s|\n", setup.sprite_texture_path);
	dprintf(1, "--- test 9 ---\n");
	ft_bzero(&setup, sizeof(setup));
	ret = p_sprite_texture("Srdine    ../textures/grass.xpm    ", &setup);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "S = %d\n", setup.S);
	dprintf(1, "sprite_texture_fd = %d\n", setup.sprite_fd);
	dprintf(1, "sprite_texture_path = |%s|\n", setup.sprite_texture_path);
}
