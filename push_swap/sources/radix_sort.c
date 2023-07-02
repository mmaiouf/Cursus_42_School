/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:05:14 by momaiouf          #+#    #+#             */
/*   Updated: 2023/07/02 16:05:14 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	ft_get_max_bits(t_list **stack)
{
	t_list	*temp;
	int		max;
	int		max_bits;

	temp = *stack;
	max = temp->index;
	max_bits = 0;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = -1;
	temp = *stack_a;
	size = ft_lstsize(temp);
	max_bits = ft_get_max_bits(stack_a);
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			temp = *stack_a;
			if (((temp->index >> i) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			ft_pa(stack_a, stack_b);
	}
}
