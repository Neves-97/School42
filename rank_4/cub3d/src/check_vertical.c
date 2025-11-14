/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:08:44 by roda-min          #+#    #+#             */
/*   Updated: 2024/04/08 15:08:47 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	init_vertical(double ra)
{
	vars()->rays.dof = 0;
	vars()->rays.dv = 1000000;
	vars()->rays.vx = vars()->player->x;
	vars()->rays.vy = vars()->player->y;
	vars()->rays.ntan = -tan(ra);
}

void	vertical_utils(void)
{
	vars()->rays.mx = (int)(vars()->rays.rx) >> 6;
	vars()->rays.my = (int)(vars()->rays.ry) >> 6;
	vars()->rays.mp = vars()->rays.my * vars()->map_width + vars()->rays.mx;
	if (vars()->rays.mx < 0 || vars()->rays.my < 0
		|| vars()->rays.mx > vars()->map_width \
		|| vars()->rays.my > vars()->map_height)
		vars()->rays.mp = vars()->map_width * vars()->map_height;
}

void	loop_vertical(void)
{
	double	dv;

	vertical_utils();
	if (vars()->rays.mp > 0 && vars()->rays.mp < vars()->map_width \
		* vars()->map_height \
		&& vars()->map[vars()->rays.my][vars()->rays.mx] == 1)
	{
		vars()->rays.vx = vars()->rays.rx;
		vars()->rays.vy = vars()->rays.ry;
		dv = distance(vars()->player->x, vars()->player->y, \
		vars()->rays.vx, vars()->rays.vy);
		vars()->rays.dv = dv;
		vars()->rays.dof = MAXSIZE;
	}
	else
	{
		vars()->rays.rx += vars()->rays.xo;
		vars()->rays.ry += vars()->rays.yo;
		vars()->rays.dof += 1;
	}
}

void	check_vertical(double ra)
{
	init_vertical(ra);
	west_east(ra);
	north_south(ra);
	while (vars()->rays.dof < MAXSIZE)
		loop_vertical();
}
