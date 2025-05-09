/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:10:42 by mikurek           #+#    #+#             */
/*   Updated: 2025/05/09 20:58:13 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_print_arg_error_message(void)
{
	printf(
		"Incorrect input data\n"
		"Expected arguments:\n"
		"1: number of philosophers\n"
		"2: time to die\n"
		"3: time to eat\n"
		"4: time to sleep\n"
		"5: number of times each philosopher must eat (optional)\n"
		"example: ./philo 42 600 200 200 [10]\n"
		);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc != 5 && argc != 6)
		return (ft_print_arg_error_message());
	table = ft_init_table(argc, argv);
	if (table == NULL)
		return (1);
	ft_begin_feast(table->philos);
	ft_free_table(table);
	return (EXIT_SUCCESS);
}
