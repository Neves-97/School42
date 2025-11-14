/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:46:19 by neves             #+#    #+#             */
/*   Updated: 2023/10/19 13:47:30 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void init_routine(t_table *phi): 
// This function initializes the state of a 
// philosopher before entering the dining routine:
// It takes a pointer to a 
// t_table structure, phi, as its parameter. This 
// structure represents a philosopher.
// It sets the last_meal attribute of 
// the philosopher to the current time using 
// the get_time function. This will be used 
// to track the time since the philosopher's 
// last meal.
// It checks if the number of 
// philosophers is odd (not divisible by 2) 
// and the current philosopher's id is equal 
// to the total number of philosophers. If 
// this condition is met, it prints that 
// the philosopher is thinking.
// If the philosopher's id is an 
// even number, it also prints that the 
// philosopher is thinking and then sleeps for 
// a duration specified by eating_time using the 
// t_sleep function. This simulates the thinking phase 
// before the dining routine.

void	init_routine(t_table *phi)
{
	phi->last_meal = get_time();
	if (phi->data->number_philosophers % 2 != 0
		&& phi->id == phi->data->number_philosophers)
		print_status(phi, "is thinking");
	if (phi->id % 2 == 0)
	{
		print_status(phi, "is thinking");
		t_sleep(phi->data->eating_time, phi);
	}
}

// void *routine(void *philo): 
// This function represents the routine that each 
// philosopher follows during the dining philosophers simulation:
// It takes a void pointer philo, 
// which is expected to point to a 
// t_table structure, as its parameter.
// Inside the function, it casts the 
// void pointer to a t_table pointer named 
// phi, which is used to work with 
// the philosopher's data.
// It begins by initializing the philosopher's 
// state by calling init_routine(phi), as described in 
// the previous explanation.
// Then, it enters a loop that 
// continues until either the philosopher has eaten 
// the required number of meals or the 
// death_checker function returns a true value (indicating 
// that the philosopher has exceeded the allowed 
// time without eating).
// In each iteration of the loop, 
// the philosopher follows the dining routine: eats, 
// sleeps, and thinks. These actions are executed 
// by calling the functions eating(phi), sleeping(phi), and 
// print_status(phi, "is thinking"), respectively.
// If the philosopher dies during any 
// phase of the loop, it returns a 
// NULL pointer to indicate that the thread 
// should terminate.
// Once the philosopher completes the required 
// number of meals or dies, the function 
// returns a NULL pointer to signal the 
// end of the thread's execution.

void	*routine(void *philo)
{
	t_table	*phi;

	phi = (t_table *)philo;
	init_routine(phi);
	while (phi->number_meals < phi->data->eating_num && !death_checker(phi))
	{
		eating(phi);
		if (is_dead(phi))
			return (NULL);
		sleeping(phi);
		usleep(1000);
		if (is_dead(phi))
			return (NULL);
		print_status(phi, "is thinking");
	}
	return (NULL);
}
