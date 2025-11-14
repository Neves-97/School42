/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:16:39 by roda-min          #+#    #+#             */
/*   Updated: 2023/04/12 11:49:22 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	display_error_msg(void)
{
	int	ret;

	ret = 0;
	ret = write(1, "\033[34mError!\n", 14);
	ret = write(1, "\nProgram Usage:\n", 18);
	ret = write(1, "\n./fractol <Fractal>\n", 23);
	ret = write(1, "\nAvailable\n", 13);
	ret = write(1, "\nmandelbrot\n", 14);
	ret = write(1, "\njulia_1\n", 11);
	ret = write(1, "\njulia_2\n", 11);
	ret = write(1, "\njulia_3\n", 11);
	ret = write(1, "\nburning_ship\n", 16);
	ret = write(1, "\033[0m\n", 7);
	(void) ret;
	exit(0);
	return (0);
}

int	arg_parser(int ac, char **av, t_data *data)
{
	if (ac < 2)
		return (display_error_msg());
	else if (ft_strncmp(av[1], "julia_1", 8) == 0)
		data->fractal_type = 3;
	else if (ft_strncmp(av[1], "julia_2", 8) == 0)
		data->fractal_type = 4;
	else if (ft_strncmp(av[1], "julia_3", 8) == 0)
		data->fractal_type = 5;
	else if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
		data->fractal_type = 1;
	else if (ft_strncmp(av[1], "burning_ship", 13) == 0)
		data->fractal_type = 2;
	else
		return (display_error_msg());
	draw_fractal(data->fractal_type, data);
	return (0);
}
