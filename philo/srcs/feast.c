/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feast.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:33:25 by mikurek           #+#    #+#             */
/*   Updated: 2025/05/10 14:19:00 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_delay(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		ft_think(philo);
		usleep(50000);
	}
	if (philo->id % 2 != 0 && philo->next->id == 1)
	{
		ft_think(philo);
		usleep(25000);
	}
}

void	ft_starve_for_ever(t_philo *philo)
{
	long	time;

	time = ft_msgettime() - philo->table->start;
	if (philo->table->stop == 0)
		printf("%ld %d has taken a fork 1\n", time, philo->id);
	while (philo->table->stop == 0)
		;
}

void	*ft_philo_existance(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo == philo->next)
		ft_starve_for_ever(philo);
	ft_delay(philo);
	ft_eat(philo);
	while (philo->meals_left != 0 && philo->table->stop == 0)
	{
		ft_sleep(philo);
		ft_think(philo);
		ft_eat(philo);
	}
	return (NULL);
}

void	*ft_monitor_life(void *arg)
{
	t_philo	*philo;
	long	time;
	long	time_to_die;
	long	time_after_meal;

	philo = NULL;
	philo = (t_philo *)arg;
	time_to_die = philo->table->input->time_to_die;
	while (philo->table->stop == 0 && philo->meals_left != 0)
	{
		time = ft_msgettime() - philo->table->start;
		time_after_meal = time - philo->time_of_last_meal;
		if (time_after_meal > time_to_die)
		{
			philo->table->stop = 1;
			printf("%ld %d died\n", time, philo->id);
		}
		philo = philo->next;
	}
	return (NULL);
}

void	ft_begin_feast(t_philo *philos)
{
	t_philo	*first;

	first = philos;
	pthread_create(&(first->philo_thread), NULL, ft_philo_existance,
		(void *)first);
	philos = philos->next;
	while (philos != first)
	{
		pthread_create(&(philos->philo_thread), NULL, ft_philo_existance,
			(void *)philos);
		philos = philos->next;
	}
	pthread_create(&(first->table->life_monitor), NULL, ft_monitor_life,
		(void *)first);
	pthread_join(first->philo_thread, NULL);
	philos = first->next;
	while (philos != first)
	{
		pthread_join(philos->philo_thread, NULL);
		philos = philos->next;
	}
	pthread_join(first->table->life_monitor, NULL);
}
