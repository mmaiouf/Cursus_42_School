/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_get_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:28:59 by mou3              #+#    #+#             */
/*   Updated: 2024/04/22 20:38:24 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

t_img	*get_texture(t_game *game)
{
	if (game->raycast.side == 1)
	{
		if ((game->raycast.raydir_x <= 0 && game->raycast.raydir_y <= 0)
			|| (game->raycast.raydir_x >= 0 && game->raycast.raydir_y <= 0))
			return (&game->array_texture[0]);
		else
			return (&game->array_texture[2]);
	}
	else
	{
		if ((game->raycast.raydir_x <= 0 && game->raycast.raydir_y <= 0)
			|| (game->raycast.raydir_x <= 0 && game->raycast.raydir_y >= 0))
			return (&game->array_texture[3]);
		else
			return (&game->array_texture[1]);
	}
	return (NULL);
}
