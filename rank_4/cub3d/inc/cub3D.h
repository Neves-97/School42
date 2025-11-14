/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:53:49 by neves             #+#    #+#             */
/*   Updated: 2024/04/02 08:31:21 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"
# include "structs.h"
# include "defines.h"

// check_horizontal.c

void	check_horizontal(double ra);

// check_map.c

int		check_map(void);

// check_vertical.c

void	check_vertical(double ra);

// colors.c

void	color_limits(int *red, int *green, int *blue);
int		rgb_to_int(int red, int green, int blue);
void	check_hit(void);

// direction.c

void	look_north_south(double ra);
void	look_west_east(double ra);
void	west_east(double ra);
void	north_south(double ra);

// draw_utils.c

void	draw_utils(void);
void	wall_collision(void);
t_img	wall_image(void);
void	draw_floor_ceiling(int width, int height, t_pos pos);

// draw.c

void	rays(void);
void	draw_all(void);

// exit.c

void	free_array(char **array);
int		free_all(int exit_status);
void	handle_exit(int keycode);

// hook.c

int		key_hook(int keycode);
int		render_hook(void);

// image.c

void	put_pixel(t_img img, int x, int y, int color);
int		get_pixel(t_img img, int pixel);
t_img	new_image(int w, int h, t_win window);
t_win	init_window(int w, int h, char *str);

// inits.c

void	init_rays(void);
void	init_player_pos(void);
void	inits(char *file_path);

// parser_utils.c

int		validate_string(char *input_str);

// parser_utils2.c

int		array_size(char **array);
int		check_string(char *input_str);
int		check_count(void);
int		check_format(const char *file);
int		is_nbr(char *nbr);

// parser.c

void	parser(char *file);

// utils.c
t_var	*vars(void);
int		check_images(void);
double	distance(int ax, int ay, int bx, int by);

#endif
