/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:35:54 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/08/03 20:56:18 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	check_is_rectangle(char **map)
{
	int	i;
	int	len_lines;

	if (!map)
		return (0);
	i = 0;
	len_lines = 0;
	while (map[len_lines])
		len_lines++;
	if (len_lines < 2)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_is_walled(char **map)
{
	int	i;
	int	j;
	int	len_lines;
	int	len_columns;

	j = 0;
	len_lines = 0;
	while (map[len_lines])
		len_lines++;
	while (map[0][j] && map[len_lines - 1][j])
	{
		if (map[0][j] != '1' || map[len_lines - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len_columns = ft_strlen(map[i]);
	while (map[i])
	{
		if ((map[i][0] != '1') || (map[i][len_columns - 1] != '1'))
			return (0);
		i++;
	}
	return (1);
}

static int	check_is_cep(t_game *game)
{
	int	i;
	int	j;

	game->nb_collect = 0;
	game->nb_exit = 0;
	game->nb_player = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->nb_collect++;
			else if (game->map[i][j] == 'E')
				game->nb_exit++;
			else if (game->map[i][j] == 'P')
				game->nb_player++;
			j++;
		}
		i++;
	}
	if (game->nb_collect == 0 || game->nb_exit != 1 || game->nb_player != 1)
		return (0);
	return (1);
}

static int	check_is_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'M')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_is_map(t_game *game)
{
	if (!check_is_rectangle(game->map))
	{
		ft_putendl_fd(IS_NOT_RECTANGLE, 2);
		return (0);
	}
	if (!check_is_walled(game->map))
	{
		ft_putendl_fd(IS_NOT_WALLED, 2);
		return (0);
	}
	if (!check_is_cep(game))
	{
		ft_putendl_fd(IS_NOT_CEP, 2);
		return (0);
	}
	if (!check_is_valid(game->map))
	{
		ft_putendl_fd(IS_NOT_VALID, 2);
		return (0);
	}
	return (1);
}
