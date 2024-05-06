/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check_map_ceil_floor.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:15:39 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:43:52 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

static int	check_ceil_floor_range(char *ceil, char *floor)
{
	char	**ceil_range;
	char	**floor_range;

	ceil_range = ft_split(ceil, ',');
	if (ceil_range == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), -1);
	floor_range = ft_split(floor, ',');
	if (floor_range == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2),
			free_double_array(ceil_range), -1);
	if (is_range(ceil_range) == -1 || is_range((floor_range)) == -1)
	{
		ft_putendl_fd(OUT_OF_RANGE, 2);
		free_double_array(ceil_range);
		free_double_array(floor_range);
		return (-1);
	}
	free_double_array(ceil_range);
	free_double_array(floor_range);
	return (0);
}

static int	check_ceil_floor_comma(char *ceil, char *floor)
{
	if (is_comma(ceil, floor) == -1)
	{
		ft_putendl_fd(ERROR_COMMA, 2);
		return (-1);
	}
	return (0);
}

static int	check_ceil_floor_between(char *ceil, char *floor)
{
	int	i;

	i = 0;
	while (ceil[i])
	{
		if (ceil[i] == ' ')
		{
			if (ft_isdigit(ceil[i - 1]) == 1 && ft_isdigit(ceil[i + 1]) == 1)
				return (ft_putendl_fd(ERROR_BETWEEN, 2), -1);
		}
		i++;
	}
	i = 0;
	while (floor[i] && floor[i] != '\n')
	{
		if (floor[i] == ' ')
		{
			if (ft_isdigit(floor[i - 1]) == 1 && ft_isdigit(floor[i + 1]) == 1)
				return (ft_putendl_fd(ERROR_BETWEEN, 2), -1);
		}
		i++;
	}
	return (0);
}

static int	check_ceil_floor_digit(char *ceil, char *floor)
{
	int	i;

	i = 0;
	while (ceil[i])
	{
		if (ft_isdigit(ceil[i]) == 0 && ceil[i] != ',' && ceil[i] != ' ')
		{
			ft_putendl_fd(ERROR_VALUE_CEIL, 2);
			return (-1);
		}
		i++;
	}
	i = 0;
	while (floor[i] && floor[i] != '\n')
	{
		if (ft_isdigit(floor[i]) == 0 && floor[i] != ',' && floor[i] != ' ')
		{
			ft_putendl_fd(ERROR_VALUE_FLOOR, 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_map_ceil_floor(t_game *game, t_map *map)
{
	map->temp_floor = ft_strtrim(map->floor_value, "F ");
	if (map->temp_floor == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), free_all(game), -1);
	map->temp_ceil = ft_strtrim(map->ceil_value, "C ");
	if (map->temp_ceil == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), free(map->temp_floor),
			free_all(game), -1);
	if (check_ceil_floor_digit(map->temp_ceil, map->temp_floor) == -1
		|| check_ceil_floor_between(map->temp_ceil, map->temp_floor) == -1
		|| check_ceil_floor_comma(map->temp_ceil, map->temp_floor) == -1
		|| check_ceil_floor_range(map->temp_ceil, map->temp_floor) == -1)
	{
		free(map->temp_floor);
		free(map->temp_ceil);
		free_all(game);
		return (-1);
	}
	free(map->temp_floor);
	free(map->temp_ceil);
	return (0);
}
