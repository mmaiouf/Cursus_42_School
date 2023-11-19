/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 23:08:13 by momaiouf          #+#    #+#             */
/*   Updated: 2023/11/18 15:12:32 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
	{
		printf(ERROR_NB_ARG);
		exit(EXIT_FAILURE);
	}
	if (init_data(&data, argc, argv) == -1)
		exit(EXIT_FAILURE);
	check_args(&data);
	philo = init_philo(&data);
	if (philo == NULL)
		exit(EXIT_FAILURE);
	if (run_dinner(philo) == -1)
	{
		free_dinner(philo, &data);
		exit(EXIT_FAILURE);
	}
	free_dinner(philo, &data);
	return (0);
}
