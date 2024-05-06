/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:31:29 by mou3              #+#    #+#             */
/*   Updated: 2024/04/23 00:24:58 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

unsigned long	convert_rgb_in_hexa(int red, int green, int blue)
{
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}

int	get_nb_lines_map(t_map *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map->array[i])
	{
		if (map->array[i])
			count++;
		i++;
	}
	return (count);
}

int	is_only_wall(char *str, int i)
{
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_newline_in_map(t_map *map, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' && (map->one_end_floor == 0 && \
			map->one_end_ceil == 0))
		{
			if (is_only_wall(str, i) == 1)
			{
				if (get_id_start_newline(str, i) < get_id_last_newline(str))
					return (1);
			}
		}
		i++;
	}
	return (0);
}

int	get_id_start_newline(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (i);
		i++;
	}
	return (i);
}
