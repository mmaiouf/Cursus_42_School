/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:15:37 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 16:47:31 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	is_builtin(char *command, t_envp *s_envp)
{
	if (command == NULL)
		return (0);
	if (is_echo(command, s_envp))
		return (1);
	else if (!ft_strncmp(command, "cd", 2))
		return (2);
	else if (!ft_strncmp(command, "pwd", 3))
		return (3);
	else if (!ft_strncmp(command, "export", 6))
		return (4);
	else if (!ft_strncmp(command, "unset", 5))
		return (5);
	else if (!ft_strncmp(command, "env", 3))
		return (6);
	else if (!ft_strncmp(command, "exit", 4))
		return (7);
	return (0);
}

void	run_builtin(char *str, t_envp *s_envp)
{
	int		id;

	id = is_builtin(str, s_envp);
	if (id == 1)
		run_echo(str, s_envp);
	else if (id == 2)
		run_cd(str);
	else if (id == 3)
		run_pwd(str);
	else if (id == 4)
		run_export(str, s_envp);
	else if (id == 5)
		run_unset(str, s_envp);
	else if (id == 6)
		run_env(str, s_envp);
	else if (id == 7)
	{
		if (run_exit(str, s_envp) == 0)
		{
			ft_putstr_fd("exit\n", 1);
			ft_close_fd();
			exit(g_error);
		}
	}
}
