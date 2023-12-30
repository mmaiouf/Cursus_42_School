/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:54:10 by momaiouf          #+#    #+#             */
/*   Updated: 2023/12/24 19:42:43 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int	ft_strlen_without_redir_in(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '<')
			count++;
		i++;
	}
	return (i - count);
}

char	*sub_without_redir_in(char *str, char c, t_envp *s_envp)
{
	int		i;
	int		j;
	int		len;
	char	*sub;

	i = -1;
	j = 0;
	len = ft_strlen_without_redir_in(str);
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
	{
		ft_putendl_fd("malloc() failed in sub_without_redir_in", 2);
		ft_free_redir_in(s_envp);
		ft_free_error_malloc(s_envp);
	}
	while (str[++i])
	{
		if (str[i] != c)
		{
			sub[j] = str[i];
			j++;
		}
	}
	sub[j] = '\0';
	return (sub);
}

int	ft_strlen_redir(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != '<' || str[i] != '>'))
		i++;
	return (i);
}

char	*sub_before_redir_out(char *str, char c, t_envp *s_envp)
{
	int		i;
	int		len;
	char	*sub;

	i = 0;
	len = ft_strlen_redir(str);
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
	{
		ft_putendl_fd("malloc() failed in sub_without_redir_out", 2);
		ft_free_redir_out(s_envp);
		ft_free_error_malloc(s_envp);
	}
	while (str[i] != '\0' && str[i] != c)
	{
		sub[i] = str[i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
