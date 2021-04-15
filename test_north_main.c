/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:35:51 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/14 15:19:23 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include "header_cub3d.h"
#include <stdbool.h>
#include "libft/header_libft.h"
#include "get_next_line/get_next_line.h" // en a-t-il besoin ?
#include <strings.h>
#include "minilibx/mlx.h" // a virer

typedef struct	s_settings
{
	bool	NO;
	int		north_fd;
	char	*north_texture_path;
	void	*mlx; // si ca marche, a bien ajouter a ta structure dans le header
}				cub_settings;

int	north_texture(char *line, cub_settings *settings);

int main()
{
//    void    *mlx; // a ajouter dans ton main a toi

//    mlx = mlx_init(); // a ajouter dans ton main a toi
	int ret = 0;
//	char *line = "NO    ./textures/grass.xpm    ./textures/stone.png    ";
	cub_settings settings;
//	settings.NO = false;
	settings.mlx = mlx_init();
	dprintf(1, "--- test 1 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("N     ./././     ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", settings.north_texture_path);
	dprintf(1, "--- test 2 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("NO    textures/grass.xpm    ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", settings.north_texture_path);
	dprintf(1, "--- test 3 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("NO    38     xpm    ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", settings.north_texture_path);
	dprintf(1, "--- test 4 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("NO   38   textures/stone.png   ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", settings.north_texture_path);
	dprintf(1, "--- test 5 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("NO   ./textures/stone.png   ./textures/grass.xpm    ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", settings.north_texture_path);
	dprintf(1, "--- test 6 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("NO    ./textures/file.txt    ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", settings.north_texture_path);
	dprintf(1, "--- test 7 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("NO    ./textures./grass.xpm    ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", settings.north_texture_path);
	dprintf(1, "--- test 8 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("NO    ./textures.xpm    ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", settings.north_texture_path);
	dprintf(1, "--- test 9 ---\n");
	ft_bzero(&settings, sizeof(cub_settings));
	ret = north_texture("NOrdine    ./textures/grass.xpm    ", &settings);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "NO = %d\n", settings.NO);
	dprintf(1, "north_texture_fd = %d\n", settings.north_fd);
	dprintf(1, "north_texture_path = |%s|\n", settings.north_texture_path);
}
