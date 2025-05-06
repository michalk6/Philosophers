/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 23:03:37 by mikurek           #+#    #+#             */
/*   Updated: 2025/05/06 23:32:36 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free_philos_list(t_philo *philos)
{
	t_philo	*to_free;

	while (philos)
	{
		to_free = philos;
		philos = philos->next;
		pthread_mutex_destroy(&to_free->fork);
		free(to_free);
	}
}

void	ft_free_table(t_table *table)
{
	if (table->input != NULL)
		free(table->input);
	if (table->philos != NULL)
		ft_free_philos_list(table->philos);
	free(table);
}
