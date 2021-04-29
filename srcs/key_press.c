#include "../cub3D.h"


int	key_press(int key, t_info *info)
{

	if (key == K_W)
	{
		if (info->setup.map[(int)(info->pos_x + info->dir_x * info->move_speed)][(int)(info->pos_y)] == '0')
			info->pos_x += info->dir_x * info->move_speed;
		if (info->setup.map[(int)(info->pos_x)][(int)(info->pos_y + info->dir_y * info->move_speed)] == '0')
			info->pos_y += info->dir_y * info->move_speed;
	}
	//move backwards if no wall behind you
	if (key == K_S)
	{
		if (info->setup.map[(int)(info->pos_x - info->dir_x * info->move_speed)][(int)(info->pos_y)] == '0')
			info->pos_x -= info->dir_x * info->move_speed;
		if (info->setup.map[(int)(info->pos_x)][(int)(info->pos_y - info->dir_y * info->move_speed)] == '0')
			info->pos_y -= info->dir_y * info->move_speed;
	}
	//rotate to the right
	if (key == K_D)
	{
		//both camera direction and camera plane must be rotated
		double olddir_x = info->dir_x;
		info->dir_x = info->dir_x * cos(-info->rot_speed) - info->dir_y * sin(-info->rot_speed);
		info->dir_y = olddir_x * sin(-info->rot_speed) + info->dir_y * cos(-info->rot_speed);
		double oldplane_x = info->plane_x;
		info->plane_x = info->plane_x * cos(-info->rot_speed) - info->plane_y * sin(-info->rot_speed);
		info->plane_y = oldplane_x * sin(-info->rot_speed) + info->plane_y * cos(-info->rot_speed);
	}
	//rotate to the left
	if (key == K_A)
	{
		//both camera direction and camera plane must be rotated
		double olddir_x = info->dir_x;
		info->dir_x = info->dir_x * cos(info->rot_speed) - info->dir_y * sin(info->rot_speed);
		info->dir_y = olddir_x * sin(info->rot_speed) + info->dir_y * cos(info->rot_speed);
		double oldplane_x = info->plane_x;
		info->plane_x = info->plane_x * cos(info->rot_speed) - info->plane_y * sin(info->rot_speed);
		info->plane_y = oldplane_x * sin(info->rot_speed) + info->plane_y * cos(info->rot_speed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}