/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:43:15 by mou3              #+#    #+#             */
/*   Updated: 2023/12/24 19:43:45 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_strlen_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

int	parse_pipe(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
		{
			while (str[i] != '\0')
			{
				if (str[i] == '|' && (str[i + 1] == '\0' || str[i + 1] == '|'))
					return (1);
				i++;
			}
		}
		if (str[i] != '\0')
			i++;
	}
	return (0);
}

int	event(void)
{
	return (0);
}
