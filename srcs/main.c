#include "../cub3D.h"
//defines a virer car infos qui doivent etre recup via parsing/a preciser dans le code des keys
//#define screenWidth 640
//#define screenHeight 480
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
	/*if (parse_args(argc, argv, &info) < 0)
	{
		ft_putstr_fd("Error\nParsing failed, please check your args and/or .cub file \
and try again. Keep going !\n", 0);
		printf("Parsed+ capped WIDTH : %d\nParsed+ capped HEIGHT : %d\n",\
info.width, info.height);
		return (-1);
	}
	//printf("\nnb lines map : %d\n", setupnb_lines);
	//printf("longueur line la plus longue de la map : %d\n", setuplongest_line);

	// REMPLACER TOUT CA POUR TOUT FAIRE DANS LE 1ER GNL !!!!
	if (info.map.nb_lines > 0 && info.map.longest_line > 0)
	{
		info.map.size_known = 1;
		//printf("\n\n EZEPARTI ok on lance le 2e GNL\n");
		fd = open(argv[1], O_RDONLY);
		if (fd > 1)
			open_file(&info, fd);
		else
			printf("Error\nProblem with your .cub while working with it.\n");
	}
	printf("La 1e ligne du tab malloqué : [%s]\n", info.setup.map[0]);
	printf("La 14e ligne du tab malloqué : [%s]\n", info.setup.map[13]);*/
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
	(void)argc;
	(void)argv;
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.width, info.height, "mlx");
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_loop(info.mlx);
	/*else
	{
		printf("error\n fichier cub3D manquant");
	}*/
	if (info.map.malloced == 1)
	{
		//free_2d_tab(setup.map, setupnb_lines + 1);
		free(info.setup.map);
	}
	return (0);
}


void	init(t_info *info)
{
	info->height = 720;
	info->width = 1280;
	info->pos_x = 5;
	info->pos_y = 5;
	info->dir_x = -1;
	info->dir_y = 0;
	/* garder l'init de plane_x/Y, rot/move_speed ? */
	info->plane_x = 0;
	info->plane_y = 0.66;
	info->move_speed = 0.5;
	info->rot_speed = 0.05;
	info->bpp = 5;
	info->endian = 1;
	info->line_lenght = 0;
}
