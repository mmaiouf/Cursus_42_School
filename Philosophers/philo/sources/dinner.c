/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 23:26:27 by momaiouf          #+#    #+#             */
/*   Updated: 2023/11/18 17:54:04 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	eating(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data_philo->fork_lock[philo->right_fork]);
		print_state(philo, "has taken the right fork");
		pthread_mutex_lock(&philo->data_philo->fork_lock[philo->left_fork]);
		print_state(philo, "has taken the left fork");
	}
	else
	{
		usleep(1000);
		pthread_mutex_lock(&philo->data_philo->fork_lock[philo->left_fork]);
		print_state(philo, "has taken the left fork");
		pthread_mutex_lock(&philo->data_philo->fork_lock[philo->right_fork]);
		print_state(philo, "has taken the right fork");
	}
	print_state(philo, "is eating");
	ft_usleep(philo->data_philo->time_eat);
	pthread_mutex_lock(&philo->data_philo->print_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data_philo->print_lock);
	pthread_mutex_unlock(&philo->data_philo->fork_lock[philo->left_fork]);
	pthread_mutex_unlock(&philo->data_philo->fork_lock[philo->right_fork]);
}

void	*loop(void *ptr)
{
	t_philo	*philo;
	int		died;

	philo = (t_philo *)ptr;
	if (philo->philo_id % 2 == 0)
		ft_usleep(philo->data_philo->time_eat);
	else
		usleep(200);
	pthread_mutex_lock(&philo->data_philo->print_lock);
	died = philo->data_philo->is_dead;
	pthread_mutex_unlock(&philo->data_philo->print_lock);
	while (died != 1)
	{
		eating(philo);
		print_state(philo, "is sleeping");
		ft_usleep(philo->data_philo->time_sleep);
		print_state(philo, "is thinking");
		philo->ate++;
		pthread_mutex_lock(&philo->data_philo->print_lock);
		died = philo->data_philo->is_dead;
		pthread_mutex_unlock(&philo->data_philo->print_lock);
	}
	return (NULL);
}

void	*monitoring(void *ptr)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (!check_meals(philo))
	{
		i = 0;
		while (i < philo->data_philo->nb_philo)
		{
			pthread_mutex_lock(&philo->data_philo->print_lock);
			if (get_time() - philo[i].last_meal >= philo->data_philo->time_die)
			{
				pthread_mutex_unlock(&philo->data_philo->print_lock);
				print_state(&philo[i], "died");
				pthread_mutex_lock(&philo->data_philo->print_lock);
				philo->data_philo->is_dead = 1;
				pthread_mutex_unlock(&philo->data_philo->print_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&philo->data_philo->print_lock);
			i++;
		}
		ft_usleep(100);
	}
	return (NULL);
}

int	run_dinner(t_philo *philo)
{
	int			i;
	pthread_t	monitor;

	i = -1;
	philo->data_philo->start_time = get_time();
	while (++i < philo->data_philo->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &loop, &philo[i]) != 0)
			return (printf(ERROR_CREATE_THREAD), -1);
	}
	if (pthread_create(&monitor, NULL, &monitoring, philo) != 0)
		return (printf(ERROR_CREATE_THREAD), -1);
	i = -1;
	while (++i < philo->data_philo->nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (printf(ERROR_JOIN_THREAD), -1);
	}
	if (pthread_join(monitor, NULL) != 0)
		return (printf(ERROR_JOIN_THREAD), -1);
	return (0);
}

void	free_dinner(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->fork_lock[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_lock);
	free(data->fork_lock);
	free(philo);
}
