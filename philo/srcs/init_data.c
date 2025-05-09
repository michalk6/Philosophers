/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:36:48 by mikurek           #+#    #+#             */
/*   Updated: 2025/05/09 18:02:28 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_input_valid(t_input_data *input)
{
	return (
		input->number_of_philos > 0
		&& input->time_to_die > 0
		&& input->time_to_eat > 0
		&& input->time_to_sleep > 0
	);
}

static t_input_data	*ft_parse_input(int argc, char **argv)
{
	t_input_data	*input;

	input = malloc(sizeof(t_input_data));
	if (input == NULL)
		return (NULL);
	input->number_of_philos = ft_atol(argv[1]);
	input->time_to_die = ft_atol(argv[2]);
	input->time_to_eat = ft_atol(argv[3]);
	input->time_to_sleep = ft_atol(argv[4]);
	if (!ft_input_valid(input))
		return (free(input), printf("Arguments must be positive\n"), NULL);
	if (argc == 6)
	{
		input->max_num_of_meals = ft_atol(argv[5]);
		if (input->max_num_of_meals <= 0)
			return (free(input), printf("Arguments must be positive\n"), NULL);
	}
	else
		input->max_num_of_meals = -1;
	return (input);
}

static void	ft_add_philo(t_philo **philos, int id, t_table *table)
{
	t_philo	*to_add;
	t_philo	*current;

	to_add = malloc(sizeof(t_philo));
	if (to_add == NULL)
		return ;
	to_add->id = id;
	to_add->meals_left = table->input->max_num_of_meals;
	to_add->table = table;
	to_add->next = NULL;
	to_add->time_of_last_meal = 0;
	pthread_mutex_init(&to_add->fork, NULL);
	if (*philos == NULL)
		*philos = to_add;
	else
	{
		current = *philos;
		while (current->next)
			current = current->next;
		current->next = to_add;
	}
}

static t_philo	*ft_create_philos(t_table *table)
{
	int		id;
	t_philo	*philos;
	t_philo	*first;

	philos = NULL;
	id = 1;
	while (id <= table->input->number_of_philos)
	{
		ft_add_philo(&philos, id, table);
		id++;
	}
	first = philos;
	while (philos->next)
		philos = philos->next;
	philos->next = first;
	return (first);
}

t_table	*ft_init_table(int argc, char **argv)
{
	t_table			*table;

	table = malloc(sizeof(t_table));
	if (table == NULL)
		return (NULL);
	table->start = ft_msgettime();
	table->stop = 0;
	table->input = ft_parse_input(argc, argv);
	if (table->input == NULL)
		return (free(table), NULL);
	table->philos = ft_create_philos(table);
	return (table);
}
