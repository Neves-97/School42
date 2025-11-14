/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizontal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:07:52 by roda-min          #+#    #+#             */
/*   Updated: 2024/04/08 15:08:00 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	init_horizontal(double ra)
{
	vars()->rays.dof = 0;
	vars()->rays.dh = 1000000;
	vars()->rays.hx = vars()->player->x;
	vars()->rays.hy = vars()->player->y;
	vars()->rays.atan = -1 / tan(ra);
}

void	horizontal_utils(void)
{
	vars()->rays.mx = (int)(vars()->rays.rx) >> 6;
	vars()->rays.my = (int)(vars()->rays.ry) >> 6;
	vars()->rays.mp = vars()->rays.my * vars()->map_width + vars()->rays.mx;
	if (vars()->rays.mx < 0 || vars()->rays.my < 0 \
		|| vars()->rays.mx > vars()->map_width
		|| vars()->rays.my > vars()->map_height)
		vars()->rays.mp = vars()->map_width * vars()->map_height;
}

void	loop_horizontal(void)
{
	double	dh;

	horizontal_utils();
	if (vars()->rays.mp > 0 && vars()->rays.mp < vars()->map_width \
		* vars()->map_height \
		&& vars()->map[vars()->rays.my][vars()->rays.mx] == 1)
	{
		vars()->rays.hx = vars()->rays.rx;
		vars()->rays.hy = vars()->rays.ry;
		dh = distance(vars()->player->x, vars()->player->y, \
		vars()->rays.hx, vars()->rays.hy);
		vars()->rays.dh = dh;
		vars()->rays.dof = MAXSIZE;
	}
	else
	{
		vars()->rays.rx += vars()->rays.xo;
		vars()->rays.ry += vars()->rays.yo;
		vars()->rays.dof += 1;
	}
}

void	check_horizontal(double ra)
{
	init_horizontal(ra);
	look_north_south(ra);
	look_west_east(ra);
	while (vars()->rays.dof < MAXSIZE)
		loop_horizontal();
}
