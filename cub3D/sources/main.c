/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:29:48 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:39:38 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (valid_map(&game, argv) == 0)
		{
			if (init_game(&game) == -1)
				return (EXIT_FAILURE);
			set_hero_position(&game);
			game.map.array[game.map.hero_x][game.map.hero_y] = '0';
			mlx_hook(game.win, 2, 1L << 0, key_press, &game);
			mlx_hook(game.win, 3, 1L << 1, key_release, &game);
			mlx_hook(game.win, KEY_EXIT, 0, game_exit, &game);
			mlx_loop_hook(game.mlx, game_loop, &game);
			mlx_loop(game.mlx);
		}
		else
			return (EXIT_FAILURE);
	}
	else
		ft_putendl_fd(WRONG_NB_ARG, 2);
	return (EXIT_SUCCESS);
}
