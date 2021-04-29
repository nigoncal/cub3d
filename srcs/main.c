#include "../cub3D.h"
//defines a virer car infos qui doivent etre recup via parsing/a preciser dans le code des keys
#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17

int	main(int argc, char **argv)
{
	t_info	info;
	int		fd;

	fd = 0;
	ft_bzero(&info, sizeof(info));
	init(&info);
	/* my part : */
	if (parse_args(argc, argv, &info) < 0)
	{
		ft_putstr_fd("Error\nParsing failed, please check your args and/or .cub file \
and try again. Keep going !\n", 0);
		return (-1);
	}
	//printf("\nnb lines map : %d\n", setup.map_nb_lines);
	//printf("longueur line la plus longue de la map : %d\n", setup.map_longest_line);
	if (info.map_info.map_nb_lines > 0 && info.map_info.map_longest_line > 0)
	{
		info.map_info.map_size_known = 1;
		//printf("\n\n EZEPARTI ok on lance le 2e GNL\n");
		fd = open(argv[1], O_RDONLY);
		if (fd > 1)
			open_file(&info, fd);
		else
			printf("Error\nProblem with your .cub while working with it.\n");
	}
	printf("La 1e ligne du tab malloqué : [%s]\n", info.ok.map[0]);
	printf("La 14e ligne du tab malloqué : [%s]\n", info.ok.map[13]);
	//init_windows(&mini);
	//init_ray(&direction, mini);
	//assigned_vector(&sphere.origine, 0, 0, -60);
	//gen_ray(&mini, &sphere);
	//mlx_put_image_to_window(mini.mlx, mini.win, mini.image, 0, 0);
	//mlx_loop(mini.mlx);
	if (info.map_info.map_malloced == 1)
	{
		//free_2d_tab(setup.map, setup.map_nb_lines + 1);
		free(info.ok.map);
	}
	/* fin de ma partie */

	/*ajouter parsing ici*/
	/*if (argc == 2)
	{
		char *line;
		int fd = open(argv[1], O_RDONLY);
		int result = 1;*/

	/*lancement GNL là*/
	/*while((result = get_next_line(fd, &line) == 1))
	{
			ft_map(line, &info.ok); // recup map
	}
		ft_map(line, &info.ok); // recup map
		printf("\n");
		int j = 0;
		while(info.ok.map[j])
		{
			//printf("%s\n", info.ok.map[j]);
			j++;	
		}
*/
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.width, info.height, "mlx");
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_loop(info.mlx);
	/*else
	{
		printf("error\n fichier cub3D manquant");
	}*/
}


void	init(t_info *info)
{
	info->height = 720;
	info->width = 1280;
	info->posX = 5;
	info->posY = 5;
	info->dirX = -1;
	info->dirY = 0;
	/* garder l'init de planeX/Y, rot/moveSpeed ? */
	info->planeX = 0;
	info->planeY = 0.66;
	info->moveSpeed = 0.5;
	info->rotSpeed = 0.05;
	info->BPP = 5;
	info->endian = 1;
	info->line_lenght = 0;
}
