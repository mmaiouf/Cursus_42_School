/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:52:13 by momaiouf          #+#    #+#             */
/*   Updated: 2023/06/20 20:11:54 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_push(t_list **dest, t_list **src)
{
	t_list		*temp;
	t_list		*temp_dest;
	t_list		*temp_src;

	if (ft_lstsize(*src) == 0)
		return (EXIT_FAILURE);
	temp_dest = *dest;
	temp_src = *src;
	temp = temp_src;
	temp_src = temp_src->next;
	*src = temp_src;
	if (!temp_dest)
	{
		temp_dest = temp;
		temp_dest->next = NULL;
		*dest = temp_dest;
	}
	else
	{
		temp->next = temp_dest;
		*dest = temp;
	}
	return (EXIT_SUCCESS);
}

int	ft_pa(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_a, stack_b) == 1)
		return (EXIT_FAILURE);
	ft_putendl_fd("pa", 1);
	return (EXIT_SUCCESS);
}

int	ft_pb(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_b, stack_a) == 1)
		return (EXIT_FAILURE);
	ft_putendl_fd("pb", 1);
	return (EXIT_SUCCESS);
}
