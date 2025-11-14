/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:11:14 by roda-min          #+#    #+#             */
/*   Updated: 2024/04/08 15:11:15 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	init_rays(void)
{
	t_rays	*rays;

	rays = &(vars()->rays);
	rays->dist = 0;
	rays->xo = 0;
	rays->yo = 0;
	rays->rx = 0;
	rays->ry = 0;
	rays->angle = vars()->player->angle - (vars()->dr * SCREENWIDTH / 2);
	while (rays->angle < 0)
		rays->angle += 2 * PI;
	while (rays->angle >= 2 * PI)
		rays->angle -= 2 * PI;
}

void	init_player_pos(void)
{
	t_pos		pos;
	t_player	*player;

	player = vars()->player;
	pos.x = player->startx * CUBESIZE + CUBESIZE / 2;
	pos.y = player->starty * CUBESIZE + CUBESIZE / 2;
	player->x = pos.x;
	player->y = pos.y;
}

void	init_player(void)
{
	if (vars()->player->orientation == 'N')
		vars()->player->angle = -P2;
	else if (vars()->player->orientation == 'S')
		vars()->player->angle = P2;
	else if (vars()->player->orientation == 'E')
		vars()->player->angle = 0;
	else if (vars()->player->orientation == 'W')
		vars()->player->angle = PI;
	vars()->player->delta_x = cos(vars()->player->angle) * 5;
	vars()->player->delta_y = sin(vars()->player->angle) * 5;
}

void	init_vars(void)
{
	static t_player		player;

	vars()->gra = malloc(sizeof(t_gra));
	if (!vars()->gra)
		exit(printf("Error\nMalloc failed\n"));
	vars()->gra->no.img_ptr = NULL;
	vars()->gra->so.img_ptr = NULL;
	vars()->gra->we.img_ptr = NULL;
	vars()->gra->ea.img_ptr = NULL;
	vars()->gra->canvas.img_ptr = NULL;
	vars()->player_cnt = 0;
	vars()->no_cnt = 0;
	vars()->so_cnt = 0;
	vars()->we_cnt = 0;
	vars()->ea_cnt = 0;
	vars()->floor_cnt = 0;
	vars()->ceiling_cnt = 0;
	vars()->map_cnt = 0;
	vars()->player = &player;
}

void	inits(char *file_path)
{
	static t_win		window;
	static t_img		canvas;

	init_vars();
	window = init_window(SCREENWIDTH, SCREENHEIGHT, "cub3d");
	vars()->win = &window;
	if (!check_format(file_path))
		free_all(printf("Error:\nWrong file extension\n") != 0);
	parser(file_path);
	if (!check_count())
		free_all(printf("Error\nWrong number of elements\n"));
	if (!check_images())
		free_all(printf("Error\nWrong texture path\n") != 0);
	if (!check_map() || !vars()->player->orientation)
		free_all(printf("Error\nInvalid map\n") != 0);
	canvas = new_image(SCREENWIDTH, SCREENHEIGHT, window);
	vars()->gra->canvas = canvas;
	init_player();
	draw_all();
}
