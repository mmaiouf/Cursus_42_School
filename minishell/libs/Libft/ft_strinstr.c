/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaiouf <mmaiouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:13:13 by momaiouf          #+#    #+#             */
/*   Updated: 2023/12/24 20:11:28 by mmaiouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strinstr(const char *str, const char *tofind)
{
	size_t	i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == tofind[j])
		{
			if (tofind[j + 1] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
