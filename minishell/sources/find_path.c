/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaiouf <mmaiouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:10:48 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/24 20:04:49 by mmaiouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*check_path(char *command, int i, t_envp *s_envp)
{
	char	**array;
	char	*path;
	char	*cur_path;
	char	*temp;
	char	*join;

	array = ft_split(getenv("PATH"), ':');
	if (path_exists(s_envp))
	{
		while (array[++i])
		{
			temp = ft_strdup(array[i]);
			join = ft_strjoin(temp, "/");
			path = ft_strjoin(join, command);
			free(temp);
			if (access(path, F_OK) == 0)
			{
				cur_path = ft_strdup(path);
				return (free(path), free(join), ft_free_str(array), cur_path);
			}
			free(join);
			free(path);
		}
	}
	return (ft_free_str(array), NULL);
}

char	*find_path(char *command, t_envp *s_envp)
{
	char	*path;

	path = NULL;
	if (access(command, F_OK) == 0)
		return (command);
	path = check_path(command, -1, s_envp);
	if (path != NULL)
		return (path);
	return (NULL);
}
