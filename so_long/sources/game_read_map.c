/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_read_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:24:52 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/08/03 00:45:39 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	**read_map(char *file_map)
{
	int		fd;
	char	*line;
	char	*buffer;
	char	*temp;
	char	**map;

	fd = open(file_map, O_RDONLY);
	buffer = ft_strdup("");
	if (fd == -1 || buffer == NULL)
		return (free(buffer), NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = buffer;
		buffer = ft_strjoin(temp, line);
		free(line);
		free(temp);
	}
	map = ft_split(buffer, '\n');
	free(buffer);
	close(fd);
	return (map);
}
