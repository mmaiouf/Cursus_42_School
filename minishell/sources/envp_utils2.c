/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:06:04 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 16:43:03 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	**sort_envp(char **envp)
{
	int			i;
	char		*temp;

	i = 0;
	while (envp[i] && envp[i + 1])
	{
		if (ft_strcmp(envp[i], envp[i + 1]) > 0)
		{
			temp = envp[i];
			envp[i] = envp[i + 1];
			envp[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	return (envp);
}

void	print_export(t_envp *s_envp)
{
	int		i;
	char	**env_sort;
	char	*temp;

	i = 0;
	env_sort = sort_envp(s_envp->env_array);
	while (env_sort[i])
	{
		temp = ft_strjoin("declare -x ", env_sort[i]);
		ft_putendl_fd(temp, 1);
		free(temp);
		i++;
	}
}
