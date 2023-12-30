/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:16:17 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 16:47:36 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	is_echo(char *str, t_envp *s_envp)
{
	char	*temp;

	temp = remove_quotes(str, s_envp);
	if (!ft_strncmp(temp, "echo", 4))
	{
		free(temp);
		return (1);
	}
	free(temp);
	return (0);
}
