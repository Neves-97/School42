/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:32:26 by neves             #+#    #+#             */
/*   Updated: 2023/10/19 14:02:40 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void free_forks(t_fork *forks): This function is responsible 
// for freeing the resources associated with the 
// forks. It takes an array of t_fork 
// structures (forks) as input. Here's what it 
// does: It initializes a counter i to 0.
// If the forks pointer is not 
// NULL, it enters a loop.
// Inside the loop, it destroys the 
// mutex associated with each fork by calling 
// pthread_mutex_destroy(&forks[i].lock). This step ensures that the mutexes 
// are properly cleaned up.
// It increments the counter i.
// Finally, it frees the memory associated 
// with the forks array using free(forks).

void	free_forks(t_fork *forks)
{
	int	i;

	i = 0;
	if (forks)
	{
		while (i < get()->number_philosophers)
		{
			pthread_mutex_destroy(&forks[i].lock);
			i++;
		}
		free(forks);
	}
}

// void free_philosophers(t_table *philosophers): 
// This function is responsible for freeing the 
// resources associated with the philosopher table, including 
// mutexes for printing and the death status. 
// It takes an array of t_table structures 
// (philosophers) as input. Here's what it does:
// If the philosophers pointer is not 
// NULL, it proceeds with the following steps.
// It destroys the mutex associated with 
// the print field of the global t_params 
// structure using pthread_mutex_destroy(&get()->print).
// It also destroys the mutex associated 
// with the death.lock field of the global 
// t_death structure using pthread_mutex_destroy(&get()->death.lock).
// Finally, it frees the memory associated 
// with the philosophers array using free(philosophers).

void	free_philosophers(t_table *philosophers)
{
	if (philosophers)
	{
		pthread_mutex_destroy(&get()->print);
		pthread_mutex_destroy(&get()->death.lock);
		free(philosophers);
	}
}

// int free_all(t_table *philosophers, 
// t_fork *forks): This function serves as a 
// high-level function to release all the resources 
// allocated during the initialization of the dining 
// philosophers simulation. It takes both philosophers and 
// forks arrays as input. Here's what it 
// does:
// It calls the free_forks(forks) function to 
// release the resources associated with the forks.
// It calls the free_philosophers(philosophers) function to 
// release the resources associated with the philosopher 
// table, including the mutexes for printing and 
// death status.
// Finally, it returns 0 to indicate 
// that the resources have been freed.

int	free_all(t_table *philosophers, t_fork *forks)
{
	free_forks(forks);
	free_philosophers(philosophers);
	return (0);
}
