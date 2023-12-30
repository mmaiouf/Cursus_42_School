/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:29:17 by momaiouf          #+#    #+#             */
/*   Updated: 2023/12/24 16:45:33 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_free_redir_out(t_envp *s_envp)
{
	if (s_envp->file_redir_out[0] != '\0')
	{
		free(s_envp->file_redir_out);
		s_envp->file_redir_out = NULL;
	}
	if (s_envp->temp_sub_redir_out[0] != '\0')
		free(s_envp->temp_sub_redir_out);
}

static void	ft_free_error_malloc_part2(t_envp *s_envp)
{
	if (s_envp->str_quotes_removed)
		free(s_envp->str_quotes_removed);
	if (s_envp->command_quotes)
		free(s_envp->command_quotes);
	if (s_envp->epur)
		free(s_envp->epur);
	if (s_envp->input)
		free(s_envp->input);
	if (s_envp->pipe_array)
		ft_free_str(s_envp->pipe_array);
	if (s_envp->pipe_list)
		ft_free_list(s_envp->pipe_list);
	if (s_envp->array_redir)
		ft_free_str(s_envp->array_redir);
}

void	ft_free_error_malloc(t_envp *s_envp)
{
	if (s_envp->temp_name)
		free(s_envp->temp_name);
	if (s_envp->temp_value)
		free(s_envp->temp_value);
	if (s_envp->sub_export)
		free(s_envp->sub_export);
	if (s_envp->array_export)
		ft_free_str(s_envp->array_export);
	if (s_envp->sub_unset)
		free(s_envp->sub_unset);
	if (s_envp->array_unset)
		ft_free_str(s_envp->array_unset);
	ft_free_error_malloc_part2(s_envp);
	ft_free_env(s_envp);
	ft_close_fd();
	exit(EXIT_FAILURE);
}
