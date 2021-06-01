
void	draw(t_setup setup)
{

	int x;
	int y;
		x = 0;
		y = 0;
	while (y < height)
	{
		while (x < width)
		{
			setup->game.image = data[y * width + x] = info->buf[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}