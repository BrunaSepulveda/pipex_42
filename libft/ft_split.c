/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsepulve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:54:15 by bsepulve          #+#    #+#             */
/*   Updated: 2025/10/20 18:54:17 by bsepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	count;
	int	index;
	int	in_word;

	index = 0;
	count = 0;
	in_word = 0;
	while (s[index])
	{
		if (s[index] != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (s[index] == c)
			in_word = 0;
		index++;
	}
	return (count);
}

static void	free_split(char **array, int size)
{
	while (size--)
		free(array[size]);
	free(array);
}

static int	ft_fill_array(char const *s, char c, char **array)
{
	int	i;
	int	i_arr;
	int	start;

	i = 0;
	i_arr = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		array[i_arr] = ft_substr(s, start, i - start);
		if (!array[i_arr])
		{
			free_split(array, i_arr);
			return (0);
		}
		i_arr++;
	}
	array[i_arr] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**array;

	count = 0;
	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	if (count == 0)
	{
		array = malloc(sizeof(char *) * 1);
		if (!array)
			return (NULL);
		array[0] = NULL;
		return (array);
	}
	if (!count)
		return (NULL);
	array = malloc((count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	if (!ft_fill_array(s, c, array))
		return (NULL);
	return (array);
}
