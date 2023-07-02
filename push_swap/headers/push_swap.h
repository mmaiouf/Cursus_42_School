/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:05:21 by momaiouf          #+#    #+#             */
/*   Updated: 2023/07/02 16:05:21 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"

int		ft_swap(t_list **stack);
int		ft_sa(t_list **stack_a);
int		ft_push(t_list **dest, t_list **src);
int		ft_pa(t_list **stack_a, t_list **stack_b);
int		ft_pb(t_list **stack_a, t_list **stack_b);
int		ft_rotate(t_list **stack);
int		ft_ra(t_list **stack_a);
int		ft_reverse_rotate(t_list **stack);
int		ft_rra(t_list **stack_a);
void	ft_basic_sort(t_list **stack_a, t_list **stack_b);
int		ft_check_is_sorted(t_list **stack);
int		ft_check_args(int ac, char **av);
void	ft_free_split(char **str);
void	ft_free_stack(t_list **stack);
void	ft_init_index_stack(t_list **stack);
void	ft_radix_sort(t_list **stack_a, t_list **stack_b);

#endif