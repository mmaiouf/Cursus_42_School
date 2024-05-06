/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_read_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:29:35 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:39:13 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

static void	free_lines(t_map *map)
{
	free(map->line);
	free(map->temp);
}

static void	close_free(t_map *map)
{
	free(map->buffer);
	close(map->fd);
}

int	read_map(t_map *map, char *file_map)
{
	map->fd = open(file_map, O_RDONLY);
	if (map->fd == -1)
		return (ft_putendl_fd(OPEN_FAILED, 2), -1);
	map->buffer = ft_strdup("");
	if (map->buffer == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), close(map->fd), -1);
	while (1)
	{
		map->line = get_next_line(map->fd);
		if (map->line == NULL)
			break ;
		map->temp = map->buffer;
		map->buffer = ft_strjoin(map->temp, map->line);
		if (map->buffer == NULL)
			return (ft_putendl_fd(MALLOC_FAIL, 2), close(map->fd),
				free_lines(map), -1);
		free_lines(map);
	}
	map->array = ft_split(map->buffer, '\n');
	if (map->array == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), close_free(map), -1);
	if (close(map->fd) == -1)
		return (ft_putendl_fd(CLOSE_FAILED, 2), -1);
	return (0);
}
