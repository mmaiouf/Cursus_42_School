/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:04:28 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 16:41:53 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	run_env(char *command, t_envp *s_envp)
{
	int		i;
	char	*sub;
	int		len;

	i = 0;
	len = ft_strlen(command);
	sub = ft_substr(command, 4, len - 4);
	if (command[3] != ' ' && command[3] != '\0')
	{
		g_error = 127;
		ft_putendl_fd("command not found", 2);
	}
	else
	{
		while (s_envp->env_array[i])
		{
			ft_putendl_fd(s_envp->env_array[i], 1);
			i++;
		}
		g_error = 0;
	}
	free(sub);
}
