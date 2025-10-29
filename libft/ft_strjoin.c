/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsepulve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:52:13 by bsepulve          #+#    #+#             */
/*   Updated: 2025/10/20 18:52:15 by bsepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s_len;
	size_t	s1_len;
	size_t	s2_len;
	char	*join_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s_len = s1_len + s2_len;
	if (s_len == 0)
	{
		join_str = malloc(1);
		if (!join_str)
			return (NULL);
		join_str[0] = '\0';
		return (join_str);
	}
	join_str = malloc((s_len + 1) * sizeof(char));
	if (!join_str)
		return (NULL);
	ft_memcpy(join_str, s1, s1_len);
	ft_strlcpy(&join_str[s1_len], s2, s2_len + 1);
	return (join_str);
}
