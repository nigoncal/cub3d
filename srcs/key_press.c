#include "../cub3D.h"


int	key_press(int key, t_info *info)
{

	if (key == K_W)
	{
		if (info->ok.map[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)] == '0')
			info->posX += info->dirX * info->moveSpeed;
		if (info->ok.map[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)] == '0')
			info->posY += info->dirY * info->moveSpeed;
	}
	//move backwards if no wall behind you
	if (key == K_S)
	{
		if (info->ok.map[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)] == '0')
			info->posX -= info->dirX * info->moveSpeed;
		if (info->ok.map[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)] == '0')
			info->posY -= info->dirY * info->moveSpeed;
	}
	//rotate to the right
	if (key == K_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	//rotate to the left
	if (key == K_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}