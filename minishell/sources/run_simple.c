/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:55:55 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/26 00:40:02 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	ft_free_child(char *path, char **parse, t_envp *s_envp)
{
	if (path)
		free(path);
	if (parse)
		ft_free_str(parse);
	if (s_envp->command_quotes)
		free(s_envp->command_quotes);
	if (s_envp->str_quotes_removed)
		free(s_envp->str_quotes_removed);
	if (s_envp->input)
		free(s_envp->input);
	ft_free_env(s_envp);
}

static void	env_var_handle(char **array)
{
	int		i;
	char	*env_value;

	i = 0;
	while (array[i])
	{
		if (array[i] && array[i][0] == '$' && array[i][1] == '?')
		{
			free(array[i]);
			array[i] = ft_itoa(g_error);
		}
		else if (array[i] && array[i][0] == '$')
		{
			env_value = getenv(ft_strtrim(array[i], "$"));
			free(array[i]);
			array[i] = ft_strdup(env_value);
		}
		i++;
	}
}

int	run_child(char **parse, t_envp *s_envp)
{
	char	*path;

	env_var_handle(parse);
	path = find_path(parse[0], s_envp);
	if (s_envp->error_flag_quote == 1 || path == NULL)
	{
		g_error = 127;
		ft_putstr_fd("command not found\n", 2);
		ft_free_child(path, parse, s_envp);
		return (-1);
	}
	else
		execve(path, parse, s_envp->env_array);
	return (0);
}

void	run_simple(char *str, t_envp *s_envp)
{
	pid_t	pid;
	char	**commands;

	commands = ft_split(str, ' ');
	ft_signals(2);
	pid = fork();
	if (pid < 0)
	{
		g_error = 127;
		ft_putstr_fd("Error : failed to create a child process.\n", 2);
	}
	else if (pid == 0)
	{
		if (run_child(commands, s_envp) == -1)
		{
			free(str);
			ft_close_fd();
			exit(g_error);
		}
	}
	waitpid(pid, &g_error, 0);
	g_error = WEXITSTATUS(g_error);
	ft_free_str(commands);
}
