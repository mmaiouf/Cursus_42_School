/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:38:32 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 19:35:24 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	free_exec_redir(t_envp *s_envp)
{
	if (s_envp->file_redir_in != NULL)
		free(s_envp->file_redir_in);
	if (s_envp->file_redir_out != NULL)
		free(s_envp->file_redir_out);
	if (s_envp->stdout_copy != 42)
		close(s_envp->stdout_copy);
	if (s_envp->eof_heredoc != NULL)
		free(s_envp->eof_heredoc);
	if (s_envp->array_redir != NULL)
		ft_free_str(s_envp->array_redir);
	if (s_envp->str_quotes_removed != NULL)
		free(s_envp->str_quotes_removed);
	if (s_envp->epur != NULL)
		free(s_envp->epur);
	if (s_envp->input != NULL)
		free(s_envp->input);
	if (s_envp->env_array != NULL)
		ft_free_env(s_envp);
}

void	exec_redir(char *str, int fd, int new_fd, t_envp *s_envp)
{
	int		n_pipe;

	ft_signals(2);
	n_pipe = count(s_envp->input, '|');
	dup2(fd, new_fd);
	close(fd);
	if (n_pipe)
		run_pipe(s_envp->input, n_pipe, s_envp);
	else if (is_builtin(str, s_envp))
		run_builtin(str, s_envp);
	else
		run_simple(str, s_envp);
	free(str);
	free_exec_redir(s_envp);
	ft_close_fd();
	exit(g_error);
}

void	exec_dir(char *str, int fd, int new_fd, t_envp *s_envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		g_error = 127;
		ft_putstr_fd("Failed forking child", 2);
	}
	else if (pid == 0)
		exec_redir(str, fd, new_fd, s_envp);
	waitpid(0, &g_error, 0);
	g_error = WEXITSTATUS(g_error);
}
