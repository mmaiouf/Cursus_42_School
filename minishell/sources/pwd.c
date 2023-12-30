/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:36:42 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 16:51:43 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	run_pwd(char *command)
{
	char	*temp;

	temp = getcwd(NULL, 0);
	if (command[3] != ' ' && command[3] != '\0')
	{
		g_error = 127;
		ft_putendl_fd("command not found", 2);
	}
	else if (temp)
	{
		ft_putendl_fd(temp, 1);
		free(temp);
		g_error = 0;
	}
	else
	{
		ft_putendl_fd("Error occured !", 2);
		g_error = 127;
	}
}
