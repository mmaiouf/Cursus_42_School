/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:47:47 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 16:32:01 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	run_cd(char *command)
{
	int		len;
	char	*sub;

	len = ft_strlen(command);
	sub = ft_substr(command, 3, len - 3);
	if (sub[0] == '\0' || sub[0] == '~')
		sub = ft_strdup(getenv("HOME"));
	if (command[2] != ' ' && command[2] != '\0')
	{
		g_error = 127;
		ft_putendl_fd("command not found", 2);
	}
	else if (chdir(sub) < 0)
	{
		g_error = 1;
		ft_putendl_fd("cd : No such file or directory", 2);
	}
	free(sub);
}
