/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:13:54 by roda-min          #+#    #+#             */
/*   Updated: 2023/04/14 11:32:59 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_julia(t_complex c, t_complex z)
{
	int		n;
	double	x;
	double	y;

	n = 0;
	while (n < 100 && (z.re * z.re + z.im * z.im) < 4.0)
	{
		x = z.re;
		y = z.im;
		z.re = x * x - y * y + c.re;
		z.im = 2 * x * y + c.im;
		n++;
	}
	return (n);
}

void	set_julia_params(t_data *data, double re, double im)
{
	data->julia_re = re;
	data->julia_im = im;
}

t_complex	calculate_z(int i, int j, t_data *data)
{
	t_complex	z;

	z = (t_complex)
	{
		(i - W_W / 2.0) * data->zoom / W_W + data->off_x,
		(j - W_W / 2.0) * data->zoom / W_W + data->off_y
	};
	return (z);
}

void	julia(t_data *data)
{	
	int			i;
	int			j;
	int			n;
	t_complex	c;
	t_complex	z;

	c.re = data->julia_re;
	c.im = data->julia_im;
	i = 0;
	while (i < W_W)
	{
		j = 0;
		while (j < W_W)
		{
			z = calculate_z(i, j, data);
			n = iterate_julia(c, z);
			if (n < 100)
				my_pixel_put(data, i, j, 0x000101 * n * 0x000f0f);
			j++;
		}
		i++;
	}
}
