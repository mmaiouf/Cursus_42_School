/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:04:59 by momaiouf          #+#    #+#             */
/*   Updated: 2023/07/02 16:04:59 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	ft_init_stack(t_list **stack, int ac, char **av)
{
	t_list	*new;
	char	**array;
	int		i;

	i = 0;
	if (ac == 2)
		array = ft_split(av[1], ' ');
	else
	{
		i = 1;
		array = av;
	}
	while (array[i])
	{
		new = ft_lstnew(ft_atoi(array[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	ft_init_index_stack(stack);
	if (ac == 2)
		ft_free_split(array);
}

int	ft_check_is_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (EXIT_FAILURE);
	if (ft_check_args(argc, argv) == 1)
		return (EXIT_FAILURE);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_init_stack(stack_a, argc, argv);
	if (ft_check_is_sorted(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (EXIT_FAILURE);
	}
	if (ft_lstsize(*stack_a) <= 5)
		ft_basic_sort(stack_a, stack_b);
	else
		ft_radix_sort(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (EXIT_SUCCESS);
}
