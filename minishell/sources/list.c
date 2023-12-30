/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:17:39 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 16:48:36 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_list	**add_list(char **pipe_ar, t_list **lst, t_envp *s_envp)
{
	int		i;

	i = -1;
	while (pipe_ar[++i])
	{
		if (count(pipe_ar[i], '>'))
			s_envp->temp_lst = sub_before_redir_out(pipe_ar[i], '>', s_envp);
		else if (count(pipe_ar[i], '<'))
		{
			s_envp->temp3_lst = sub_without_redir_in(pipe_ar[i], '<', s_envp);
			s_envp->temp_lst = ft_epur_str(s_envp->temp3_lst);
			free(s_envp->temp3_lst);
		}
		else
			s_envp->temp_lst = ft_epur_str(pipe_ar[i]);
		if (s_envp->temp_lst[0] == '\0')
		{
			free(s_envp->temp_lst);
			return (NULL);
		}
		s_envp->temp2_lst = ft_lstnew(s_envp->temp_lst);
		ft_lstadd_back(lst, s_envp->temp2_lst);
	}
	return (lst);
}
