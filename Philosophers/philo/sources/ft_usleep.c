/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:40:25 by momaiouf          #+#    #+#             */
/*   Updated: 2023/11/18 17:28:22 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	ft_usleep(long time_loop)
{
	long	start_time;

	start_time = get_time();
	while (get_time() < (start_time + time_loop))
		usleep(100);
}
