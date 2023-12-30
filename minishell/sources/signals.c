/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 01:19:32 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 19:38:46 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	handler_heredoc(int signum)
{
	if (signum == SIGINT)
	{
		g_error = 130;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_done = 1;
	}
}

static void	handler_child(int signum)
{
	if (signum == SIGINT)
	{
		g_error = 130;
		write(1, "\n", 1);
	}
	if (signum == SIGQUIT)
	{
		g_error = 131;
		ft_putendl_fd("Quit (core dumped)", 2);
	}
}

static void	handler_main(int signum)
{
	(void)signum;
	g_error = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_signals(int signum)
{
	if (signum == 1)
	{
		signal(SIGINT, handler_main);
		signal(SIGQUIT, SIG_IGN);
	}
	if (signum == 2)
	{
		signal(SIGINT, handler_child);
		signal(SIGQUIT, handler_child);
	}
	if (signum == 3)
	{
		signal(SIGINT, handler_heredoc);
		signal(SIGQUIT, SIG_IGN);
	}
}
