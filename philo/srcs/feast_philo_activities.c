/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feast_philo_activities.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:12:49 by mikurek           #+#    #+#             */
/*   Updated: 2025/05/09 18:13:07 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_grab_forks(t_philo *philo)
{
	long	time;

	if (philo->table->stop != 0)
		return ;
	pthread_mutex_lock(&(philo->fork));
	time = ft_msgettime() - philo->table->start;
	if (philo->table->stop == 0)
		printf("%ld %d has taken a fork 1\n", time, philo->id);
	pthread_mutex_lock(&(philo->next->fork));
	time = ft_msgettime() - philo->table->start;
	if (philo->table->stop == 0)
		printf("%ld %d has taken a fork 2\n", time, philo->id);
}

void	ft_eat(t_philo *philo)
{
	long	time;

	ft_grab_forks(philo);
	if (philo->table->stop == 0)
	{
		time = ft_msgettime() - philo->table->start;
		if (philo->meals_left > 0)
		{
			philo->meals_left--;
			printf("%ld %d is eating (meals left %ld)\n",
				time, philo->id, philo->meals_left);
		}
		else
			printf("%ld %d is eating\n", time, philo->id);
		philo->time_of_last_meal = ft_msgettime();
		usleep(philo->table->input->time_to_eat * 1000);
	}
	pthread_mutex_unlock(&(philo->fork));
	pthread_mutex_unlock(&(philo->next->fork));
}

void	ft_sleep(t_philo *philo)
{
	long	time;

	if (philo->table->stop != 0)
		return ;
	time = ft_msgettime() - philo->table->start;
	printf("%ld %d is sleeping\n", time, philo->id);
	usleep(philo->table->input->time_to_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	long	time;

	if (philo->table->stop != 0)
		return ;
	time = ft_msgettime() - philo->table->start;
	printf("%ld %d is thinking\n", time, philo->id);
}
