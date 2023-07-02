/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:04:52 by momaiouf          #+#    #+#             */
/*   Updated: 2023/07/02 16:04:52 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static t_list	*ft_get_next_min(t_list **stack)
{
	t_list	*temp;
	t_list	*min;
	int		min_found;

	temp = *stack;
	min_found = 0;
	min = NULL;
	if (!temp)
		return (NULL);
	while (temp)
	{
		if ((temp->index == -1) && (!min_found || temp->content < min->content))
		{
			min_found = 1;
			min = temp;
		}
		temp = temp->next;
	}
	return (min);
}

void	ft_init_index_stack(t_list **stack)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = ft_get_next_min(stack);
	while (temp)
	{
		temp->index = i++;
		temp = ft_get_next_min(stack);
	}
}
