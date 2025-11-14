/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:08:58 by roda-min          #+#    #+#             */
/*   Updated: 2024/04/08 15:09:01 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	color_limits(int *red, int *green, int *blue)
{
	if (*red > 255)
		*red = 255;
	if (*green > 255)
		*green = 255;
	if (*blue > 255)
		*blue = 255;
	if (*red < 0)
		*red = 0;
	if (*green < 0)
		*green = 0;
	if (*blue < 0)
		*blue = 0;
}

int	rgb_to_int(int red, int green, int blue)
{
	color_limits(&red, &green, &blue);
	return (red << 16 | green << 8 | green << 8 | blue);
}

void	check_hit(void)
{
	if (vars()->rays.dv <= vars()->rays.dh)
	{
		vars()->rays.rx = vars()->rays.vx;
		vars()->rays.ry = vars()->rays.vy;
		vars()->rays.dist = vars()->rays.dv;
	}
	if (vars()->rays.dv > vars()->rays.dh)
	{
		vars()->rays.rx = vars()->rays.hx;
		vars()->rays.ry = vars()->rays.hy;
		vars()->rays.dist = vars()->rays.dh;
	}
}

void	init_colors(void)
{
	t_color	*color;

	color = &(vars()->color);
	color->r = 0;
	color->g = 0;
	color->b = 0;
}
