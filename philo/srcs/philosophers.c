/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:10:42 by mikurek           #+#    #+#             */
/*   Updated: 2025/05/08 19:36:36 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_input(t_input_data *input)
{
	printf("---input---\n");
	if (input == NULL)
	{
		printf("no input\n");
		return ;
	}
	printf("number of philos: %ld\n", input->number_of_philos);
	printf("time to die:      %ld\n", input->time_to_die);
	printf("time to eat:      %ld\n", input->time_to_eat);
	printf("time to sleep:    %ld\n", input->time_to_sleep);
	printf("max num meals:    %ld\n", input->max_num_of_meals);
}

void	ft_print_philos(t_philo *philos)
{
	printf("---philos---\n");
	if (philos == NULL)
	{
		printf("no philos\n");
		return ;
	}
	while (philos)
	{
		printf("id: %d", philos->id);
		printf(" - meals: %ld\n", philos->meals_left);
		if (philos->id < philos->next->id)
			philos = philos->next;
		else
			philos = NULL;
	}
}

void	ft_print_table(t_table *table)
{
	printf("---table---\n");
	if (table == NULL)
	{
		printf("no table\n");
		return ;
	}
	printf("start - %ld\n", table->start);
	ft_print_input(table->input);
	ft_print_philos(table->philos);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc != 5 && argc != 6)
		return (0);
	table = ft_init_table(argc, argv);
	if (table == NULL)
		return (1);
	ft_begin_feast(table);
	printf("test\n");
	ft_print_table(table);

	ft_free_table(table);
	return (0);
}
