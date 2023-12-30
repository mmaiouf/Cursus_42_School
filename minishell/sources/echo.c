/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:04:02 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/25 15:53:32 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	echo_management(char *str, t_envp *s_envp)
{
	if (check_quotes(str, s_envp) == -1)
	{
		g_error = 2;
		ft_putendl_fd("syntax error", 2);
	}
	else
	{
		if (s_envp->n_flag == 1)
			exec_echo_with_n(str, s_envp);
		else if (s_envp->n_flag == -1)
			exec_echo_without_n(str, s_envp);
	}
}

static char	*find_start_n(char *str, int last, int start)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i])
	{
		if (i > 0 && str[i - 1] == ' ' && (str[i] == '-' && str[i + 1] == 'n')
			&& (str[i + 2] == ' ' || str[i + 2] == 'n'))
		{
			i = i + 2;
			while (str[i] != '\0' && (str[i] < 33 || str[i] == 'n' || \
					str[i] == '-'))
				i++;
			start = i;
			break ;
		}
		i++;
	}
	temp = ft_substr(str, start, last + 1);
	return (temp);
}

static char	*find_start(char *str, int last, int start)
{
	int		i;
	char	*temp;

	i = -1;
	while (str[++i])
	{
		if (str[i + 1] != '\0' && str[i + 1] > 32)
			;
		else
		{
			i++;
			while (str[i] != '\0' && str[i] < 33)
				i++;
			if (str[i] == 'e' && str[i + 1] == 'c' && str[i + 2] == 'h' && \
				str[i + 3] == 'o')
				i = i + 4;
			while (str[i] != '\0' && str[i] < 33)
				i++;
			start = i;
			break ;
		}
	}
	temp = ft_substr(str, start, last + 1);
	return (temp);
}

static char	*get_echo_str(char *str, t_envp *s_envp)
{
	int		last;
	int		start;
	int		len;
	char	*temp;

	last = 0;
	start = 0;
	len = ft_strlen(str) - 1;
	while (len)
	{
		if (str[len] > 32 && str[len] < 127)
		{
			last = len;
			str[last + 1] = '\0';
			break ;
		}
		len--;
	}
	if (s_envp->n_flag == 1)
		temp = find_start_n(str, last, start);
	else
		temp = find_start(str, last, start);
	return (temp);
}

void	run_echo(char *str, t_envp *s_envp)
{
	char	*temp;

	s_envp->n_flag = check_flag_n(str);
	if (s_envp->n_redir_out > 0 || s_envp->n_redir_in > 0)
		temp = get_echo_str(str, s_envp);
	else
		temp = get_echo_str(s_envp->input, s_envp);
	if (s_envp->epur[4] != ' ' && s_envp->epur[4] != '\0')
	{
		g_error = 127;
		ft_putendl_fd("command not found", 2);
	}
	else if (s_envp->epur[4] == '\0')
	{
		g_error = 0;
		ft_putchar_fd('\n', 1);
	}
	else if (check_flag_n_empty(s_envp->epur) == 1)
		g_error = 0;
	else
		echo_management(temp, s_envp);
	if (temp[0] != '\0')
		free(temp);
}
