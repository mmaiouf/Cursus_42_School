/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:04:55 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 16:42:36 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	env_len(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

int	ft_var_is_in_env(char *env_var, char *my_var)
{
	int	len;

	len = ft_strlen_equal(env_var);
	if (my_var == NULL)
	{
		ft_putendl_fd("Error Occured !", 2);
		g_error = 127;
	}
	if (ft_strncmp(env_var, my_var, len) == 0)
	{
		if (my_var[len] == '\0' || my_var[len] == '=')
			return (1);
	}
	return (0);
}

int	get_index(char *var_name, t_envp *s_envp)
{
	int		i;

	i = 0;
	while (s_envp->env_array[i])
	{
		if (ft_var_is_in_env(s_envp->env_array[i], var_name))
			return (i);
		i++;
	}
	return (i);
}

void	realloc_env_array_export(t_envp *s_envp)
{
	char	**new_env_array_export;
	int		i;

	new_env_array_export = malloc(sizeof(char *) * (s_envp->env_len + 1));
	if (new_env_array_export == NULL)
	{
		ft_putendl_fd("malloc() in realloc_env_array_export failed", 2);
		ft_free_error_malloc(s_envp);
	}
	i = 0;
	while (s_envp->env_array[i])
	{
		new_env_array_export[i] = ft_strdup(s_envp->env_array[i]);
		free(s_envp->env_array[i]);
		i++;
	}
	new_env_array_export[i + 1] = NULL;
	free(s_envp->env_array);
	s_envp->env_array = new_env_array_export;
}

void	realloc_env_array_unset(t_envp *s_envp)
{
	char	**new_env_array_unset;
	int		i;

	new_env_array_unset = malloc(sizeof(char *) * (s_envp->env_len + 1));
	if (new_env_array_unset == NULL)
	{
		ft_putendl_fd("malloc() in realloc_env_array_unset failed", 2);
		ft_free_error_malloc(s_envp);
	}
	i = 0;
	while (s_envp->env_array[i])
	{
		new_env_array_unset[i] = ft_strdup(s_envp->env_array[i]);
		free(s_envp->env_array[i]);
		i++;
	}
	new_env_array_unset[i] = NULL;
	free(s_envp->env_array);
	s_envp->env_array = new_env_array_unset;
}
