/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:44:13 by roda-min          #+#    #+#             */
/*   Updated: 2023/04/12 11:30:20 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include "mlx_linux/mlx.h"
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <unistd.h>
# include <string.h>

# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define W_W 800
# define WINDOW_HEIGHT 800
# define MLX_ERROR 1
# define DESTROY_NOTIFY 17
# define SCROLL_UP 5
# define SCROLL_DOWN 4

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	off_x;
	double	off_y;
	double	julia_re;
	double	julia_im;
	int		fractal_type;
}	t_data;

typedef struct s_complex
{
	double			re;
	double			im;
}			t_complex;

// main

t_data		*initialize_data(void);
void		free_data(t_data *data);
int			main(int ac, char **av);

//arg parser

int			display_error_msg(void);
int			arg_parser(int ac, char **av, t_data *data);

// utils

int			ft_strncmp(const char *str1, const char *str2, size_t n);
void		*ft_memset(void *b, int c, size_t len);

// draw

void		my_pixel_put(t_data *data, int x, int y, int color);
void		draw_fractal(int fractal_type, t_data *data);

// events

int			close_window(t_data *pointer);
int			mouse_scroll(int keycode, int x, int y, void *param);
int			move_pos(int keysum, t_data *pointer);
void		hooks(t_data *pointer);

// julia

void		julia(t_data *data);
int			iterate_julia(t_complex c, t_complex z);
void		set_julia_params(t_data *data, double re, double im);

// burning

int			iterate_ship(t_complex *c, t_complex *z);
void		burning_ship(t_data *data);

// get c

t_complex	calculate_c(int i, int j, t_data *data);

// get z

t_complex	calculate_z(int i, int j, t_data *data);

// mandel

void		mandelbrot(t_data *data);
int			iterate_mandelbrot(t_complex *c, t_complex *z);

#endif