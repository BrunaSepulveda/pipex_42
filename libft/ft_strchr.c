/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsepulve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:55:19 by bsepulve          #+#    #+#             */
/*   Updated: 2025/10/20 18:55:22 by bsepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int arg)
{
	unsigned char		arg_copy;
	size_t				index;

	arg_copy = (unsigned char)(arg);
	index = 0;
	while (str[index] != '\0')
	{
		if ((unsigned char)(str[index]) == arg_copy)
		{
			return ((char *)&str[index]);
		}
		index ++;
	}
	if (arg_copy == '\0')
	{
		return ((char *)&str[index]);
	}
	return (NULL);
}
