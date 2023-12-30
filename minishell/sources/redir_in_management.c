/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaiouf <mmaiouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:39:01 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 20:05:32 by mmaiouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	here_doc(char *file, char *eof)
{
	char	*line;
	int		fd_temp;

	g_error = 0;
	ft_signals(3);
	line = ft_strdup("");
	fd_temp = open(file, O_RDWR | O_CREAT | O_TRUNC, 0777);
	while (ft_strcmp(line, eof))
	{
		free(line);
		rl_event_hook = event;
		line = readline("> ");
		if (g_error == 130)
			break ;
		if (line == NULL)
		{
			ft_putstr_fd("warning: here-doc delimited by end-of-file\n", 2);
			break ;
		}
		else if (line && ft_strcmp(line, eof))
			ft_putendl_fd(line, fd_temp);
	}
	close(fd_temp);
	if (line)
		free(line);
}

void	mixed_redir(char *str, char *temp, int fd, t_envp *s_envp)
{
	int		last_fd;

	if (str == NULL)
	{
		g_error = 2;
		ft_putendl_fd("Syntax error", 2);
	}
	else
	{
		s_envp->stdout_copy = dup(1);
		last_fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2(last_fd, 1);
		close(last_fd);
		exec_dir(temp, fd, 0, s_envp);
		dup2(s_envp->stdout_copy, 1);
		close(s_envp->stdout_copy);
	}
}

void	mixed_redir2(char *str, char *temp, int fd, t_envp *s_envp)
{
	int		last_fd;

	if (str == NULL)
	{
		g_error = 2;
		ft_putendl_fd("Syntax error", 2);
	}
	else
	{
		s_envp->stdout_copy = dup(1);
		last_fd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0777);
		dup2(last_fd, 1);
		close(last_fd);
		exec_dir(temp, fd, 0, s_envp);
		dup2(s_envp->stdout_copy, 1);
		close(s_envp->stdout_copy);
	}
}

void	redir_in_handle(int i, t_envp *s_envp)
{
	s_envp->temp_sub_redir_in = sub_redir(s_envp->array_redir, i, s_envp);
	s_envp->file_redir_in = ft_strdup(s_envp->array_redir[i + 1]);
	s_envp->fd_redir_in = open(s_envp->file_redir_in, O_RDONLY, 0777);
	if (s_envp->fd_redir_in == -1)
		ft_putstr_fd("No such file or directory\n", 2);
	else
	{
		if (s_envp->array_redir[i + 2] && s_envp->array_redir[i + 2][0] == '>')
		{
			if (s_envp->array_redir[i + 2][1] == '>')
				mixed_redir2(s_envp->array_redir[i + 3],
					s_envp->temp_sub_redir_in, s_envp->fd_redir_in, s_envp);
			else
				mixed_redir(s_envp->array_redir[i + 3],
					s_envp->temp_sub_redir_in, s_envp->fd_redir_in, s_envp);
		}
		else
			exec_dir(s_envp->temp_sub_redir_in, s_envp->fd_redir_in, 0, s_envp);
		if (close(s_envp->fd_redir_in) == -1)
			ft_putstr_fd("failed to close", 2);
	}
	ft_free_redir_in(s_envp);
}

void	redir2_in_handle(int i, t_envp *s_envp)
{
	int		fd;
	char	*temp;

	temp = sub_redir(s_envp->array_redir, i, s_envp);
	s_envp->eof_heredoc = ft_strdup(s_envp->array_redir[i + 1]);
	here_doc("temp.txt", s_envp->eof_heredoc);
	fd = open("temp.txt", O_RDONLY, 0777);
	if (s_envp->array_redir[i + 2] && s_envp->array_redir[i + 2][0] == '>')
	{
		if (s_envp->array_redir[i + 2][1] == '>')
			mixed_redir2(s_envp->array_redir[i + 3], temp, fd, s_envp);
		else
			mixed_redir(s_envp->array_redir[i + 3], temp, fd, s_envp);
	}
	else if (g_error != 130)
		exec_dir(temp, fd, 0, s_envp);
	unlink("temp.txt");
	if (s_envp->eof_heredoc)
	{
		free(s_envp->eof_heredoc);
		s_envp->eof_heredoc = NULL;
	}
	if (temp)
		free(temp);
	close(fd);
}
