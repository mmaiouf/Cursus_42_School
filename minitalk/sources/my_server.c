/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:16:58 by momaiouf          #+#    #+#             */
/*   Updated: 2023/05/24 23:16:58 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

static char	*ft_return_message(char *str);
static char	*ft_add_char(char *str, char c);
static void	ft_signal_handler(int signal, siginfo_t *info, void *context);

static char	*ft_return_message(char *str)
{
	ft_printf(str);
	ft_printf("\n");
	free(str);
	return (str = NULL);
}

static char	*ft_add_char(char *str, char c)
{
	char	*new_str;
	size_t	i;

	if (!c)
		return (NULL);
	if (str == NULL)
	{
		str = malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
	}
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (new_str == NULL)
		return (free(str), NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free(str);
	return (new_str);
}

static void	ft_signal_handler(int signal, siginfo_t *info, void *context)
{
	static char				*my_str = NULL;
	static int				bit = 0;
	static unsigned char	c = 0;

	(void)context;
	if (signal == SIGUSR2)
		c = c | (1 << bit);
	bit++;
	if (bit == BYTE_SIZE)
	{
		bit = 0;
		if (!c)
		{
			my_str = ft_return_message(my_str);
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		my_str = ft_add_char(my_str, c);
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf(ARGS_ERROR);
		return (EXIT_FAILURE);
	}
	pid = getpid();
	sa.sa_sigaction = ft_signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID : %d\n", pid);
	ft_printf("Waiting for signals...\n");
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
