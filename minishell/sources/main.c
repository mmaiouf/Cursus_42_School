/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:32:47 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 16:49:32 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	g_error;

char	*take_input(t_envp *s_envp)
{
	char	*str;
	char	*buffer;

	str = "";
	buffer = readline(">>>minishell ");
	if (buffer == NULL)
	{
		g_error = 131;
		ft_putstr_fd("exit\n", 1);
		ft_free_env(s_envp);
		ft_close_fd();
		exit(g_error);
	}
	str = ft_strdup(buffer);
	add_history(buffer);
	if (buffer[0] != '\0')
		free(buffer);
	return (str);
}

int	main(int argc, char **argv, char **envp)
{
	t_envp	*s_envp;

	(void)argc;
	(void)argv;
	s_envp = init(envp);
	while (1)
	{
		ft_signals(1);
		s_envp->input = take_input(s_envp);
		if (ft_is_only_spaces(s_envp->input))
			g_error = 0;
		else if (ft_strlen(s_envp->input) != 0)
			parsing_command(s_envp);
		if (s_envp->input[0] != '\0')
			free(s_envp->input);
	}
	return (0);
}
