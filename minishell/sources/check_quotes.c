/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:57:27 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 16:32:17 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int	check_double_quote(char *str, int *i)
{
	(*i)++;
	while (*(str + *i) != '\"' && *(str + *i))
		(*i)++;
	if (*(str + *i) != '\"')
		return (-1);
	return (1);
}

static int	check_single_quote(char *str, int *i)
{
	(*i)++;
	while (*(str + *i) != '\'' && *(str + *i))
		(*i)++;
	if (*(str + *i) != '\'')
		return (-1);
	return (1);
}

int	check_quotes(char *str, t_envp *s_envp)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			s_envp->quote_flag = check_double_quote(str, &i);
		else if (str[i] == '\'')
			s_envp->quote_flag = check_single_quote(str, &i);
		if (s_envp->quote_flag == -1)
			break ;
		i++;
	}
	return (s_envp->quote_flag);
}
