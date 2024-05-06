/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:32:35 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:37:40 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	is_range(char **range)
{
	int	red;
	int	green;
	int	blue;

	red = ft_atoi(range[0]);
	green = ft_atoi(range[1]);
	blue = ft_atoi(range[2]);
	if ((red < 0 || red > 255) || (green < 0 || green > 255)
		|| (blue < 0 || blue > 255))
	{
		return (-1);
	}
	return (0);
}

int	is_comma(char *ceil, char *floor)
{
	int	i;
	int	nb_comma_ceil;
	int	nb_comma_floor;

	i = 0;
	nb_comma_ceil = 0;
	nb_comma_floor = 0;
	while (ceil[i])
	{
		if (ceil[i] == ',')
			nb_comma_ceil++;
		i++;
	}
	i = 0;
	while (floor[i])
	{
		if (floor[i] == ',')
			nb_comma_floor++;
		i++;
	}
	if (nb_comma_ceil != 2 || nb_comma_floor != 2)
		return (-1);
	return (0);
}

int	is_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= 8 && str[i] <= 12))
			return (0);
		i++;
	}
	return (1);
}

int	parsing_spaces(t_map *map, int i, int j)
{
	j++;
	while (map->array[i][j] && map->array[i][j] <= 32)
		j++;
	return (j);
}

int	is_only_newline_or_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
