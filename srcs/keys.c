#include "../cub3D.h"

int	key_hook(int keycode)//, t_miniRT *mini)
{
    //void(&mini);
	if (keycode != 0)
		printf("Hello from key_hook!\n");
	if (keycode == 53)
		printf("Wow you pressed ESC !! R U crazy bro ?\n");
	return (0);
}