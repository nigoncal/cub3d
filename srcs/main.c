#include "../cub3D.h"
#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17




int	main(void)
{
	t_info info;
	init(&info);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.width, info.height, "mlx");
	mlx_loop_hook(info.mlx, &main_loop, &info);		
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_loop(info.mlx);
}

void	init(t_info *info)
{
	
	info->height = 720;
	info->width = 1280;
	info->posX = 12;
	info->posY = 5;
	info->dirX = -1;
	info->dirY = 0;
	info->planeX = 0;
	info->planeY = 0.66;
	info->moveSpeed = 0.5;
	info->rotSpeed = 0.05;
	info->BPP = 3;
	info->endian = 0;
	info->line_lenght = 0;

}
