/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaiouf <mmaiouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:09:09 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 20:04:26 by mmaiouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_export(char *var_name, char *var_val, t_envp *s_envp)
{
	int	i;

	i = get_index(var_name, s_envp);
	if (s_envp->env_array[i])
		export_exec_exist(var_name, var_val, s_envp, i);
	else if (s_envp->env_array[i] == NULL)
		export_exec_non_existent(var_name, var_val, s_envp, i);
}

static void	get_name_and_value_env(char **array, t_envp *s_envp, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (array[i][j] != '=')
		s_envp->temp_name[k++] = array[i][j++];
	s_envp->temp_name[k] = '\0';
	k = 0;
	if (array[i][j] == '=')
	{
		while (array[i][j] != '\0')
			s_envp->temp_value[k++] = array[i][++j];
		s_envp->temp_value[k] = '\0';
	}
}

void	export_with_equal(char **array, t_envp *s_envp, int i)
{
	s_envp->temp_name = malloc(sizeof(char) * (ft_strlen_equal(array[i]) + 1));
	if (s_envp->temp_name == NULL)
	{
		ft_putstr_fd("malloc() failed in export_with_equal", 2);
		ft_free_error_malloc(s_envp);
	}
	s_envp->temp_value = malloc(sizeof(char) * \
			((ft_strlen(array[i]) - ft_strlen_equal(array[i])) + 1));
	if (s_envp->temp_value == NULL)
	{
		ft_putstr_fd("malloc() failed in export_with_equal", 2);
		ft_free_error_malloc(s_envp);
	}
	get_name_and_value_env(array, s_envp, i);
	ft_export(s_envp->temp_name, s_envp->temp_value, s_envp);
	if (s_envp->temp_name)
	{
		free(s_envp->temp_name);
		s_envp->temp_name = NULL;
	}
	if (s_envp->temp_value)
	{
		free(s_envp->temp_value);
		s_envp->temp_value = NULL;
	}
}

void	run_export2(char *str, t_envp *s_envp)
{
	int		i;
	int		equal;

	s_envp->array_export = ft_split(str, ' ');
	i = -1;
	while (s_envp->array_export[++i])
	{
		equal = count(s_envp->array_export[i], '=');
		if (equal > 0)
			export_with_equal(s_envp->array_export, s_envp, i);
		else if (equal == 0)
			g_error = 0;
	}
	if (s_envp->array_export)
	{
		ft_free_str(s_envp->array_export);
		s_envp->array_export = NULL;
	}
}

void	run_export(char *str, t_envp *s_envp)
{
	int		len;

	len = ft_strlen(str);
	s_envp->sub_export = ft_substr(str, 7, len - 7);
	if (str[6] != ' ' && str[6] != '\0')
	{
		g_error = 127;
		ft_putendl_fd("command not found", 2);
	}
	else if (str[0] == '\0')
		print_export(s_envp);
	else
		run_export2(str, s_envp);
	free(s_envp->sub_export);
}
