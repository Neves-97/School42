/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:11:33 by roda-min          #+#    #+#             */
/*   Updated: 2024/04/08 15:11:34 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	fill_map_line(int index)
{
	while (index < MAXSIZE)
	{
		vars()->map[vars()->map_height][index] = 2;
		index++;
	}
}

int	is_valid_character(char c)
{
	if ((c - '0') == 0 || (c - '0') == 1)
		vars()->map_cnt++;
	if ((c - '0') == 0 || (c - '0') == 1 || \
		c == 'N' || c == 'S' || \
		c == 'E' || c == 'W' || \
		c == ' ')
		return (1);
	else
		return (0);
}

void	validate_aux(char c, int index)
{
	vars()->player->orientation = c;
	vars()->player->startx = index;
	vars()->player->starty = vars()->map_height;
}

int	process_character(char *input_str, int index)
{
	char	c;

	c = input_str[index];
	if (!is_valid_character(c))
	{
		free(input_str);
		free_all(printf("Error\nInvalid character\n") != 0);
	}
	if (c == 'N' || c == 'S' || \
		c == 'E' || c == 'W')
	{
		vars()->player_cnt++;
		validate_aux(c, index);
		c = '0';
	}
	if (c == ' ')
		c = '2';
	vars()->map[vars()->map_height][index] = (c - '0');
	return (0);
}

int	validate_string(char *input_str)
{
	int	index;

	index = 0;
	vars()->player->angle = 0;
	while (input_str[index] != '\0')
	{
		if (process_character(input_str, index) != 0)
			return (1);
		index++;
	}
	fill_map_line(index);
	return (0);
}
