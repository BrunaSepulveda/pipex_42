/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsepulve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:54:30 by bsepulve          #+#    #+#             */
/*   Updated: 2025/10/20 18:54:53 by bsepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substring;

	s_len = ft_strlen(s);
	if ((size_t)start >= s_len || len == 0)
	{
		return (ft_strdup(""));
	}
	if (start + len > s_len)
	{
		len = s_len - start;
	}
	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
	{
		return (NULL);
	}
	ft_strlcpy(substring, &s[start], len + 1);
	return (substring);
}
