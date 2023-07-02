/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:08:02 by momaiouf          #+#    #+#             */
/*   Updated: 2023/07/02 15:56:23 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	ft_check_nb(char *nb)
{
	int	i;

	i = 0;
	if ((nb[0] == '-' || nb[0] == '+') && (ft_isdigit(nb[1])))
		i++;
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_duplicate(int nb, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_min_max(long nb)
{
	if (nb < -2147483648 || nb > 2147483647)
		return (1);
	return (0);
}

int	ft_check_args(int ac, char **av)
{
	int		i;
	char	**tab;

	i = -1;
	if (ac == 2)
		tab = ft_split(av[1], ' ');
	else
	{
		i = 0;
		tab = av;
	}
	while (tab[++i])
	{
		if (!ft_check_nb(tab[i]) || ft_check_duplicate(ft_atoi(tab[i]), tab, i)
			|| ft_check_min_max(ft_atoi(tab[i])) || ft_strlen(tab[i]) > 11)
		{
			ft_putendl_fd("Error", 2);
			if (ac == 2)
				ft_free_split(tab);
			return (EXIT_FAILURE);
		}
	}
	if (ac == 2)
		ft_free_split(tab);
	return (EXIT_SUCCESS);
}
