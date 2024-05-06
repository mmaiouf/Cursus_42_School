/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check_map_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:44:49 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:37:51 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

static int	check_map_spaces(t_map *map, int i, int j)
{
	map->i_p = i;
	map->j_p = j;
	map->i_m = i;
	map->j_m = j;
	while (map->array[i][map->j_p] && map->array[i][map->j_p] <= 32)
		map->j_p++;
	while (map->j_m > 0 && map->array[i][map->j_m] <= 32)
		map->j_m--;
	if (map->array[i][map->j_m] == '1' && map->array[i][map->j_p] == 0)
		return (1);
	while (map->i_p < (map->nb_lines - 1) && map->array[map->i_p][j] <= 32)
		map->i_p++;
	while (map->i_m > 6 && map->array[map->i_m][j] <= 32)
		map->i_m--;
	if ((map->array[i][map->j_p] == '1' || map->array[i][map->j_p] == ' ' || \
		map->array[i][map->j_p] == '\t') && (map->array[i][map->j_m] == '1' || \
		map->array[i][map->j_m] == ' ' || map->array[i][map->j_m] == '\t') && \
		(map->array[map->i_p][j] == '1' || map->array[map->i_p][j] == ' ' || \
		map->array[map->i_p][j] == '\t') && (map->array[map->i_m][j] == '1' || \
		map->array[map->i_m][j] == ' ' || map->array[map->i_m][j] == '\t'))
		return (1);
	return (-1);
}

static int	check_map_zero(t_map *map, int i, int j)
{
	if (map->array[i][j + 1] <= 32 || (map->array[i][j + 1] != '0' && \
		map->array[i][j + 1] != '1' && map->array[i][j + 1] != 'N' && \
		map->array[i][j + 1] != 'E' && map->array[i][j + 1] != 'S' && \
		map->array[i][j + 1] != 'W'))
		return (-1);
	if (map->array[i][j - 1] <= 32 || (map->array[i][j - 1] != '0' && \
		map->array[i][j - 1] != '1' && map->array[i][j - 1] != 'N' && \
		map->array[i][j - 1] != 'E' && map->array[i][j - 1] != 'S' && \
		map->array[i][j - 1] != 'W'))
		return (-1);
	if (map->array[i + 1][j] <= 32 || (map->array[i + 1][j] != '0' && \
		map->array[i + 1][j] != '1' && map->array[i + 1][j] != 'N' && \
		map->array[i + 1][j] != 'E' && map->array[i + 1][j] != 'S' && \
		map->array[i + 1][j] != 'W'))
		return (-1);
	if (map->array[i - 1][j] <= 32 || (map->array[i - 1][j] != '0' && \
		map->array[i - 1][j] != '1' && map->array[i - 1][j] != 'N' && \
		map->array[i - 1][j] != 'E' && map->array[i - 1][j] != 'S' && \
		map->array[i - 1][j] != 'W'))
		return (-1);
	return (0);
}

int	check_map_wall(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = map->start_map - 1;
	while (map->array[++i])
	{
		j = -1;
		while (map->array[i][++j])
		{
			if (map->array[i][j] <= 32)
				if (check_map_spaces(map, i, j) == -1)
					return (ft_putendl_fd(ERROR_ISLAND, 2), free_all(game), -1);
			if (map->array[i][j] == 'N' || map->array[i][j] == 'E' || \
				map->array[i][j] == 'W' || map->array[i][j] == 'S')
				if (check_map_zero(map, i, j) == -1)
					return (ft_putendl_fd(OUT_OF_MAP_HERO, 2),
						free_all(game), -1);
			if (map->array[i][j] == '0')
				if (j == 0 || i == 6 || i == (map->nb_lines - 1) || \
					check_map_zero(map, i, j) == -1)
					return (ft_putendl_fd(WALL_ERROR, 2), free_all(game), -1);
		}
	}
	return (0);
}
