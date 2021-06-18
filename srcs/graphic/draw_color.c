/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:58:14 by nigoncal          #+#    #+#             */
/*   Updated: 2021/06/18 12:18:00 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

void draw_celling(t_setup *setup)
{
    int i;
        i = 0;

        while (i < setup->game.drawstart - 1)
		{
			setup->game.buf[i][setup->x] = setup->game.f_color.color;
			i++;
		}
}

void     draw_floor (t_setup *setup)
{
    int i;
    	i = setup->game.drawend;
		while (i < setup->height - 1)
		{
			setup->game.buf[i][setup->x] = setup->game.c_color.color;
			i++;
		}
}
