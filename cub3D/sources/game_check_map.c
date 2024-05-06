/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:01:55 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:37:59 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

static int	is_correct(t_map *map, int i, int j)
{
	if (i >= map->start_map)
	{
		if ((is_only_spaces(map->array[i]) == 1) || \
			(is_correct_line_map(map->array[i]) == 1))
			return (1);
	}
	else
	{
		if ((map->array[i][j] == 'W' && map->array[i][j + 1] == 'E' && \
		map->array[i][j + 2] == ' ') || (map->array[i][j] == 'S' && \
		map->array[i][j + 1] == 'O' && map->array[i][j + 2] == ' ') || \
		(map->array[i][j] == 'E' && map->array[i][j + 1] == 'A' && \
		map->array[i][j + 2] == ' ') || (map->array[i][j] == 'N' && \
		map->array[i][j + 1] == 'O' && map->array[i][j + 2] == ' ') || \
		(map->array[i][j] == 'F' && map->array[i][j + 1] == ' ') || \
		(map->array[i][j] == 'C' && map->array[i][j + 1] == ' ') || \
		(is_only_spaces(map->array[i]) == 1))
			return (1);
	}
	return (-1);
}

int	check_map_file(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->array[i])
	{
		j = 0;
		if ((map->array[i][j] == ' ') || (map->array[i][j] == '\t'))
			j = parsing_spaces(map, i, j);
		if (is_correct(map, i, j) == 1)
			i++;
		else
		{
			ft_putendl_fd(MAP_NO_VALID, 2);
			free_all(game);
			return (-1);
		}
	}
	return (0);
}

int	check_map_hero(t_game *game, t_map *map)
{
	int	i;
	int	j;
	int	count_hero;

	i = map->start_map;
	count_hero = 0;
	while (map->array[i])
	{
		j = -1;
		while (map->array[i][++j])
		{
			if (ft_strchr("NSWE", map->array[i][j]) != 0)
			{
				map->hero_x = i;
				map->hero_y = j;
				count_hero++;
			}
		}
		i++;
	}
	if (count_hero == 1)
		return (0);
	ft_putendl_fd(MAP_HERO_ERROR, 2);
	free_all(game);
	return (-1);
}

int	check_map_name(char *map_name)
{
	int	i;
	int	fd;

	i = 0;
	while (map_name[i])
		i++;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd(FILE_DOESNT_EXIST, 2), -1);
	if (map_name[i] == '\0' && map_name[i - 1] == 'b' && map_name[i - 2] == 'u'
		&& map_name [i - 3] == 'c' && map_name [i - 4] == '.')
		return (close(fd), 1);
	ft_putendl_fd(IS_NOT_CUB, 2);
	close(fd);
	return (-1);
}

int	valid_map(t_game *game, char **argv)
{
	if (check_map_name(argv[1]) == -1)
		return (-1);
	if (init_map(game, &game->map, argv[1]) == -1)
		return (-1);
	if (check_map_file(game, &game->map) == -1)
		return (-1);
	if (check_map_hero(game, &game->map) == -1)
		return (-1);
	if (check_map_wall(game, &game->map) == -1)
		return (-1);
	if (check_map_ceil_floor(game, &game->map) == -1)
		return (-1);
	return (0);
}
