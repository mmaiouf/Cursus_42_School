/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:06:51 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:38:58 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	init_texture_img_data_addr(t_game *game, int i, char *dir_path)
{
	int	start;

	start = get_index_spaces_str(dir_path);
	game->sub = ft_substr(dir_path, 0, start + 5);
	if (game->sub == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), game_exit(game));
	game->temp = ft_strtrim(dir_path, game->sub);
	if (game->temp == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), free(game->sub),
			game_exit(game));
	game->join = ft_strjoin("./textures/", game->temp);
	if (game->join == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), free(game->sub),
			free(game->temp), game_exit(game));
	init_array_texture_mlx(game, i);
	free_img_data_addr(game);
	return (0);
}

int	init_textures(t_game *game)
{
	init_texture_img_data_addr(game, 0, game->map.we_path);
	init_texture_img_data_addr(game, 1, game->map.so_path);
	init_texture_img_data_addr(game, 2, game->map.ea_path);
	init_texture_img_data_addr(game, 3, game->map.no_path);
	return (0);
}

void	set_hero_position(t_game *game)
{
	int		lines;
	int		columns;
	char	value;

	lines = game->map.start_map;
	while (game->map.array[lines])
	{
		columns = 0;
		while (game->map.array[lines][columns])
		{
			value = game->map.array[lines][columns];
			if (value == 'S')
				exec_rotate(game, PI);
			else if (value == 'N')
				exec_rotate(game, 0);
			else if (value == 'W')
				exec_rotate(game, 1.5 * PI);
			else if (value == 'E')
				exec_rotate(game, 0.5 * PI);
			columns++;
		}
		lines++;
	}
}

void	init_hero(t_game *game)
{
	t_hero	*hero;

	hero = &game->hero;
	hero->dir.x = -1;
	hero->dir.y = 0;
	hero->plane_x = 0;
	hero->plane_y = 0.66;
	hero->move_velocity = MOVE_VELOCITY;
	hero->rotation_velocity = ROTATION_VELOCITY;
	hero->pos_x = game->map.hero_x + 0.5;
	hero->pos_y = game->map.hero_y + 0.5;
}

int	init_game(t_game *game)
{
	game_struct_init(game);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putendl_fd(MLX_INIT_FAILED, 2);
		free_all(game);
		return (-1);
	}
	game->win = mlx_new_window(game->mlx, game->screen_width,
			game->screen_height, "cub3D");
	if (!game->win)
	{
		ft_putendl_fd(MLX_NW_FAILED, 2);
		free_all(game);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (-1);
	}
	init_hero(game);
	init_array_texture(game);
	init_key_state(game);
	init_textures(game);
	return (0);
}
