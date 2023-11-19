/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 23:21:17 by momaiouf          #+#    #+#             */
/*   Updated: 2023/11/18 14:44:10 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	*one_philo_exec(void *ptr)
{
	t_data	*data;

	data = (t_data *) ptr;
	pthread_mutex_lock(&data->fork_lock[0]);
	printf("1 1 has taken the left fork\n");
	usleep(data->time_die * 1000);
	pthread_mutex_unlock(&data->fork_lock[0]);
	printf("%d %d %s\n", data->time_die, 1, "died");
	return (0);
}

int	one_philo_handler(t_data *data)
{
	pthread_t		monitor;

	data->fork_lock = malloc(sizeof(pthread_mutex_t) * 1);
	if (data->fork_lock == NULL)
		return (printf("%s", ERROR_MALLOC_A_FORK), -1);
	if (pthread_mutex_init(&data->fork_lock[0], NULL) != 0)
		return (printf("%s", ERROR_MUTEX_FORK), free(data->fork_lock), -1);
	if (pthread_create(&monitor, NULL, &one_philo_exec, data) != 0)
		return (printf("%s", ERROR_CREATE_THREAD),
			pthread_mutex_destroy(&data->fork_lock[0]), free(data->fork_lock),
			-1);
	if (pthread_join(monitor, NULL) != 0)
		return (printf("%s", ERROR_JOIN_THREAD),
			pthread_mutex_destroy(&data->fork_lock[0]), free(data->fork_lock),
			-1);
	pthread_mutex_destroy(&data->fork_lock[0]);
	free(data->fork_lock);
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->must_eat = 0;
	if (data->nb_philo == 1)
	{
		one_philo_handler(data);
		return (-1);
	}
	if (ac == 6)
	{
		data->must_eat = ft_atoi(av[5]);
		if (data->must_eat < 1)
			return (printf(ERROR_ARG), -1);
	}
	data->is_dead = 0;
	data->sum_meal = 0;
	data->fork_lock = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (data->fork_lock == NULL)
		return (printf("%s", ERROR_MALLOC_ARRAY_FORK), -1);
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
		return (printf("%s", ERROR_MUTEX_PRINT), free(data->fork_lock), -1);
	return (0);
}

t_philo	*init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (philo == NULL)
		return (printf("%s", ERROR_MALLOC_ARRAY_PHILO),
			pthread_mutex_destroy(&data->print_lock), free(data->fork_lock),
			NULL);
	while (++i < data->nb_philo)
	{
		philo[i].philo_id = i + 1;
		philo[i].left_fork = i;
		philo[i].right_fork = i + 1;
		philo[i].ate = 0;
		philo[i].last_meal = get_time();
		philo[i].data_philo = data;
		if (pthread_mutex_init(&data->fork_lock[i], NULL) != 0)
			return (printf("%s", ERROR_MUTEX_FORK), free_all(data, philo, i));
	}
	i--;
	philo[i].right_fork = 0;
	return (philo);
}

void	*free_all(t_data *data, t_philo *philo, int i)
{
	while (i >= 0)
		pthread_mutex_destroy(&data->fork_lock[i--]);
	return (free(philo), pthread_mutex_destroy(&data->print_lock),
		free(data->fork_lock), NULL);
}
