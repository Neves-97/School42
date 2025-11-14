/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:25:56 by neves             #+#    #+#             */
/*   Updated: 2023/10/19 14:59:36 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// uint64_t get_time(void): This 
// function retrieves the current time in milliseconds. 
// It does the following:
// It uses the gettimeofday function to 
// get the current time in seconds and 
// microseconds since the Epoch.
// If gettimeofday fails, it returns 0 
// to indicate an error.
// If gettimeofday succeeds, it converts the 
// time to milliseconds and returns it as 
// a uint64_t value.

uint64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((uint64_t)(tv.tv_sec * 1000) + (uint64_t)(tv.tv_usec / 1000));
}

// void t_sleep(uint64_t time, 
// t_table *philo): This function is used to 
// make a philosopher sleep for a specified 
// amount of time (in milliseconds). Here's how 
// it works:
// It records the starting time using 
// the get_time function to measure the duration 
// of the sleep.      
// It enters a while loop that 
// continues as long as the time elapsed 
// since the start is less than the 
// desired sleep time.      
// Inside the loop, it checks if 
// the philosopher is dead by calling death_checker(philo). 
// If the philosopher is dead, it returns, 
// effectively terminating the sleep.      
// It uses usleep to pause the 
// execution for a fraction (1/10th) of the 
// desired sleep time.
// After the loop, it calls death_checker(philo) 
// again to ensure that the philosopher is 
// not dead. This is done to account 
// for the possibility that the philosopher died 
// during the sleep.

void	t_sleep(uint64_t time, t_table *philo)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < time)
	{
		if (death_checker(philo))
			return ;
		usleep(time / 10);
	}
	death_checker(philo);
}
// uint64_t calc_time(void): This 
// function calculates the elapsed time in milliseconds 
// since the start of the program. It 
// does the following:
// It subtracts the start time (retrieved 
// from get()->start) from the current time (retrieved 
// using the get_time function).
// The result, which represents the elapsed 
// time in milliseconds, is returned as a 
// uint64_t value.

uint64_t	calc_time(void)
{
	uint64_t	total;

	total = get_time() - get()->start;
	return (total);
}
