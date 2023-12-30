/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:36:18 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/26 00:41:03 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	ft_free_pipe(char *path, int *fd_ar, char **array, t_envp *s_envp)
{
	if (path)
		free(path);
	if (array)
		ft_free_str(array);
	if (fd_ar)
		free(fd_ar);
	if (s_envp->pipe_list)
		ft_free_list(s_envp->pipe_list);
	if (s_envp->pipe_array)
		ft_free_str(s_envp->pipe_array);
	if (s_envp->command_quotes)
		free(s_envp->command_quotes);
	if (s_envp->str_quotes_removed)
		free(s_envp->str_quotes_removed);
	if (s_envp->epur)
		free(s_envp->epur);
	if (s_envp->input)
		free(s_envp->input);
	ft_free_env(s_envp);
}

void	exec_pipe(int *fd_array, int j, t_list *temp, t_envp *s_envp)
{
	int		i;
	char	**array_cmd;
	char	*path;

	s_envp->count_pipe_exec = count(s_envp->input, '|');
	if (j != 0)
		if (dup2(fd_array[(j - 1) * 2], 0) < 0)
			exit(1);
	if (temp->next)
		if (dup2(fd_array[j * 2 + 1], 1) < 0)
			exit(1);
	i = -1;
	while (++i < 2 * s_envp->count_pipe_exec)
		close(fd_array[i]);
	array_cmd = ft_split(temp->content, ' ');
	path = find_path(array_cmd[0], s_envp);
	if (s_envp->error_flag_quote == 1 || path == NULL)
	{
		g_error = 127;
		ft_putstr_fd("command not found\n", 2);
		ft_free_pipe(path, fd_array, array_cmd, s_envp);
		exit(g_error);
	}
	else
		execve(path, array_cmd, s_envp->env_array);
}

static void	split_pipe(int *pipe_fd, t_list *pipe_commands, t_envp *s_envp)
{
	int		j;
	int		pid;
	t_list	*temp;

	j = 0;
	temp = pipe_commands;
	while (temp)
	{
		ft_signals(1);
		pid = fork();
		if (pid == 0)
		{
			ft_signals(2);
			exec_pipe(pipe_fd, j, temp, s_envp);
		}
		temp = temp->next;
		j++;
	}
	free(temp);
}

void	pipe_handler(t_list **pipe_list, int countpipe, t_envp *s_envp)
{
	int	i;
	int	*pipe_fd;

	i = -1;
	pipe_fd = (int *)malloc(sizeof(int) * countpipe * 2);
	if (pipe_fd == NULL)
	{
		ft_putstr_fd("malloc() in pipe_handler() failed\n", 2);
		ft_free_error_malloc(s_envp);
	}
	while (++i < countpipe)
	{
		if (pipe(pipe_fd + i * 2) < 0)
			exit(1);
	}
	split_pipe(pipe_fd, (*pipe_list), s_envp);
	i = -1;
	while (++i < 2 * countpipe)
		close(pipe_fd[i]);
	countpipe++;
	while (countpipe--)
		waitpid(0, &g_error, WUNTRACED);
	g_error = WEXITSTATUS(g_error);
	if (pipe_fd[0] != '\0')
		free(pipe_fd);
}

void	run_pipe(char *str, int n_pipe, t_envp *s_envp)
{
	s_envp->pipe_list = (t_list **)malloc(sizeof(char *) * (n_pipe + 2));
	if (s_envp->pipe_list == NULL)
	{
		ft_putstr_fd("malloc() in run_pipe() failed\n", 2);
		ft_free_error_malloc(s_envp);
	}
	*s_envp->pipe_list = NULL;
	s_envp->pipe_array = ft_split(str, '|');
	if (add_list(s_envp->pipe_array, s_envp->pipe_list, s_envp) == NULL)
	{
		g_error = 2;
		ft_putstr_fd("syntax error\n", 2);
	}
	else if (parse_pipe(str) == 1)
	{
		g_error = 2;
		ft_putstr_fd("syntax error\n", 2);
	}
	else
		pipe_handler(s_envp->pipe_list, n_pipe, s_envp);
	ft_free_list(s_envp->pipe_list);
	ft_free_str(s_envp->pipe_array);
}
