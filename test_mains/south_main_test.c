/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:35:51 by sylducam          #+#    #+#             */
/*   Updated: 2021/04/16 08:50:56 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include "../header_cub3d.h"
#include <stdbool.h>
#include "../libft/header_libft.h"
#include "../get_next_line/get_next_line.h" // en a-t-il besoin ?
#include <strings.h>
#include "../minilibx/mlx.h" // a virer

typedef struct	s_settings
{
	bool	SO;
	int		south_fd;
	char	*south_texture_path;
	void	*mlx; // si ca marche, a bien ajouter a ta structure dans le header
}				t_settings;

int	south_texture(char *line, t_settings *cub_sets);

int main()
{
//    void    *mlx; // a ajouter dans ton main a toi

//    mlx = mlx_init(); // a ajouter dans ton main a toi
	int ret = 0;
//	char *line = "SO    ./textures/grass.xpm    ./textures/stone.png    ";
	t_settings cub_sets;
//	cub_sets.SO = false;
	cub_sets.mlx = mlx_init();
	dprintf(1, "--- test 1 ---\n");
	ft_bzero(&cub_sets, sizeof(t_settings));
	ret = south_texture("SO     ./././     ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "SO = %d\n", cub_sets.SO);
	dprintf(1, "south_texture_fd = %d\n", cub_sets.south_fd);
	dprintf(1, "south_texture_path = |%s|\n", cub_sets.south_texture_path);
	dprintf(1, "--- test 2 ---\n");
	ft_bzero(&cub_sets, sizeof(t_settings));
	ret = south_texture("SO    textures/grass.xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "SO = %d\n", cub_sets.SO);
	dprintf(1, "south_texture_fd = %d\n", cub_sets.south_fd);
	dprintf(1, "south_texture_path = |%s|\n", cub_sets.south_texture_path);
	dprintf(1, "--- test 3 ---\n");
	ft_bzero(&cub_sets, sizeof(t_settings));
	ret = south_texture("SO    38     xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "SO = %d\n", cub_sets.SO);
	dprintf(1, "south_texture_fd = %d\n", cub_sets.south_fd);
	dprintf(1, "south_texture_path = |%s|\n", cub_sets.south_texture_path);
	dprintf(1, "--- test 4 ---\n");
	ft_bzero(&cub_sets, sizeof(t_settings));
	ret = south_texture("SO   38   textures/stone.png   ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "SO = %d\n", cub_sets.SO);
	dprintf(1, "south_texture_fd = %d\n", cub_sets.south_fd);
	dprintf(1, "south_texture_path = |%s|\n", cub_sets.south_texture_path);
	dprintf(1, "--- test 5 ---\n");
	ft_bzero(&cub_sets, sizeof(t_settings));
	ret = south_texture("SO   ./textures/stone.png   ./textures/grass.xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "SO = %d\n", cub_sets.SO);
	dprintf(1, "south_texture_fd = %d\n", cub_sets.south_fd);
	dprintf(1, "south_texture_path = |%s|\n", cub_sets.south_texture_path);
	dprintf(1, "--- test 6 ---\n");
	ft_bzero(&cub_sets, sizeof(t_settings));
	ret = south_texture("SO    ./textures/file.txt    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "SO = %d\n", cub_sets.SO);
	dprintf(1, "south_texture_fd = %d\n", cub_sets.south_fd);
	dprintf(1, "south_texture_path = |%s|\n", cub_sets.south_texture_path);
	dprintf(1, "--- test 7 ---\n");
	ft_bzero(&cub_sets, sizeof(t_settings));
	ret = south_texture("SO    ./textures./grass.xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "SO = %d\n", cub_sets.SO);
	dprintf(1, "south_texture_fd = %d\n", cub_sets.south_fd);
	dprintf(1, "south_texture_path = |%s|\n", cub_sets.south_texture_path);
	dprintf(1, "--- test 8 ---\n");
	ft_bzero(&cub_sets, sizeof(t_settings));
	ret = south_texture("SO    ./textures.xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "SO = %d\n", cub_sets.SO);
	dprintf(1, "south_texture_fd = %d\n", cub_sets.south_fd);
	dprintf(1, "south_texture_path = |%s|\n", cub_sets.south_texture_path);
	dprintf(1, "--- test 9 ---\n");
	ft_bzero(&cub_sets, sizeof(t_settings));
	ret = south_texture("SOrdine    ./textures/grass.xpm    ", &cub_sets);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "SO = %d\n", cub_sets.SO);
	dprintf(1, "south_texture_fd = %d\n", cub_sets.south_fd);
	dprintf(1, "south_texture_path = |%s|\n", cub_sets.south_texture_path);
}
