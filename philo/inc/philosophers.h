/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:07:39 by mikurek           #+#    #+#             */
/*   Updated: 2025/05/09 18:17:53 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_input_data
{
	long	number_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	max_num_of_meals;
}	t_input_data;

typedef struct s_philo
{
	int				id;
	long			time_of_last_meal;
	long			meals_left;
	pthread_t		philo_thread;
	pthread_mutex_t	fork;
	struct s_table	*table;
	struct s_philo	*next;
}	t_philo;

typedef struct s_table
{
	long			start;
	int				stop;
	t_input_data	*input;
	t_philo			*philos;
	pthread_t		life_monitor;
}	t_table;

t_table	*ft_init_table(int argc, char **argv);
void	ft_free_table(t_table *table);
void	ft_begin_feast(t_philo *philos);

void	ft_grab_forks(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

// UTILS
long	ft_atol(const char *nptr);
long	ft_msgettime(void);

#endif