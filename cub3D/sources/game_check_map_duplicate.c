/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check_map_duplicate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:32:35 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:37:34 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

static void	parse_map_duplicate(t_map *map, int i)
{
	while (map->buffer[++i])
	{
		if (map->buffer[i] == 'W' && map->buffer[i + 1] == 'E' && \
			map->buffer[i + 2] == ' ')
			map->nb_we++;
		else if (map->buffer[i] == 'S' && map->buffer[i + 1] == 'O' && \
			map->buffer[i + 2] == ' ')
			map->nb_so++;
		else if (map->buffer[i] == 'E' && map->buffer[i + 1] == 'A' && \
			map->buffer[i + 2] == ' ')
			map->nb_ea++;
		else if (map->buffer[i] == 'N' && map->buffer[i + 1] == 'O' && \
			map->buffer[i + 2] == ' ')
			map->nb_no++;
		else if (map->buffer[i] == 'F' && map->buffer[i + 1] == ' ')
			map->nb_f++;
		else if (map->buffer[i] == 'C' && map->buffer[i + 1] == ' ')
			map->nb_c++;
	}
}

int	check_map_duplicate(t_game *game, t_map *map)
{
	int	i;

	i = -1;
	parse_map_duplicate(map, i);
	if (map->nb_ea > 1 || map->nb_no > 1 || map->nb_so > 1 || map->nb_we > 1
		|| map->nb_c > 1 || map->nb_f > 1)
	{
		ft_putendl_fd(MAP_DUPLPICATE_ERROR, 2);
		free_all(game);
		return (-1);
	}
	return (0);
}
