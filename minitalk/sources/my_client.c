/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:17:09 by momaiouf          #+#    #+#             */
/*   Updated: 2023/05/24 23:17:09 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

static void		ft_message_confirmation(int signal);
static void		ft_send_message(pid_t server_pid, char *str);

static void	ft_message_confirmation(int signal)
{
	static int	nb_bits = 0;

	if (signal == SIGUSR1)
		nb_bits++;
	else
	{
		ft_printf(MSG_CONFIRM);
		exit(0);
	}
}

static void	ft_send_message(pid_t server_pid, char *str)
{
	int		i;
	int		bit;

	i = 0;
	while (str[i])
	{
		bit = 0;
		while (bit < BYTE_SIZE)
		{
			if ((str[i] & (1 << bit)))
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			usleep(SLEEP_TIME);
			bit++;
		}
		i++;
	}
	bit = 0;
	while (bit < BYTE_SIZE)
	{
		kill(server_pid, SIGUSR1);
		usleep(SLEEP_TIME);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf(ARGS_ERROR);
		return (EXIT_FAILURE);
	}
	if (!ft_strlen(argv[2]))
	{
		ft_printf(EMPTY_STR_ERROR);
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		ft_printf(PID_ERROR);
		return (EXIT_FAILURE);
	}
	signal(SIGUSR1, ft_message_confirmation);
	signal(SIGUSR2, ft_message_confirmation);
	ft_send_message(pid, argv[2]);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
