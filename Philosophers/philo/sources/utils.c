/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 23:24:56 by momaiouf          #+#    #+#             */
/*   Updated: 2023/11/18 18:11:13 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	ft_atoi(const char *str)
{
	int	result;

	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		printf("%s", ERROR_ARG);
		exit(EXIT_FAILURE);
	}
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (result + *str - '0' != (result + *str - '0') * 10 / 10)
			return (-1);
		result = result * 10 + *str - '0';
		str++;
	}
	if (!(*str >= '0' && *str <= '9') && *str != '\0')
	{
		printf(ERROR_NON_DIGIT_CHARACTER);
		exit(EXIT_FAILURE);
	}
	return (result * 1);
}

void	check_args(t_data *data)
{
	if (data->nb_philo < 1)
	{
		printf(ERROR_ARG);
		free(data->fork_lock);
		pthread_mutex_destroy(&data->print_lock);
		exit(EXIT_FAILURE);
	}
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_state(t_philo *philo, char *state)
{
	long	current_time;

	pthread_mutex_lock(&philo->data_philo->print_lock);
	current_time = get_time() - philo->data_philo->start_time;
	if (!philo->data_philo->is_dead)
		printf("%ld %d %s\n", current_time, philo->philo_id, state);
	pthread_mutex_unlock(&philo->data_philo->print_lock);
}

int	check_meals(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->data_philo->must_eat > 0)
	{
		while (i < philo->data_philo->nb_philo)
		{
			pthread_mutex_lock(&philo->data_philo->print_lock);
			if (philo[i].ate >= philo->data_philo->must_eat)
				philo->data_philo->sum_meal++;
			pthread_mutex_unlock(&philo->data_philo->print_lock);
			i++;
		}
		if (philo->data_philo->sum_meal >= philo->data_philo->nb_philo)
		{
			pthread_mutex_lock(&philo->data_philo->print_lock);
			philo->data_philo->is_dead = 1;
			pthread_mutex_unlock(&philo->data_philo->print_lock);
			return (1);
		}
	}
	return (0);
}
