/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:40:57 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 19:37:15 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	check_another_redir(t_envp *s_envp, int i)
{
	int		pos;

	pos = i + 2;
	if (s_envp->array_redir[pos + 1] == NULL)
		return (-42);
	while (s_envp->array_redir[pos])
	{
		if (s_envp->array_redir[pos + 1] && \
		(ft_strncmp(s_envp->array_redir[pos], ">", 1) == 0 || \
		ft_strncmp(s_envp->array_redir[pos], ">>", 2) == 0))
		{
			open(s_envp->array_redir[pos - 1], O_CREAT, 0777);
			if (s_envp->array_redir[pos + 2] == NULL)
			{
				i = pos;
				break ;
			}
		}
		pos = pos + 2;
	}
	return (i);
}

void	redir_out_handle(int i, t_envp *s_envp)
{
	int		fd;

	s_envp->temp_sub_redir_out = sub_redir(s_envp->array_redir, i, s_envp);
	if (s_envp->array_redir[i + 2])
		i = check_another_redir(s_envp, i);
	if (i == -42)
	{
		g_error = 2;
		ft_putendl_fd("Syntax error", 2);
	}
	else
	{
		s_envp->file_redir_out = ft_strdup(s_envp->array_redir[i + 1]);
		fd = open(s_envp->file_redir_out, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		exec_dir(s_envp->temp_sub_redir_out, fd, 1, s_envp);
		if (s_envp->file_redir_out[0] != '\0')
		{
			free(s_envp->file_redir_out);
			s_envp->file_redir_out = NULL;
		}
		close(fd);
	}
	if (s_envp->temp_sub_redir_out[0] != '\0')
		free(s_envp->temp_sub_redir_out);
}

void	redir2_out_handle(int i, t_envp *s_envp)
{
	int		fd;

	s_envp->temp_sub_redir_out = sub_redir(s_envp->array_redir, i, s_envp);
	if (s_envp->array_redir[i + 2])
		i = check_another_redir(s_envp, i);
	if (i == -42)
	{
		g_error = 2;
		ft_putendl_fd("Syntax error", 2);
	}
	else
	{
		s_envp->file_redir_out = ft_strdup(s_envp->array_redir[i + 1]);
		fd = open(s_envp->file_redir_out, O_WRONLY | O_CREAT | O_APPEND, 0777);
		exec_dir(s_envp->temp_sub_redir_out, fd, 1, s_envp);
		if (s_envp->file_redir_out[0] != '\0')
		{
			free(s_envp->file_redir_out);
			s_envp->file_redir_out = NULL;
		}
		close(fd);
	}
	if (s_envp->temp_sub_redir_out[0] != '\0')
		free(s_envp->temp_sub_redir_out);
}
