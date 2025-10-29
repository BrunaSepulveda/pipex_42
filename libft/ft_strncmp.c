/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsepulve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:51:52 by bsepulve          #+#    #+#             */
/*   Updated: 2025/10/20 18:51:55 by bsepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_diff_unsigned_char(unsigned char char1, unsigned char char2)
{
	return (char1 - char2);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			index;
	unsigned char	c1;
	unsigned char	c2;

	index = 0;
	while (index < n)
	{
		c1 = (unsigned char)(str1[index]);
		c2 = (unsigned char)(str2[index]);
		if (c1 != c2)
		{
			return (ft_diff_unsigned_char(c1, c2));
		}
		if (c1 == '\0')
		{
			break ;
		}
		index++;
	}
	return (0);
}
