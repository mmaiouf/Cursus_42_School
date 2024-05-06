/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:48:43 by momaiouf          #+#    #+#             */
/*   Updated: 2024/04/23 00:37:15 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	is_start_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	update_one_end(t_game *game, t_map *map)
{
	size_t	i;

	map->temp_floor = ft_strtrim(map->floor_value, "F ");
	if (map->temp_floor == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), free_all(game), -1);
	map->temp_ceil = ft_strtrim(map->ceil_value, "C ");
	if (map->temp_ceil == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), free(map->temp_floor),
			free_all(game), -1);
	i = ft_strlen(map->temp_floor) - 1;
	if (map->temp_floor[i] == '1')
		while (map->temp_floor[i] != ',')
			i--;
	if (map->temp_floor[i] == ',')
		map->one_end_floor = 1;
	i = ft_strlen(map->temp_ceil) - 1;
	if (map->temp_ceil[i] == '1')
		while (map->temp_ceil[i] != ',')
			i--;
	if (map->temp_ceil[i] == ',')
		map->one_end_ceil = 1;
	free(map->temp_floor);
	free(map->temp_ceil);
	return (0);
}
