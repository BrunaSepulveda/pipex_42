/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsepulve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:47:22 by bsepulve          #+#    #+#             */
/*   Updated: 2025/10/22 19:47:24 by bsepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_cmds(t_cmd *cmds, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free_split(cmds[i].argv);
		free(cmds[i].path);
		i++;
	}
	free(cmds);
}

void	*free_partial_argv(char **argv, int count)
{
	while (count--)
		free(argv[count]);
	free(argv);
	return (NULL);
}
