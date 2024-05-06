/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:31:48 by mou3              #+#    #+#             */
/*   Updated: 2024/04/23 00:41:00 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

static int	parsing_rgb(char **array_floor, char **array_ceil)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array_ceil[i])
		i++;
	while (array_floor[j])
		j++;
	if (i != 3 || j != 3)
		return (-1);
	return (0);
}

static int	rgb_map(t_game *game, t_map *map)
{
	map->temp_floor = ft_strtrim(map->floor_value, "F ");
	if (map->temp_floor == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), free_all(game), -1);
	map->temp_ceil = ft_strtrim(map->ceil_value, "C ");
	if (map->temp_ceil == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), free(map->temp_floor),
			free_all(game), -1);
	map->array_floor = ft_split(map->temp_floor, ',');
	if (map->array_floor == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), free(map->temp_floor),
			free(map->temp_ceil), free_all(game), -1);
	map->array_ceil = ft_split(map->temp_ceil, ',');
	if (map->array_ceil == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), free(map->temp_floor),
			free(map->temp_ceil), free_double_array(map->array_floor),
			free_all(game), -1);
	if (parsing_rgb(map->array_floor, map->array_ceil) == -1)
		return (ft_putendl_fd(WRONG_RGB, 2), free_temp_and_array(map),
			free_all(game), -1);
	map->floor_rgb = convert_rgb_in_hexa(ft_atoi(map->array_floor[0]),
			ft_atoi(map->array_floor[1]), ft_atoi(map->array_floor[2]));
	map->ceil_rgb = convert_rgb_in_hexa(ft_atoi(map->array_ceil[0]),
			ft_atoi(map->array_ceil[1]), ft_atoi(map->array_ceil[2]));
	free_temp_and_array(map);
	return (0);
}

static int	check_fill_map(t_game *game, t_map *map)
{
	if (map->floor_value != NULL && map->ceil_value != NULL)
		if (update_one_end(game, map) == -1)
			return (-1);
	if (is_only_newline_or_empty(map->buffer) == 1)
	{
		ft_putendl_fd(EMPTY_MAP, 2);
		free(map->array);
		free(map->buffer);
		return (-1);
	}
	if (is_newline_in_map(map, map->buffer) == 1)
	{
		ft_putendl_fd(NEWLINE_IN_MAP, 2);
		free_all(game);
		return (-1);
	}
	if (map->we_path == NULL || map->so_path == NULL || map->ea_path == NULL
		|| map->no_path == NULL || map->floor_value == NULL
		|| map->ceil_value == NULL)
	{
		ft_putendl_fd(ERROR_DIRECTION, 2);
		free_all(game);
		return (-1);
	}
	return (0);
}

static int	fill_map(t_game *game, t_map *map, int i, int j)
{
	while (map->array[++i])
	{
		j = get_index_spaces(map, i, j);
		if (map->array[i][j] == 'W' && map->array[i][j + 1] == 'E' && \
			map->array[i][j + 2] == ' ')
			map->we_path = ft_strdup(map->array[i]);
		else if (map->array[i][j] == 'S' && map->array[i][j + 1] == 'O' && \
			map->array[i][j + 2] == ' ')
			map->so_path = ft_strdup(map->array[i]);
		else if (map->array[i][j] == 'E' && map->array[i][j + 1] == 'A' && \
			map->array[i][j + 2] == ' ')
			map->ea_path = ft_strdup(map->array[i]);
		else if (map->array[i][j] == 'N' && map->array[i][j + 1] == 'O' && \
			map->array[i][j + 2] == ' ')
			map->no_path = ft_strdup(map->array[i]);
		else if (map->array[i][j] == 'F' && map->array[i][j + 1] == ' ')
			map->floor_value = ft_strdup(map->array[i]);
		else if (map->array[i][j] == 'C' && map->array[i][j + 1] == ' ')
			map->ceil_value = ft_strdup(map->array[i]);
		j = 0;
	}
	if (check_fill_map(game, map) == -1)
		return (-1);
	return (0);
}

int	init_map(t_game *game, t_map *map, char *argv)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	map_struct_init(map);
	if (read_map(map, argv) == -1)
		return (-1);
	map->start_map = get_id_start_map(map);
	map->nb_lines = get_nb_lines_map(map);
	if (check_map_duplicate(game, map) == -1)
		return (-1);
	if (fill_map(game, map, i, j) == -1)
		return (-1);
	if (rgb_map(game, map) == -1)
		return (-1);
	return (0);
}
