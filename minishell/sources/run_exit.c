/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:47:42 by momaiouf          #+#    #+#             */
/*   Updated: 2023/12/21 19:14:28 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	ft_free_exit(char *sub, char *str, char **ar, t_envp *s_envp)
{
	if (sub)
		free(sub);
	if (s_envp->str_quotes_removed)
		free(s_envp->str_quotes_removed);
	if (s_envp->command_quotes)
		free(s_envp->command_quotes);
	if (str)
		free(str);
	if (s_envp->input)
		free(s_envp->input);
	if (ar)
		ft_free_str(ar);
	ft_free_env(s_envp);
}

static int	check_letter(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			ft_putendl_fd("numeric argument required", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_llong_min_max(char *str)
{
	int	len;

	len = ft_strlen(str);
	if ((check_letter(str) == 0) && (len >= 20))
	{
		ft_putendl_fd("numeric argument required", 2);
		return (1);
	}
	return (0);
}

int	run_exit(char *str, t_envp *s_envp)
{
	char	*sub;
	char	**ar;

	sub = ft_substr(str, 5, ft_strlen(str) - 5);
	ar = ft_split(str, ' ');
	if (str[4] != ' ' && str[4] != '\0')
	{
		g_error = 127;
		ft_free_str(ar);
		return (ft_putendl_fd("command not found", 2), free(sub), 1);
	}
	else if (sub[0] == '\0')
		g_error = 0;
	else if (ar[2])
	{
		g_error = 1;
		ft_free_str(ar);
		return (ft_putendl_fd("too many arguments", 2), free(sub), 1);
	}
	else if (check_letter(sub) == 1 || check_llong_min_max(sub) == 1)
		g_error = 2;
	else if (sub)
		g_error = ft_atoi(sub) % 256;
	ft_free_exit(sub, str, ar, s_envp);
	return (0);
}
