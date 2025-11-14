/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:10:17 by roda-min          #+#    #+#             */
/*   Updated: 2024/04/08 15:10:20 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	handle_movement_we(int keycode)
{
	int	test_x;
	int	test_y;

	if (keycode == KEY_W)
	{
		test_x = (vars()->player->x + vars()->player->delta_x * 10) / CUBESIZE;
		test_y = (vars()->player->y + vars()->player->delta_y * 10) / CUBESIZE;
		if (vars()->map[test_y][test_x] == 0)
		{
			vars()->player->x += vars()->player->delta_x;
			vars()->player->y += vars()->player->delta_y;
		}
	}
	if (keycode == KEY_S)
	{
		test_x = (vars()->player->x - vars()->player->delta_x * 10) / CUBESIZE;
		test_y = (vars()->player->y - vars()->player->delta_y * 10) / CUBESIZE;
		if (vars()->map[test_y][test_x] == 0)
		{
			vars()->player->y -= vars()->player->delta_y;
			vars()->player->x -= vars()->player->delta_x;
		}
	}
}

void	handle_movement_ns(int keycode)
{
	int	test_x;
	int	test_y;

	if (keycode == KEY_D)
	{
		test_x = (vars()->player->x - vars()->player->delta_y * 10) / CUBESIZE;
		test_y = (vars()->player->y + vars()->player->delta_x * 10) / CUBESIZE;
		if (vars()->map[test_y][test_x] == 0)
		{
			vars()->player->x -= vars()->player->delta_y;
			vars()->player->y += vars()->player->delta_x;
		}
	}
	if (keycode == KEY_A)
	{
		test_x = (vars()->player->x + vars()->player->delta_y * 10) / CUBESIZE;
		test_y = (vars()->player->y - vars()->player->delta_x * 10) / CUBESIZE;
		if (vars()->map[test_y][test_x] == 0)
		{
			vars()->player->x += vars()->player->delta_y;
			vars()->player->y -= vars()->player->delta_x;
		}
	}
}

void	handle_rotation(int keycode)
{
	if (keycode == RIGHT_KEY)
	{
		vars()->player->angle += 0.1;
		if (vars()->player->angle > 2 * PI)
			vars()->player->angle -= 2 * PI;
		vars()->player->delta_x = cos(vars()->player->angle) * 5;
		vars()->player->delta_y = sin(vars()->player->angle) * 5;
	}
	else if (keycode == LEFT_KEY)
	{
		vars()->player->angle -= 0.1;
		if (vars()->player->angle < 0)
			vars()->player->angle += 2 * PI;
		vars()->player->delta_x = cos(vars()->player->angle) * 5;
		vars()->player->delta_y = sin(vars()->player->angle) * 5;
	}
}

int	key_hook(int keycode)
{
	handle_exit(keycode);
	handle_rotation(keycode);
	handle_movement_ns(keycode);
	handle_movement_we(keycode);
	return (0);
}

int	render_hook(void)
{
	t_pos	pos2;

	pos2.color = vars()->ccolor;
	pos2.x = 0;
	pos2.y = 0;
	draw_floor_ceiling(SCREENWIDTH, SCREENHEIGHT / 2, pos2);
	pos2.y = SCREENHEIGHT / 2;
	pos2.color = vars()->fcolor;
	draw_floor_ceiling(SCREENWIDTH, SCREENHEIGHT / 2, pos2);
	rays();
	mlx_put_image_to_window(vars()->win->mlx_ptr, vars()->win->win_ptr, \
	vars()->gra->canvas.img_ptr, 0, 0);
	return (0);
}
