/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:29:23 by neves             #+#    #+#             */
/*   Updated: 2023/10/19 14:17:51 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// is_dead(t_table *philo): This function is used to check if a 
// philosopher is considered dead. It works as follows:
// It locks the death.lock mutex to ensure that only one thread can 
// access the death structure at a time.
// It checks the status field of the death structure. If status 
// is equal to 1, it means the philosopher is considered dead, 
// and the function returns 1 to indicate this.
// If the status is not 1, the function unlocks the death.lock 
// mutex and returns 0 to indicate that the philosopher is not dead.
// This function is useful for checking whether the philosopher's 
// death status has been set elsewhere in the code, which might indicate 
// that they have died.

int	is_dead(t_table *philo)
{
	pthread_mutex_lock(&philo->data->death.lock);
	if (philo->data->death.status == 1)
	{
		pthread_mutex_unlock(&philo->data->death.lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death.lock);
	return (0);
}

// death_checker(t_table *philo): This function is used to check 
//whether a philosopher 
// should be considered dead based on a specific condition. 
//It has a few steps:
// It locks the death.lock mutex to ensure exclusive access to 
//the death structure.
// It calculates the time elapsed since the philosopher's last 
//meal using get_time() 
// and compares it to the death_time value specified in the 
//philosopher's configuration.
// If the time elapsed is greater than or equal to the death_time, the
// philosopher is considered to have died or should be marked as dead.
// If the philosopher's status in the death structure is already set to 1
// (indicating death), it unlocks the mutex, returning 1
//to signify that the
// philosopher is considered dead
// If the philosopher's status is not set to 1, it means
//this is the first
// time they are considered dead. In this case:
// It locks the data->print mutex to ensure safe printing 
// (it seems to be used for output).
// It prints a message indicating the philosopher's ID and the 
// fact that they have died along with the time it occurred.
// It sets the status to 1 to indicate that the philosopher 
//is now considered dead.
// It unlocks both the data->print mutex and the death.lock mutex.
// Finally, the function returns 1 if the philosopher is 
//considered dead 
// (either previously marked as dead or marked as dead in this function). 
// Otherwise, it returns 0.

int	death_checker(t_table *philo)
{
	pthread_mutex_lock(&philo->data->death.lock);
	if (get_time() - (uint64_t)philo->last_meal
		>= (uint64_t)philo->data->death_time)
	{
		if (philo->data->death.status == 1)
		{
			pthread_mutex_unlock(&philo->data->death.lock);
			return (1);
		}
		pthread_mutex_lock(&philo->data->print);
		printf("%lu %d died\n", calc_time(), philo->id);
		pthread_mutex_unlock(&philo->data->print);
		philo->data->death.status = 1;
		pthread_mutex_unlock(&philo->data->death.lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death.lock);
	return (0);
}
