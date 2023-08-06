/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check_mobs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:44:14 by momaiouf          #+#    #+#             */
/*   Updated: 2023/08/01 01:55:19 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_is_mob(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'M')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_nb_mob(t_game *game)
{
	int	i;
	int	j;
	int	nb_mobs;

	i = 0;
	nb_mobs = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'M')
				nb_mobs++;
			j++;
		}
		i++;
	}
	return (nb_mobs);
}
