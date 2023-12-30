/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:02:52 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 16:33:26 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	print_echo_envp(t_envp *s_envp, int i, int j)
{
	while (s_envp->env_array[i][++j])
	{
		if (s_envp->env_array[i][j] == '=')
		{
			while (s_envp->env_array[i][++j])
				ft_putchar_fd(s_envp->env_array[i][j], 1);
			break ;
		}
	}
}

static void	get_my_env(char *var_name, t_envp *s_envp)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (s_envp->env_array[i])
	{
		temp = ft_strjoin(var_name, "=");
		if (ft_var_is_in_env(s_envp->env_array[i], temp))
		{
			print_echo_envp(s_envp, i, j);
			ft_putchar_fd(' ', 1);
		}
		free(temp);
		i++;
	}
}

static int	ft_strlen_temp_echo(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i])
		i++;
	return (i);
}

void	echo_dollar_env(char *str, int *i, t_envp *s_envp)
{
	char	*temp;
	int		j;

	temp = malloc(sizeof(char) * ft_strlen_temp_echo(str));
	if (temp == NULL)
	{
		ft_putendl_fd("malloc() in echo_dollar_env failed", 2);
		free(str);
		ft_free_error_malloc(s_envp);
	}
	j = 0;
	(*i)++;
	while (*(str + *i) != ' ' && *(str + *i) != '\"' && *(str + *i))
	{
		temp[j] = *(str + *i);
		(*i)++;
		j++;
	}
	temp[j] = '\0';
	get_my_env(temp, s_envp);
	free(temp);
}

void	print_echo_double_quote(char *str, int *i, t_envp *s_envp)
{
	(*i)++;
	if (*(str + *i) == '$')
		echo_dollar_env(str, i, s_envp);
	else
	{
		while (*(str + *i) != '\"' && *(str + *i))
		{
			ft_putchar_fd(*(str + *i), 1);
			(*i)++;
		}
	}
}
