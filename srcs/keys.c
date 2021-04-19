#include "../cub3D.h"

int	key_hook(int keycode)//, t_miniRT *mini)
{
    //void(&mini);
	if (keycode)
		printf("Hello from key_hook!\n");
	if (keycode == 53)
		printf("Wow you pressed ESC !! R U crazy bro ?\n");
	/*if (keycode == 13)
		//go forward
	if (keycode == 1)
		//go backward
	if (keycode == 0)
		//go left
	if (keycode == 2)
		//go right*/
	return (0);
}
