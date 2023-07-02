/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:04:44 by momaiouf          #+#    #+#             */
/*   Updated: 2023/07/02 16:04:44 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_free_split(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*temp;
	t_list	*delete;

	temp = *stack;
	while (temp)
	{
		delete = temp;
		temp = temp->next;
		free(delete);
	}
	free(stack);
}
