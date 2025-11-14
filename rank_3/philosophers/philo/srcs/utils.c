/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:28:20 by neves             #+#    #+#             */
/*   Updated: 2023/10/18 16:45:27 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

int	error_message(char *msg)
{
	ft_putstr_fd(msg, 1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	signal;

	i = 0;
	result = 0;
	signal = 1;
	while (str[i] && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (str[i] == '-')
		signal = -1;
	if (str[i] == '+' || str[i] == '-')
		str++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + (str[i] - '0');
		str++;
	}
	return (result * signal);
}

void	print_status(t_table *philo, char *status)
{
	pthread_mutex_lock(&philo->data->death.lock);
	if (philo->data->death.status != 1)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%lu %d %s\n", calc_time(), philo->id, status);
		pthread_mutex_unlock(&philo->data->print);
	}
	pthread_mutex_unlock(&philo->data->death.lock);
}
