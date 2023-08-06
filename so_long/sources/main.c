/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:41:18 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/08/02 15:17:39 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	check_is_ber(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	i = i - 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b'
		&& argv [i - 3] == '.')
		return (1);
	ft_putendl_fd(IS_NOT_BER, 2);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments.", 2);
		exit(EXIT_FAILURE);
	}
	game.map = read_map(argv[1]);
	if (game.map == NULL)
		exit(EXIT_FAILURE);
	if (check_is_ber(argv[1]) && check_is_map(&game) 
		&& check_is_solvable(argv[1]))
	{
		if (game_load(&game) == -1)
			exit (EXIT_FAILURE);
		game_update(&game);
		mlx_loop(game.mlx);
	}
	else
	{
		if (game.map != NULL)
			free_map(game.map);
		exit(EXIT_FAILURE);
	}
	return (0);
}
