/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 01:20:01 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 19:40:15 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	ft_unset(int var_pos, t_envp *s_envp)
{
	int	i;

	s_envp->env_len--;
	if (s_envp->env_array[var_pos][0] != '\0')
		free(s_envp->env_array[var_pos]);
	s_envp->env_array[var_pos] = NULL;
	i = var_pos;
	while (s_envp->env_array[i + 1])
	{
		s_envp->env_array[i] = s_envp->env_array[i + 1];
		s_envp->env_array[i + 1] = NULL;
		i++;
	}
	realloc_env_array_unset(s_envp);
}

void	run_unset(char *str, t_envp *s_envp)
{
	int		i;
	int		j;

	s_envp->sub_export = ft_substr(str, 6, ft_strlen(str) - 6);
	s_envp->array_unset = ft_split(s_envp->sub_export, ' ');
	if (str[5] != ' ' && str[5] != '\0')
	{
		g_error = 127;
		ft_putendl_fd("command not found", 2);
	}
	else if (s_envp->sub_export[0] == '\0')
		g_error = 0;
	i = -1;
	while (s_envp->array_unset[++i])
	{
		j = get_index(s_envp->array_unset[i], s_envp);
		if (s_envp->env_array[j])
			ft_unset(j, s_envp);
	}
	if (s_envp->sub_export[0] != '\0')
		free(s_envp->sub_export);
	if (s_envp->array_unset != NULL)
		ft_free_str(s_envp->array_unset);
}
