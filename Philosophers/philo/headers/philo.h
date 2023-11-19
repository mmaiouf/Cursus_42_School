/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:25:43 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/11/18 15:11:44 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define ERROR_MALLOC_ARRAY_FORK "malloc() of fork_lock array failed.\n"
# define ERROR_NON_DIGIT_CHARACTER "Your arguments have non-digits character.\n"
# define ERROR_MALLOC_ARRAY_PHILO "malloc() of philo array failed.\n"
# define ERROR_MUTEX_PRINT "pthread_mutex_init() of print_lock failed.\n"
# define ERROR_MUTEX_FORK "pthread_mutex_init() of a fork failed.\n"
# define ERROR_NB_ARG "Wrong number of arguments.\n"
# define ERROR_ARG "Wrong arguments.\n"
# define ERROR_INT_ARG "Your arguments have non-digits character.\n"
# define ERROR_CREATE_THREAD "Failed to create a thread.\n"
# define ERROR_JOIN_THREAD "Failed to join a thread.\n"
# define ERROR_MALLOC_A_FORK "malloc of a fork failed.\n"

typedef struct s_data
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	int				sum_meal;
	long			start_time;
	int				is_dead;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	*fork_lock;
}	t_data;

typedef struct s_philo
{
	pthread_t	thread;
	long		last_meal;
	int			philo_id;
	int			ate;
	int			left_fork;
	int			right_fork;
	t_data		*data_philo;
}	t_philo;

int		init_data(t_data *data, int ac, char **av);
t_philo	*init_philo(t_data *data);

int		ft_atoi(const char *str);
void	check_args(t_data *data);
long	get_time(void);
void	print_state(t_philo *philo, char *state);
int		check_meals(t_philo *philo);
void	eating(t_philo *philo);
void	*loop(void *ptr);
void	*monitoring(void *ptr);
int		run_dinner(t_philo *philo);
void	free_dinner(t_philo *philo, t_data *data);
void	*free_all(t_data *data, t_philo *philo, int i);
void	ft_usleep(long time_loop);

#endif