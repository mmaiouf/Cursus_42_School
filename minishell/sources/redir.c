/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:42:52 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 19:37:47 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	redir_out(int i, t_envp *s_envp)
{
	if (s_envp->array_redir[i + 1] == NULL || \
	s_envp->array_redir[i + 1][0] == '<' || \
	s_envp->array_redir[i + 1][0] == '>' || \
	s_envp->array_redir[i + 1][0] == '\0')
	{
		g_error = 2;
		ft_putendl_fd("Syntax error", 2);
	}
	else
	{
		if (!ft_strcmp(s_envp->array_redir[i], ">"))
			redir_out_handle(i, s_envp);
		else if (!ft_strcmp(s_envp->array_redir[i], ">>"))
			redir2_out_handle(i, s_envp);
	}
}

void	redir_in(int i, t_envp *s_envp)
{
	if (s_envp->array_redir[i + 1] == NULL || \
	s_envp->array_redir[i + 1][0] == '<' || \
	s_envp->array_redir[i + 1][0] == '>' || \
	s_envp->array_redir[i + 1][0] == '\0')
	{
		g_error = 2;
		ft_putendl_fd("Syntax error", 2);
	}
	else
	{
		if (!ft_strcmp(s_envp->array_redir[i], "<"))
			redir_in_handle(i, s_envp);
		else if (!ft_strcmp(s_envp->array_redir[i], "<<"))
			redir2_in_handle(i, s_envp);
	}
}

void	run_redir(t_envp *s_envp)
{
	int		i;

	i = -1;
	s_envp->array_redir = ft_split(s_envp->input, ' ');
	while (s_envp->array_redir[++i])
	{
		if ((!ft_strcmp(s_envp->array_redir[i], ">") || \
		!ft_strcmp(s_envp->array_redir[i], ">>")))
		{
			redir_out(i, s_envp);
			break ;
		}
		else if ((!ft_strcmp(s_envp->array_redir[i], "<") || \
		!ft_strcmp(s_envp->array_redir[i], "<<")))
		{
			redir_in(i, s_envp);
			break ;
		}
	}
	if (s_envp->array_redir[i] == NULL)
	{
		g_error = 2;
		ft_putendl_fd("Syntax error", 2);
	}
	ft_free_str(s_envp->array_redir);
}
