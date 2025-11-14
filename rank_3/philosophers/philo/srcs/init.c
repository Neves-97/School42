/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:26:11 by neves             #+#    #+#             */
/*   Updated: 2023/10/19 13:56:28 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// t_fork *init_forks(t_params *data): 
// This function initializes the forks used by 
// the philosophers in the simulation. It takes 
// a pointer to a t_params structure called 
// data, which contains information about the number 
// of philosophers. The function performs the following 
// steps:
// It allocates memory for an array 
// of t_fork structures based on the number 
// of philosophers (data->number_philosophers).
// It initializes the status field of 
// each fork to 1, indicating that the 
// fork is available.
// It uses a loop to initialize 
// a mutex (pthread_mutex) for each fork, ensuring 
// that they are properly protected for concurrent 
// access.
// If any initialization step fails, it 
// returns NULL to indicate an error.
// If successful, it returns a pointer 
// to the array of initialized forks.

t_fork	*init_forks(t_params *data)
{
	int		i;
	t_fork	*forks;

	i = 0;
	forks = malloc(sizeof(t_fork) * data->number_philosophers);
	while (i < data->number_philosophers)
	{
		forks[i].status = 1;
		if (pthread_mutex_init(&forks[i].lock, NULL))
			return (NULL);
		i++;
	}
	return (forks);
}
// void init_table(t_params *data, 
// t_table *philosophers, t_fork *forks): This function initializes 
// the philosopher table. It takes a pointer 
// to the t_params structure (data), an array 
// of t_table structures (philosophers) representing the philosophers, 
// and an array of t_fork structures (forks) 
// representing the forks. The function does the 
// following:
// It uses a loop to initialize 
// each philosopher in the philosophers array.
// For each philosopher, it assigns a 
// reference to the data structure (containing global 
// simulation data) and the forks array to 
// allow them to interact with the shared 
// simulation resources.
// It assigns a unique ID to 
// each philosopher, starting from 1.
// It initializes the number of meals 
// and the time of the last meal 
// for each philosopher.
// The loop increments the philosophers pointer 
// and continues until all philosophers are initialized.

void	init_table(t_params *data, t_table *philosophers, t_fork *forks)
{
	int	i;

	i = 0;
	while (i < data->number_philosophers)
	{
		philosophers->data = data;
		philosophers->forks = forks;
		philosophers->id = i + 1;
		philosophers->number_meals = 0;
		philosophers->last_meal = get_time();
		philosophers++;
		i++;
	}
}
// void init_death(t_death *death): 
// This function initializes the t_death structure used 
// to control the status of the simulation. 
// It takes a pointer to the t_death 
// structure (death). The function does the following:
// It sets the status field of 
// the death structure to 0, indicating that 
// no philosopher has died at the beginning.
// It initializes a mutex (pthread_mutex) associated 
// with death to protect access to the 
// status field.

void	init_death(t_death *death)
{
	death->status = 0;
	pthread_mutex_init(&death->lock, NULL);
}

// void init_params(t_params *data, 
// char **av, int ac): This function initializes 
// the simulation parameters based on command-line arguments. 
// It takes a pointer to the t_params 
// structure (data), an array of command-line arguments 
// (av), and the number of command-line arguments 
// (ac). The function does the following:
// It extracts and stores the number 
// of philosophers, death time, eating time, sleeping 
// time, and eating limit (if provided) from 
// the command-line arguments.
// If there are 5 command-line arguments 
// (including the program name), it sets the 
// eating_num field to the specified limit. Otherwise, 
// it sets eating_num to INT_MAX to indicate 
// no limit on the number of meals.
// It records the current time as 
// the simulation's start time.
// It initializes a mutex associated with 
// the print field of the data structure 
// to manage output synchronization.

void	init_params(t_params *data, char **av, int ac)
{
	data->number_philosophers = ft_atoi(av[1]);
	data->death_time = ft_atoi(av[2]);
	data->eating_time = ft_atoi(av[3]);
	data->sleeping_time = ft_atoi(av[4]);
	if (ac == 6)
		data->eating_num = ft_atoi(av[5]);
	else
		data->eating_num = INT_MAX;
	data->start = get_time();
	pthread_mutex_init(&data->print, NULL);
}

// void init_struct(int ac, 
// char **av, t_params *data): This function orchestrates 
// the initialization process for the simulation. It 
// takes the number of command-line arguments (ac), 
// an array of command-line arguments (av), and 
// a pointer to the t_params structure (data). 
// The function performs the following steps:
// It initializes the t_death structure using 
// the init_death function to manage the death 
// status of the simulation.
// It initializes the simulation parameters using 
// the init_params function based on the command-line 
// arguments.
// It assigns the initialized t_death structure 
// to the death field of the data 
// structure, effectively controlling the simulation's death status.

void	init_struct(int ac, char **av, t_params *data)
{
	t_death	death;

	init_death(&death);
	init_params(data, av, ac);
	data->death = death;
}
