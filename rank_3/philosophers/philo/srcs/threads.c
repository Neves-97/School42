/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:13:14 by neves             #+#    #+#             */
/*   Updated: 2023/10/19 13:45:54 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// int create_threads_helper(t_table *philosophers): 
// This function is responsible for creating threads 
// for the philosophers in the dining philosophers 
// problem:
// It takes an array of t_table 
// pointers named philosophers as its parameter. This 
// array represents the philosophers.
// It initializes an integer variable i 
// to 0.
// It enters a loop, iterating over 
// the philosophers based on the number_philosophers attribute 
// of the first philosopher (assuming all philosophers 
// share this value).
// Inside the loop, it uses the 
// pthread_create function to create a new thread 
// for a philosopher. The created thread runs 
// the routine function, passing the respective philosopher's 
// data as a parameter.
// If thread creation fails (i.e., pthread_create 
// returns an error code), the function returns 
// 0 to indicate an error.
// If all threads are successfully created, 
// the function returns 1 to indicate success.

int	create_threads_helper(t_table *philosophers)
{
	int	i;

	i = 0;
	while (i < philosophers[0].data->number_philosophers)
	{
		if (pthread_create(&philosophers[i].philo,
				NULL, &routine, &philosophers[i]))
			return (0);
		i++;
	}
	return (1);
}

// int join_threads(t_table *philosophers): 
// This function is responsible for joining (waiting 
// for the completion of) the threads created 
// for the philosophers:
// It takes an array of t_table 
// pointers named philosophers as its parameter.
// It initializes an integer variable i 
// to 0.
// It enters a loop, iterating over 
// the philosophers based on the number_philosophers attribute 
// of the first philosopher.
// Inside the loop, it uses the 
// pthread_join function to wait for the completion 
// of a philosopher's thread.
// If thread joining fails (i.e., pthread_join 
// returns an error code), the function returns 
// 0 to indicate an error.
// If all threads are successfully joined, 
// the function returns 1 to indicate success.

int	join_threads(t_table *philosophers)
{
	int	i;

	i = 0;
	while (i < philosophers[0].data->number_philosophers)
	{
		if (pthread_join(philosophers[i].philo, NULL))
			return (0);
		i++;
	}
	return (1);
}

// int create_threads(t_table *philosophers): 
// This function serves as the entry point 
// for creating and managing threads for the 
// dining philosophers simulation:
// It takes an array of t_table 
// pointers named philosophers as its parameter.
// It first calls the create_threads_helper function 
// to create threads for the philosophers. If 
// thread creation fails, it returns 0 to 
// indicate an error.
// If thread creation is successful, it 
// proceeds to call the join_threads function to 
// wait for the threads to complete their 
// execution. If any thread fails to join, 
// it returns 0.
// If all threads are successfully created 
// and joined, it calls the free_all function 
// to release any allocated resources, and then 
// returns 1 to indicate success.

int	create_threads(t_table *philosophers)
{
	if (create_threads_helper(philosophers) == 0)
		return (0);
	if (join_threads(philosophers) == 0)
		return (0);
	free_all(philosophers, philosophers->forks);
	return (1);
}
