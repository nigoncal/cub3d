#include "../cub3D.h"

int	cap_resolution(t_setup *setup)
{
	if (setup->res_w <= 0 || setup->res_h <= 0)
	{
		ft_putstr_fd("Error\nResolution parsing failed because of negative \
values, check your .cub file please <3\n", 0);
		return (-1);
	}
	mlx_get_screen_size(setup->mlx, &setup->max_w, &setup->max_h);
	if (setup->max_w == 0 || setup->max_h == 0)
	{
		printf("Error\nMLX couldn't get your screen's size. Sorry bro.\n");
		return (-1);
	}
	if (setup->res_w > setup->max_w)
		setup->res_w = setup->max_w;
	else if (setup->max_w != setup->res_w)
		setup->max_w = setup->res_w;
	if (setup->res_h > setup->max_h)
		setup->res_h = setup->max_h;
	else if (setup->max_h != setup->res_h)
		setup->max_h = setup->res_h;
	return (0);
}

int	parse_resolution(char **tab, t_setup *setup)
{
	int	i;
	int l;

	i = 0;
	l = 0;
	setup->res_w = 0;
	setup->res_h = 0;
	while (tab[l] != 0)
		l++;
	if (l != 3)
		return (-1);
	l = 1;
	i += skip_ws(tab[l]);
	setup->res_w = ft_atoi(tab[l]);
	//printf("res W = %d\n", setup->res_w);
	l++;
	i += skip_ws(tab[l]);
	setup->res_h = ft_atoi(tab[l]);
	//printf("res H = %d\n", setup->res_h);
	return (0);
}