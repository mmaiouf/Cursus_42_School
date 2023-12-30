/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:58:01 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 16:33:02 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	print_echo_single_quote(char *str, int *i)
{
	(*i)++;
	while (*(str + *i) != '\'' && *(str + *i))
	{
		ft_putchar_fd(*(str + *i), 1);
		(*i)++;
	}
}

void	exec_echo_with_n(char *str, t_envp *s_envp)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			print_echo_double_quote(str, &i, s_envp);
		else if (str[i] == '\'')
			print_echo_single_quote(str, &i);
		else if (str[i] == '$' && str[i + 1] == '?' && ++i)
			ft_putnbr_fd(g_error, 1);
		else if (str[i] == '$')
			echo_dollar_env(str, &i, s_envp);
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
}

void	exec_echo_without_n(char *str, t_envp *s_envp)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			print_echo_double_quote(str, &i, s_envp);
		else if (str[i] == '\'')
			print_echo_single_quote(str, &i);
		else if (str[i] == '$' && str[i + 1] == '?' && ++i)
			ft_putnbr_fd(g_error, 1);
		else if (str[i] == '$')
			echo_dollar_env(str, &i, s_envp);
		else
			ft_putchar_fd(str[i], 1);
		if (str[i] == '\0')
			break ;
		i++;
	}
	ft_putchar_fd('\n', 1);
}

int	check_flag_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	if (str[i - 1] == ' ' && (str[i] == '-' && str[i + 1] == 'n'))
	{
		i++;
		while (str[i] && str[i] == 'n')
			i++;
	}
	if (str[i] != ' ' && str[i] != '\t')
		return (-1);
	return (1);
}

int	check_flag_n_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	if (str[i - 1] == ' ' && (str[i] == '-' && str[i + 1] == 'n')
		&& str[i + 2] == '\0')
		return (1);
	return (-1);
}
