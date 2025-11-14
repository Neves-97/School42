/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:39:25 by neves             #+#    #+#             */
/*   Updated: 2023/10/19 14:18:01 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// t_params *get(void): This 
// function returns a pointer to a t_params 
// structure. It's designed to provide access to 
// a static instance of the t_params structure 
// called data, which is used to store 
// configuration parameters for the dining philosophers simulation. 
// The function is defined as follows:
// It declares a static instance of 
// t_params named data. The static keyword ensures 
// that this instance persists across function calls.
// It returns a pointer to the 
// static data structure, effectively providing access to 
// its contents. The data structure stores information 
// such as the number of philosophers, their 
// death time, eating and sleeping times, the 
// number of meals, and other simulation parameters.

t_params	*get(void)
{
	static t_params	data;

	return (&data);
}

// int main(int ac, 
// char **av): This is the main function 
// that orchestrates the dining philosophers simulation:
// It takes the command-line arguments ac 
// (argument count) and av (argument vector).
// First, it checks the validity of 
// the command-line arguments by calling the check 
// function. If the arguments are invalid (e.g., 
// the wrong number of arguments or non-numeric 
// values), the program returns 0 to indicate 
// an error.
// If the arguments are valid, it 
// proceeds to initialize the simulation:
// It calls 
// the init_struct function, which sets up the 
// t_params structure and its parameters based on 
// It then 
// calls init_forks to create and initialize an 
// array of fork structures (used to represent 
// the forks on the table).
// It allocates 
// memory for an array of t_table structures, 
// which represent the philosophers, using malloc. The 
// number of philosophers is obtained from the 
// get() function.
// If any initialization step fails (e.g., 
// memory allocation for forks or philosophers), the 
// program returns 0 to indicate an error.
// If all the initialization steps are 
// successful, it continues to set up the 
// philosopher table by calling init_table.
// Finally, it calls the create_threads function 
// to start the dining philosophers simulation with 
// the philosopher threads.

int	main(int ac, char **av)
{
	t_table	*philosophers;
	t_fork	*forks;

	if (check(ac, av) == 0)
		return (0);
	init_struct(ac, av, get());
	forks = init_forks(get());
	if (!forks)
		return (free_all(NULL, forks));
	philosophers = malloc(sizeof(t_table) * get()->number_philosophers);
	if (!philosophers)
		return (free_all(philosophers, forks));
	init_table(get(), philosophers, forks);
	create_threads(philosophers);
}
