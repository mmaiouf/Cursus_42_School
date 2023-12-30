/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaiouf <mmaiouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 01:20:52 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 20:05:46 by mmaiouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	*sub_redir(char **str, int i, t_envp *s_envp)
{
	char	*temp;
	int		j;
	int		k;
	int		m;

	j = 0;
	k = 0;
	temp = malloc(sizeof(char) * ft_strlen_redir(s_envp->epur));
	if (temp == NULL)
	{
		ft_putstr_fd("malloc() in sub_redir failed()", 2);
		ft_free_error_malloc(s_envp);
	}
	while (k < i)
	{
		m = 0;
		while (str[k][m])
			temp[j++] = str[k][m++];
		temp[j] = ' ';
		j++;
		k++;
	}
	temp[j - 1] = '\0';
	return (temp);
}

int	ft_is_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= 8 && str[i] <= 12))
			return (0);
		i++;
	}
	return (1);
}

void	ft_close_fd(void)
{
	close(0);
	close(1);
	close(2);
}

int	path_exists(t_envp *s_envp)
{
	int	i;

	i = 0;
	while (s_envp->env_array[i])
	{
		if (ft_strncmp(s_envp->env_array[i], "PATH=", 5) == 0)
		{
			if (ft_strinstr(s_envp->env_array[i], "/usr/bin") || \
				ft_strinstr(s_envp->env_array[i], "/bin"))
				return (1);
		}
		i++;
	}
	return (0);
}
