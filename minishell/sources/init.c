/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:14:25 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/25 23:48:49 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	init_variables(t_envp *s_envp)
{
	s_envp->array_redir = NULL;
	s_envp->file_redir_in = NULL;
	s_envp->input = NULL;
	s_envp->eof_heredoc = NULL;
	s_envp->epur = NULL;
	s_envp->stdout_copy = 42;
	s_envp->count_pipe_exec = 0;
	s_envp->error_flag_quote = 0;
	s_envp->quote_flag = 0;
	s_envp->command_quotes = NULL;
	s_envp->n_pipe = 0;
	s_envp->n_redir_in = 0;
	s_envp->n_redir_out = 0;
	s_envp->str_quotes_removed = NULL;
	s_envp->temp_name = NULL;
	s_envp->temp_value = NULL;
	s_envp->sub_export = NULL;
	s_envp->array_export = NULL;
	s_envp->sub_unset = NULL;
	s_envp->array_unset = NULL;
	s_envp->pipe_array = NULL;
	s_envp->pipe_list = NULL;
	s_envp->fd_redir_in = 0;
	s_envp->temp_sub_redir_in = NULL;
	s_envp->temp_sub_redir_out = NULL;
}

static void	init_variables2(t_envp *s_envp)
{
	s_envp->file_redir_out = NULL;
	s_envp->temp_lst = NULL;
	s_envp->temp2_lst = NULL;
	s_envp->temp3_lst = NULL;
	s_envp->n_single_quotes = 0;
	s_envp->n_double_quotes = 0;
}

t_envp	*init_envp(char **envp)
{
	int		i;
	t_envp	*s_env;

	i = -1;
	s_env = malloc(sizeof(t_envp));
	if (s_env == NULL)
	{
		ft_close_fd();
		exit(EXIT_FAILURE);
	}
	s_env->env_len = env_len(envp);
	s_env->env_array = malloc(sizeof(char *) * (s_env->env_len + 1));
	if (s_env->env_array == NULL)
	{
		ft_putstr_fd("Error : malloc() in init_envp() failed.\n", 2);
		free(s_env);
		ft_close_fd();
		exit(EXIT_FAILURE);
	}
	init_variables(s_env);
	init_variables2(s_env);
	while (envp[++i])
		s_env->env_array[i] = ft_strdup(envp[i]);
	s_env->env_array[i] = NULL;
	return (s_env);
}

t_envp	*init(char **envp)
{
	t_envp	*s_envp;

	g_error = 0;
	s_envp = init_envp(envp);
	return (s_envp);
}
