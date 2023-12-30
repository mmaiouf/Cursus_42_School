/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaiouf <mmaiouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:18:33 by mou3              #+#    #+#             */
/*   Updated: 2023/12/24 20:08:54 by mmaiouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_word(char const *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] && (str[i] != ' ' && str[i] != '\t'))
			count++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i++;
	}
	return (count);
}

static int	ft_len_new_str(char *str)
{
	int	i;
	int	nb_word;
	int	len;

	i = 0;
	nb_word = ft_nb_word(str);
	len = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			len++;
		i++;
	}
	return (len + nb_word);
}

static void	ft_epur_str_exec(char *new, char *mystr, int i, int j)
{
	while (mystr[i] != '\0' && (mystr[i] == ' ' || mystr[i] == '\t'))
		i++;
	while (mystr[i] != '\0')
	{
		if (mystr[i] == ' ' || mystr[i] == '\t')
		{
			while (mystr[i] != '\0' && (mystr[i] == ' ' || mystr[i] == '\t'))
				i++;
			if (mystr[i] == '\0')
				break ;
			new[j] = ' ';
			j++;
		}
		else
		{
			new[j] = mystr[i];
			j++;
			i++;
		}
	}
	new[j] = '\0';
}

char	*ft_epur_str(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * (ft_len_new_str(str) + 1));
	if (new_str == NULL)
		return (NULL);
	ft_epur_str_exec(new_str, str, i, j);
	return (new_str);
}
