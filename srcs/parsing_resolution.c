#include "../cub3D.h"

int	cap_resolution(t_info *info)
{
	if (info->width <= 0 || info->height <= 0)
	{
		ft_putstr_fd("Error\nResolution parsing failed because of negative \
values, check your .cub file please <3\n", 0);
		return (-1);
	}
	mlx_get_screen_size(info->mlx, &info->max_w, &info->setup.max_h);
	if (info->setup.max_w == 0 || info->setup.max_h == 0)
	{
		printf("Error\nMLX couldn't get your screen's size. sorry bro.\n");
		return (-1);
	}
	if (info->width > info->setup.max_w)
		info->width = info->setup.max_w;
	else if (info->setup.max_w != info->width)
		info->setup.max_w = info->width;
	if (info->height > info->setup.max_h)
		info->height = info->setup.max_h;
	else if (info->setup.max_h != info->height)
		info->setup.max_h = info->height;
	return (0);
}

int	parse_resolution(char **tab, t_info *info)
{
	int	i;
	int l;

	i = 0;
	l = 0;
	info->width = 0;
	info->height = 0;
	while (tab[l] != 0)
		l++;
	if (l != 3)
		return (-1);
	l = 1;
	i += skip_ws(tab[l]);
	info->width = ft_atoi(tab[l]);
	//printf("res W = %d\n", info->width);
	l++;
	i += skip_ws(tab[l]);
	info->height = ft_atoi(tab[l]);
	//printf("res H = %d\n", info->height);
	return (0);
}