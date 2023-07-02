/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:40:03 by momaiouf          #+#    #+#             */
/*   Updated: 2023/06/20 20:32:03 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return (EXIT_FAILURE);
	temp = *stack;
	last = ft_lstlast(temp);
	*stack = temp->next;
	temp->next = NULL;
	last->next = temp;
	return (EXIT_SUCCESS);
}

int	ft_ra(t_list **stack_a)
{
	if (ft_rotate(stack_a) == 1)
		return (EXIT_FAILURE);
	ft_putendl_fd("ra", 1);
	return (EXIT_SUCCESS);
}
