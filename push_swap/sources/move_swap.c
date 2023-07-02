/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:10:09 by momaiouf          #+#    #+#             */
/*   Updated: 2023/07/02 16:05:09 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	int		temp_first_content;
	int		temp_first_index;

	if (ft_lstsize(*stack) < 2)
		return (EXIT_FAILURE);
	first = *stack;
	second = first->next;
	temp_first_content = first->content;
	temp_first_index = first->index;
	first->content = second->content;
	first->index = second->index;
	second->content = temp_first_content;
	second->index = temp_first_index;
	return (EXIT_SUCCESS);
}

int	ft_sa(t_list **stack_a)
{
	if (ft_swap(stack_a) == 1)
		return (EXIT_FAILURE);
	ft_putendl_fd("sa", 1);
	return (EXIT_SUCCESS);
}
