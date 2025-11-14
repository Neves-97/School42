/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:10:28 by roda-min          #+#    #+#             */
/*   Updated: 2024/04/08 15:10:29 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	put_pixel(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

int	get_pixel(t_img img, int pixel)
{
	char	*src;
	int		color;

	if (pixel >= 0 && pixel < img.w * img.h)
	{
		src = img.addr + (pixel * (img.bpp / 8));
		color = *(unsigned int *)src;
		return (color);
	}
	return (-1);
}

t_img	new_image(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), \
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

t_win	init_window(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	{
		free(vars()->gra);
		exit(printf("Error\nmlx_init failed\n"));
	}
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}
