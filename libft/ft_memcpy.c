/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsepulve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:50:19 by bsepulve          #+#    #+#             */
/*   Updated: 2025/10/20 18:50:22 by bsepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char		*dest_copy;
	const unsigned char	*src_copy;
	size_t				index;

	if ((!dest && !src) || count == 0)
	{
		return (dest);
	}
	dest_copy = (unsigned char *)dest;
	src_copy = (const unsigned char *)src;
	index = 0;
	while (count)
	{
		dest_copy[index] = src_copy[index];
		index ++;
		count --;
	}
	return (dest);
}
