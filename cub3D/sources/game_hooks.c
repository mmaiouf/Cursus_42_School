/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:48:39 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:38:28 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_LEFT)
		game->key_state[ID_LEFT] = 0;
	if (keycode == KEY_RIGHT)
		game->key_state[ID_RIGHT] = 0;
	if (keycode == KEY_W)
		game->key_state[ID_W] = 0;
	if (keycode == KEY_S)
		game->key_state[ID_S] = 0;
	if (keycode == KEY_A)
		game->key_state[ID_A] = 0;
	if (keycode == KEY_D)
		game->key_state[ID_D] = 0;
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_LEFT)
		game->key_state[ID_LEFT] = 1;
	if (keycode == KEY_RIGHT)
		game->key_state[ID_RIGHT] = 1;
	if (keycode == KEY_W)
		game->key_state[ID_W] = 1;
	if (keycode == KEY_S)
		game->key_state[ID_S] = 1;
	if (keycode == KEY_A)
		game->key_state[ID_A] = 1;
	if (keycode == KEY_D)
		game->key_state[ID_D] = 1;
	if (keycode == KEY_ESC)
		game_exit(game);
	return (0);
}
