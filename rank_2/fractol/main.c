/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:18:18 by roda-min          #+#    #+#             */
/*   Updated: 2023/04/11 17:16:46 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	*initialize_data(void)
{
	t_data	*pointer;

	pointer = malloc(sizeof(t_data));
	pointer->mlx_ptr = mlx_init();
	pointer->win_ptr = mlx_new_window(pointer->mlx_ptr,
			W_W, WINDOW_HEIGHT, "fractol");
	pointer->img = mlx_new_image(pointer->mlx_ptr, W_W, WINDOW_HEIGHT);
	pointer->addr = mlx_get_data_addr(pointer->img, &pointer->bits_per_pixel,
			&pointer->line_length, &pointer->endian);
	pointer->zoom = 4.5;
	pointer->off_x = 0.0;
	pointer->off_y = 0.0;
	pointer->fractal_type = 0;
	return (pointer);
}

void	free_data(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
}

static int	is_valid(char *set)
{
	if ((ft_strncmp(set, "mandelbrot", 10)
			&& ft_strncmp(set, "burning_ship", 13)
			&& ft_strncmp(set, "julia_1", 8)
			&& ft_strncmp(set, "julia_2", 8)
			&& ft_strncmp(set, "julia_3", 8)))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2 || !is_valid(av[1]))
	{
		display_error_msg();
		return (0);
	}
	data = initialize_data();
	arg_parser(ac, av, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	hooks(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
