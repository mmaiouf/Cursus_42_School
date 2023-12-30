/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaiouf <mmaiouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:57:24 by momaiouf          #+#    #+#             */
/*   Updated: 2023/12/24 20:02:23 by mmaiouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	get_index_max_quote(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			i++;
			while (str[i] && str[i] != '\'' && str[i] != '\"')
			{
				i++;
				count++;
			}
		}
		if (str[i] == '\0' || str[i] == '\'' || str[i] == '\"')
			break ;
		i++;
	}
	return (count);
}

char	*remove_quotes_specific(char *str, t_envp *s_envp)
{
	char	*temp;
	int		i;
	int		j;

	i = -1;
	j = -1;
	temp = malloc(sizeof(char) * (get_index_max_quote(str) + 1));
	if (temp == NULL)
		ft_free_error_malloc(s_envp);
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			i++;
			while (str[i] && str[i] != '\'' && str[i] != '\"')
			{
				temp[++j] = str[i];
				i++;
			}
		}
		if (str[i] == '\0' || str[i] == '\'' || str[i] == '\"')
			break ;
	}
	temp[j + 1] = '\0';
	return (temp);
}

int	count_quotes(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			count++;
		i++;
	}
	return (i - count);
}

char	*remove_quotes(char *str, t_envp *s_envp)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = malloc(sizeof(char) * (count_quotes(str) + 1));
	if (temp == NULL)
	{
		ft_putstr_fd("malloc() in remove_quotes() failed\n", 2);
		ft_free_error_malloc(s_envp);
	}
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
			temp[j++] = str[i];
		i++;
	}
	temp[j] = '\0';
	return (temp);
}
