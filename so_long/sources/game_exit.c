/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:03:52 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/07/30 14:45:57 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	destroy_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_grass);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player_front);
	mlx_destroy_image(game->mlx, game->img_player_back);
	mlx_destroy_image(game->mlx, game->img_player_right);
	mlx_destroy_image(game->mlx, game->img_player_left);
	mlx_destroy_image(game->mlx, game->img_collect_right);
	mlx_destroy_image(game->mlx, game->img_collect_left);
	mlx_destroy_image(game->mlx, game->img_exit_close);
	mlx_destroy_image(game->mlx, game->img_exit_open);
	mlx_destroy_image(game->mlx, game->img_mob_front);
	mlx_destroy_image(game->mlx, game->img_mob_back);
	mlx_destroy_image(game->mlx, game->img_mob_right);
	mlx_destroy_image(game->mlx, game->img_mob_left);
	return (0);
}

int	game_exit(t_game *game)
{
	free_map(game->map);
	destroy_img(game);
	if (game->nb_mobs > 0)
		free(game->mobs);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
