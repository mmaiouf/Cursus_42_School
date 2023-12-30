/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:35:30 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/28 15:09:16 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int	parsing_quotes_spaces(t_envp *s_envp)
{
	int		i;

	i = 0;
	s_envp->command_quotes = remove_quotes_specific(s_envp->input, s_envp);
	while (s_envp->command_quotes[i])
	{
		if (s_envp->command_quotes[i] == ' ' || \
			s_envp->command_quotes[i] == '\t')
			return (1);
		i++;
	}
	return (0);
}

static void	ft_init_count(t_envp *s_envp)
{
	s_envp->n_pipe = count(s_envp->input, '|');
	s_envp->n_redir_out = count(s_envp->input, '>');
	s_envp->n_redir_in = count(s_envp->input, '<');
	s_envp->n_single_quotes = count(s_envp->input, '\'');
	s_envp->n_double_quotes = count(s_envp->input, '\"');
}

void	parsing_command(t_envp *s_envp)
{
	s_envp->error_flag_quote = 0;
	s_envp->quote_flag = 0;
	if (check_quotes(s_envp->input, s_envp) == 1)
	{
		if (parsing_quotes_spaces(s_envp) == 1)
			s_envp->error_flag_quote = 1;
	}
	else if (check_quotes(s_envp->input, s_envp) == -1)
		s_envp->error_flag_quote = 1;
	s_envp->str_quotes_removed = remove_quotes(s_envp->input, s_envp);
	s_envp->epur = ft_epur_str(s_envp->str_quotes_removed);
	ft_init_count(s_envp);
	if ((s_envp->n_redir_out > 0 || s_envp->n_redir_in > 0) && \
		(s_envp->n_single_quotes == 0 && s_envp->n_double_quotes == 0))
		run_redir(s_envp);
	else if (s_envp->n_pipe > 0 && \
		(s_envp->n_redir_out == 0 && s_envp->n_redir_in == 0))
		run_pipe(s_envp->epur, s_envp->n_pipe, s_envp);
	else if (is_builtin(s_envp->epur, s_envp) > 0)
		run_builtin(s_envp->epur, s_envp);
	else
		run_simple(s_envp->epur, s_envp);
	free(s_envp->epur);
	free(s_envp->str_quotes_removed);
}
