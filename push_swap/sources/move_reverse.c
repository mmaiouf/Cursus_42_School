/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:41:20 by momaiouf          #+#    #+#             */
/*   Updated: 2023/06/20 21:20:00 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return (EXIT_FAILURE);
	temp = *stack;
	last = ft_lstlast(temp);
	while (temp)
	{
		if (temp->next->next == NULL)
		{
			temp->next = NULL;
			break ;
		}
		temp = temp->next;
	}
	last->next = *stack;
	*stack = last;
	return (EXIT_SUCCESS);
}

int	ft_rra(t_list **stack_a)
{
	if (ft_reverse_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}
