/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:47:02 by neves             #+#    #+#             */
/*   Updated: 2023/10/19 13:28:55 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// lock_fork(t_fork *fork, t_table *philo): This function is responsible for a 
// philosopher picking up a fork. It does the following:
// It enters a while loop that continues until the philosopher is 
//considered dead, 
// as determined by the death_checker(philo) function.
// Inside the loop, it attempts to lock the mutex associated with the fork 
//using 
// pthread_mutex_lock(&fork->lock). If the lock is successful, it means 
//the fork 
// is available.
// If the fork's status is 1 (indicating that it's available), it sets 
//the status 
// to 0 to indicate that the fork is now in use. This action is 
//atomic, meaning 
// it's not interrupted by other threads.
// It unlocks the mutex associated with the fork using 
//pthread_mutex_unlock(&fork->lock).
// It calls print_status(philo, "has taken a fork") to indicate 
//that the philosopher 
// has successfully taken a fork.
// It breaks out of the loop, as the philosopher now has the desired fork.

void	lock_fork(t_fork *fork, t_table *philo)
{
	while (!death_checker(philo))
	{
		pthread_mutex_lock(&fork->lock);
		if (fork->status == 1)
		{
			fork->status = 0;
			pthread_mutex_unlock(&fork->lock);
			print_status(philo, "has taken a fork");
			break ;
		}
		pthread_mutex_unlock(&fork->lock);
	}
}
// unlock_fork(t_fork *fork, t_table *philo): This function is used to 
// release a fork once a philosopher is done using it. It follows a 
// similar structure to lock_fork:
// It enters a while loop that continues until the philosopher is 
// considered dead.
// It locks the mutex associated with the fork using 
// pthread_mutex_lock(&fork->lock).
// If the fork's status is 0 (indicating it's in use), it sets 
// the status to 1 to mark it as available.
// It unlocks the mutex associated with the fork.
// The loop exits, and the philosopher has released the fork.

void	unlock_fork(t_fork *fork, t_table *philo)
{
	while (!death_checker(philo))
	{
		pthread_mutex_lock(&fork->lock);
		if (fork->status == 0)
		{
			fork->status = 1;
			pthread_mutex_unlock(&fork->lock);
			break ;
		}
		pthread_mutex_unlock(&fork->lock);
	}
}
// pick_forks(t_table *philo, int *fork1, int *fork2): This 
// function is used to help a philosopher pick up two adjacent 
// forks. It calculates which forks they should pick up 
// based on their id and uses the lock_fork function to lock 
// both of those forks. Here's how it works:
// It calculates the indices of the two forks that the 
// philosopher should pick up based on their id and the number 
// of philosophers. These indices are stored in fork1 and fork2.
// It then calls lock_fork twice to lock both of these forks. 
// If the philosopher is considered dead at any point in this 
// process, it returns 0 to indicate an error.
// If the philosopher hasn't died and has successfully locked 
// both forks, it returns 1 to indicate success.

int	pick_forks(t_table *philo, int *fork1, int *fork2)
{
	*fork1 = ((philo->id == 1) * (philo->data->number_philosophers - 1) + \
		((philo->id != 1) * (philo->id - 1)));
	*fork2 = (philo->id - 1 - (philo->id != 1));
	lock_fork(&philo->forks[*fork1], philo);
	lock_fork(&philo->forks[*fork2], philo);
	if (is_dead(philo))
		return (0);
	return (1);
}

void	release_forks(t_table *philo, int fork1, int fork2)
{
	unlock_fork(&philo->forks[fork1], philo);
	unlock_fork(&philo->forks[fork2], philo);
}
