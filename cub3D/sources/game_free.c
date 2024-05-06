/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:01:16 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:38:19 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

// free les splits
void	free_double_array(char **str)
{
	int	i;

	if (str[0] == NULL)
		return ;
	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_all(t_game *game)
{
	if (game->map.so_path)
		free(game->map.so_path);
	if (game->map.no_path)
		free(game->map.no_path);
	if (game->map.we_path)
		free(game->map.we_path);
	if (game->map.ea_path)
		free(game->map.ea_path);
	if (game->map.floor_value)
		free(game->map.floor_value);
	if (game->map.ceil_value)
		free(game->map.ceil_value);
	if (game->map.buffer)
		free(game->map.buffer);
	if (game->map.array)
		free_double_array(game->map.array);
}

void	free_img_data_addr(t_game *game)
{
	if (game->sub)
		free(game->sub);
	if (game->temp)
		free(game->temp);
	if (game->final)
		free(game->final);
	if (game->join)
		free(game->join);
}

void	free_temp_and_array(t_map *map)
{
	free(map->temp_floor);
	free(map->temp_ceil);
	free_double_array(map->array_floor);
	free_double_array(map->array_ceil);
}
