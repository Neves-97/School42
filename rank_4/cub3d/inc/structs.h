/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:53:44 by neves             #+#    #+#             */
/*   Updated: 2024/03/25 14:53:44 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_oam
{
	char	orientation;
	double	angle;
}	t_oam;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}	t_color;

typedef struct s_rays
{
	int			ray;
	int			mx;
	int			my;
	int			mp;
	int			dof;
	double		rx;
	double		ry;
	double		angle;
	double		xo;
	double		yo;
	double		atan;
	double		ntan;
	double		dist;
	double		dh;
	double		dv;
	double		vx;
	double		vy;
	double		hx;
	double		hy;
}	t_rays;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_data;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
}	t_win;

typedef struct s_img
{
	t_win		win;
	void		*img_ptr;
	char		*addr;
	int			h;
	int			w;
	int			bpp;
	int			endian;
	int			line_len;
}	t_img;

typedef struct s_player
{
	double		x;
	double		y;
	int			size;
	double		angle;
	double		delta_x;
	double		delta_y;
	int			startx;
	int			starty;
	char		orientation;
}	t_player;

typedef struct s_position
{
	int			x;
	int			y;
	int			color;
}	t_pos;

typedef struct s_gra
{
	t_img			wall;
	t_img			floor;
	t_img			ceil_img;
	t_img			floor_img;
	t_img			teste;
	t_img			no;
	t_img			so;
	t_img			we;
	t_img			ea;
	t_img			canvas;
}	t_gra;

typedef struct s_var
{
	t_rays		rays;
	t_win		*win;
	t_gra		*gra;
	t_color		color;
	int			player_cnt;
	int			no_cnt;
	int			so_cnt;
	int			we_cnt;
	int			ea_cnt;
	int			floor_cnt;
	int			ceiling_cnt;
	int			map_cnt;
	int			fcolor;
	int			ccolor;
	t_player	*player;
	int			map[100][100];
	int			map_width;
	int			map_height;
	double		dr;
	float		ca;
	float		line_h;
	float		ty_step;
	float		ty;
	float		tx;
	float		ty_off;
	int			pix_size;
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
}	t_var;

#endif