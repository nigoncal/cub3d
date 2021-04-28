#include "../cub3D.h"
#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17




int	main(int argc, char **argv)
{
	t_info info;
	//ft_putstr_fd("salut", 1);	
 	ft_bzero(&info, sizeof(info));
	init(&info);
	if(argc == 2)
	{
		char *line;
		int fd = open(argv[1], O_RDONLY);
		int result = 1;

	while((result = get_next_line(fd, &line) == 1))
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

	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.width, info.height, "mlx");
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_loop(info.mlx);
	}
	else
	{
		printf("error\n fichier cub3D manquant");
	}
}


void	init(t_info *info)
{
	info->height = 720;
	info->width = 1280;
	info->posX = 5;
	info->posY = 5;
	info->dirX = -1;
	info->dirY = 0;
	info->planeX = 0;
	info->planeY = 0.66;
	info->moveSpeed = 0.5;
	info->rotSpeed = 0.05;
	info->BPP = 5;
	info->endian = 1;
	info->line_lenght = 0;
}
