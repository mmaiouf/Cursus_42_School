/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:07:06 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 16:43:43 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	export_exec_exist(char *var_name, char *var_val, t_envp *s_envp, int i)
{
	char	*temp;
	char	*temp2;

	if (s_envp->env_array[i][0] != '\0')
		free(s_envp->env_array[i]);
	s_envp->env_array[i] = NULL;
	temp = ft_strjoin("=", var_val);
	temp2 = ft_strjoin(var_name, temp);
	s_envp->env_array[i] = temp2;
	free(temp);
}

void	export_exec_non_existent(char *var_name, char *var_val,
	t_envp *s_envp, int i)
{
	char	*dollar;
	char	*temp;
	char	*temp2;

	s_envp->env_len++;
	realloc_env_array_export(s_envp);
	if (var_val)
	{
		if (count(var_val, '$'))
		{
			temp2 = ft_strtrim(var_val, "$");
			dollar = ft_strdup(getenv(temp2));
			free(temp2);
			ft_strcpy(var_val, dollar);
			free(dollar);
		}
		temp = ft_strjoin("=", var_val);
		s_envp->env_array[i] = ft_strjoin(var_name, temp);
		free(temp);
	}
	else if (var_val == NULL)
		s_envp->env_array[i] = ft_strjoin(var_name, " ");
}
