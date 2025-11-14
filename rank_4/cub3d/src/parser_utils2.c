/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:11:41 by roda-min          #+#    #+#             */
/*   Updated: 2024/04/08 15:11:41 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	array_size(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		continue ;
	return (i);
}

int	check_string(char *input_str)
{
	while (*input_str != '\0')
	{
		if (*input_str == '0' || *input_str == '1')
			return (0);
		input_str++;
	}
	return (1);
}

int	check_count(void)
{
	if (vars()->player_cnt != 1 || vars()->no_cnt != 1 \
	|| vars()->so_cnt != 1 || vars()->we_cnt != 1 \
	|| vars()->ea_cnt != 1 || vars()->floor_cnt != 1 \
	|| vars()->ceiling_cnt != 1 || vars()->map_cnt == 0)
		return (0);
	return (1);
}

int	check_format(const char *file)
{
	const char	*dot_name;

	dot_name = ft_strrchr(file, '.');
	if (dot_name != NULL)
	{
		if (ft_strcmp(dot_name, ".cub") == 0)
			return (1);
	}
	return (0);
}

int	is_nbr(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]) && nbr[i] != ' ' && nbr[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
