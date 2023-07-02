/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:04:31 by momaiouf          #+#    #+#             */
/*   Updated: 2023/07/02 16:04:31 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	ft_get_min(t_list **stack)
{
	t_list	*temp;
	int		min;

	temp = *stack;
	min = temp->index;
	while (temp)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	return (min);
}

static void	ft_sort_3(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	while (!ft_check_is_sorted(stack_a))
	{
		if ((temp->content > temp->next->next->content)
			&& (temp->next->content < temp->next->next->content))
			ft_ra(stack_a);
		else if (temp->content > temp->next->content)
			ft_sa(stack_a);
		else
			ft_rra(stack_a);
		temp = *stack_a;
	}
}

static void	ft_sort_4_5(t_list **stack_a, t_list **stack_b)
{
	int		min;
	t_list	*temp;

	temp = *stack_a;
	while (!ft_check_is_sorted(stack_a))
	{
		temp = *stack_a;
		min = ft_get_min(stack_a);
		if (temp->index == min)
		{
			ft_pb(stack_a, stack_b);
			if (ft_lstsize(*stack_a) == 3)
				break ;
		}
		else if (temp->next->index == min)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
	if (!ft_check_is_sorted(stack_a))
		ft_sort_3(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

void	ft_basic_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		ft_sa(stack_a);
	else if (size == 3)
		ft_sort_3(stack_a);
	else if (size > 3 && size <= 5)
		ft_sort_4_5(stack_a, stack_b);
}
