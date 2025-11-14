/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:03:09 by neves             #+#    #+#             */
/*   Updated: 2023/10/19 13:42:49 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// int eating(t_table *philo): 
// This function represents the behavior of a 
// philosopher while eating. It does the following:
// It takes a t_table pointer philo 
// as a parameter, which represents a philosopher's 
// information.
// It attempts to acquire two forks 
// by calling the pick_forks function, which is 
// responsible for locking two forks for the 
// philosopher.
// If the philosopher successfully picks up 
// the forks (i.e., if pick_forks returns 1), 
// it proceeds to eat:
// It prints 
// the status of the philosopher as "is 
// eating" by calling the print_status function.
// It makes 
// the philosopher sleep for a duration specified 
// by philo->data->eating_time using the t_sleep function. 
// This simulates the time spent eating.
// It updates the philosopher's last_meal time to the current 
// time obtained from the get_time function.
// It releases 
// the forks acquired by the philosopher by 
// calling the release_forks function.
// It increments 
// the number_meals counter for the philosopher.
// If the philosopher fails to pick 
// up the forks (i.e., if pick_forks returns 
// 0), it means the philosopher couldn't eat. 
// In this case, the function returns 0 
// to indicate the failure.

int	eating(t_table *philo)
{
	int	fork1;
	int	fork2;

	if (pick_forks(philo, &fork1, &fork2))
	{
		print_status(philo, "is eating");
		t_sleep(philo->data->eating_time, philo);
		philo->last_meal = get_time();
		release_forks(philo, fork1, fork2);
		philo->number_meals++;
		return (1);
	}
	return (0);
}

// void sleeping(t_table *philo): 
// This function represents the behavior of a 
// philosopher while sleeping. Here's how it works:
// It takes a t_table pointer philo 
// as a parameter, which represents a philosopher's 
// information.
// It prints the status of the 
// philosopher as "is sleeping" by calling the 
// print_status function.
// It makes the philosopher sleep for 
// a duration specified by philo->data->sleeping_time using the 
// t_sleep function. This simulates the time spent 
// sleeping.

void	sleeping(t_table *philo)
{
	print_status(philo, "is sleeping");
	t_sleep(philo->data->sleeping_time, philo);
}
