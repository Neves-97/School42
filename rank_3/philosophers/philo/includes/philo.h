/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:31:17 by neves             #+#    #+#             */
/*   Updated: 2023/10/19 14:18:08 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <stdint.h>
# include <unistd.h>
# include <stddef.h>

// t_death Structure:
// This structure represents the death status 
// and the associated mutex lock for a 
// philosopher.
// status: An integer that represents the 
// death status (0 or 1).
// lock: A pthread_mutex_t to provide thread-safe 
// access to the death status.

// t_fork Structure:
// This structure represents a fork, which 
// is used by philosophers to eat.
// status: An integer representing the status 
// of the fork (1 if available, 0 
// if in use).
// lock: A pthread_mutex_t to ensure exclusive 
// access to the fork.

// t_params Structure:
// This structure contains various parameters for 
// the dining philosophers simulation.
// number_philosophers: An integer representing the number 
// of philosophers in the simulation.
// death_time: An integer representing the time 
// it takes for a philosopher to die 
// if they don't eat.
// eating_time: An integer representing the time 
// it takes for a philosopher to eat.
// sleeping_time: An integer representing the time 
// it takes for a philosopher to sleep.
// eating_num: An integer representing the maximum 
// number of meals a philosopher can eat.
// start: A timestamp (uint64_t) representing the 
// start time of the simulation.
// print: A pthread_mutex_t used for thread-safe 
// printing.
// death: An instance of the t_death 
// structure to track the death status.

// t_table Structure:
// This structure represents an individual philosopher 
// and their state at the dining table.
// data: A pointer to a t_params 
// structure, containing shared simulation parameters.
// forks: A pointer to an array 
// of t_fork structures, representing the forks used 
// by philosophers.
// philo: A pthread_t representing the philosopher's 
// thread.
// id: An integer representing the philosopher's 
// unique identifier.
// number_meals: An integer representing the number 
// of meals this philosopher has eaten.
// last_meal: A timestamp (uint64_t) representing the 
// time of the philosopher's last meal.

typedef struct s_death
{
	int				status;
	pthread_mutex_t	lock;
}				t_death;

typedef struct s_fork
{
	int				status;
	pthread_mutex_t	lock;
}				t_fork;

typedef struct s_params
{
	int				number_philosophers;
	int				death_time;
	int				eating_time;
	int				sleeping_time;
	int				eating_num;
	uint64_t		start;
	pthread_mutex_t	print;
	t_death			death;
}		t_params;

typedef struct s_table
{
	t_params		*data;
	t_fork			*forks;
	pthread_t		philo;
	int				id;
	int				number_meals;
	uint64_t		last_meal;
}				t_table;

// ACTIONS.C
int			eating(t_table *philo);
void		sleeping(t_table *philo);
// CHECK.C
int			check_argument_validity(int argc, char **argv);
int			check(int argc, char **argv);
// DEATH.C
int			is_dead(t_table *philo);
int			death_checker(t_table *philo);
// FORKS.C
void		lock_fork(t_fork *fork, t_table	*philo);
void		unlock_fork(t_fork *fork, t_table	*philo);
int			pick_forks(t_table *philo, int *fork1, int *fork2);
void		release_forks(t_table *philo, int fork1, int fork2);
// FREE.C
void		free_forks(t_fork *forks);
void		free_philosophers(t_table *philosophers);
int			free_all(t_table *philosophers, t_fork *forks);
// INIT.C
t_fork		*init_forks(t_params *data);
void		init_table(t_params *data, t_table *philosophers, t_fork *forks);
void		init_death(t_death *death);
void		init_params(t_params *data, char **av, int ac);
void		init_struct(int ac, char **av, t_params *data);
// MAIN.C
t_params	*get(void);
// ROUTINE.C
void		init_routine(t_table *phi);
void		*routine(void *philo);
// THREADS.C
int			create_threads_helper(t_table *philosophers);
int			join_threads(t_table *philosophers);
int			create_threads(t_table *philosophers);
// TIME.C
uint64_t	get_time(void);
void		t_sleep(uint64_t time, t_table *philo);
uint64_t	calc_time(void);
// UTILS.C
int			ft_strlen(char *str);
void		ft_putstr_fd(char *str, int fd);
int			error_message(char *msg);
int			ft_atoi(const char *str);
void		print_status(t_table *philo, char *status);

#endif