/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:29:06 by momaiouf          #+#    #+#             */
/*   Updated: 2024/04/22 23:55:22 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	init_array_texture_mlx(t_game *game, int i)
{
	game->array_texture[i].img = mlx_xpm_file_to_image(game->mlx, game->join,
			&(game->array_texture[i].width), &(game->array_texture[i].height));
	if (!game->array_texture[i].img)
		return (ft_putendl_fd(MLX_FTI_FAILED, 2), free_img_data_addr(game),
			game_exit(game));
	game->array_texture[i].addr = (int *)mlx_get_data_addr(
			game->array_texture[i].img,
			&(game->array_texture[i].bits_per_pixel),
			&(game->array_texture[i].line_length),
			&(game->array_texture[i].endian));
	if (!game->array_texture[i].addr)
		return (ft_putendl_fd(MLX_GDA_FAILED, 2), free_img_data_addr(game),
			game_exit(game));
	return (0);
}

int	init_key_state(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		game->key_state[i] = 0;
		i++;
	}
	return (0);
}

int	init_array_texture(t_game *game)
{
	game->array_texture[0].img = NULL;
	game->array_texture[1].img = NULL;
	game->array_texture[2].img = NULL;
	game->array_texture[3].img = NULL;
	return (0);
}

void	map_struct_init(t_map *map)
{
	map->no_path = NULL;
	map->so_path = NULL;
	map->ea_path = NULL;
	map->we_path = NULL;
	map->floor_value = NULL;
	map->ceil_value = NULL;
	map->array_floor = NULL;
	map->array_ceil = NULL;
	map->temp_floor = NULL;
	map->temp_ceil = NULL;
	map->buffer = NULL;
	map->temp = NULL;
	map->line = NULL;
	map->i = -1;
	map->j = 0;
	map->value_count = 0;
	map->nb_we = 0;
	map->nb_so = 0;
	map->nb_ea = 0;
	map->nb_no = 0;
	map->nb_f = 0;
	map->nb_c = 0;
	map->one_end_ceil = 0;
	map->one_end_floor = 0;
}

void	game_struct_init(t_game *game)
{
	game->screen_width = SCREEN_WIDTH;
	game->screen_height = SCREEN_HEIGHT;
	game->color.floor = game->map.floor_rgb;
	game->color.ceil = game->map.ceil_rgb;
	game->sub = NULL;
	game->temp = NULL;
	game->final = NULL;
	game->join = NULL;
}
