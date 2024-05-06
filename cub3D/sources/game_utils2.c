/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 02:05:36 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:39:29 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	get_index_spaces(t_map *map, int i, int j)
{
	while (map->array[i][j] && map->array[i][j] <= 32)
		j++;
	return (j);
}

int	get_index_spaces_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] <= 32)
		i++;
	return (i);
}

int	is_correct_line_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'W' && \
			str[i] != 'E' && str[i] != 'S' && str[i] != 'N' && \
			str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	get_id_last_newline(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = len - 1;
	while (str[i] == '\n')
		i--;
	return (i + 1);
}

int	get_id_start_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->array[i])
	{
		if (is_start_map(map->array[i]) == 1)
			return (i);
		i++;
	}
	return (0);
}
