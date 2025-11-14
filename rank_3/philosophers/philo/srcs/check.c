/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:23:21 by neves             #+#    #+#             */
/*   Updated: 2023/10/19 12:35:21 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_valid(char *str)
{
	int		signal;
	long	result;
	int		i;

	signal = 1;
	result = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
		return (0);
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (result * signal > INT_MAX || result * signal < INT_MIN)
			return (0);
	}
	return (str[i] == '\0');
}

int	check_argument_validity(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (error_message("wrong number of arguments\n"));
	if (!check_argument_validity(argc, argv))
		return (error_message("wrong values, put nothing but characters\n"));
	return (1);
}
