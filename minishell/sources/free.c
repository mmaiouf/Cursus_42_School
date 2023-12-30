/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:12:28 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 16:45:04 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_free_str(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_lstdelete(t_list *lst)
{
	free(lst->content);
	free(lst);
	lst = NULL;
}

void	ft_free_list(t_list **list)
{
	t_list	*tmp;

	if (list)
	{
		while (*list)
		{
			tmp = (*list)->next;
			ft_lstdelete(*list);
			*list = tmp;
		}
		free(list);
	}
}

void	ft_free_env(t_envp *s_envp)
{
	int	i;

	i = 0;
	while (s_envp->env_array[i])
	{
		free(s_envp->env_array[i]);
		i++;
	}
	free(s_envp->env_array);
	free(s_envp);
	s_envp = NULL;
}

void	ft_free_redir_in(t_envp *s_envp)
{
	if (s_envp->file_redir_in[0] != '\0')
	{
		free(s_envp->file_redir_in);
		s_envp->file_redir_in = NULL;
	}
	if (s_envp->temp_sub_redir_in[0] != '\0')
		free(s_envp->temp_sub_redir_in);
	if (s_envp->fd_redir_in == -1)
		g_error = 1;
}
