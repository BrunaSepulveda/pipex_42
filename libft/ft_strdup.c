/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsepulve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:52:32 by bsepulve          #+#    #+#             */
/*   Updated: 2025/10/20 18:52:34 by bsepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_initstr(const char *str, size_t size)
{
	char	*str_copy;

	if (!str)
		return (NULL);
	str_copy = malloc((size + 1) * sizeof(char));
	if (!str_copy)
		return (NULL);
	ft_strlcpy(str_copy, str, size + 1);
	return (str_copy);
}

char	*ft_strdup(const char *str)
{
	return (ft_initstr(str, ft_strlen(str)));
}
