/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsepulve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:47:33 by bsepulve          #+#    #+#             */
/*   Updated: 2025/10/22 19:47:35 by bsepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3)
{
	char	*tmp;
	char	*result;

	if (!s1 || !s2 || !s3)
		return (NULL);
	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		return (NULL);
	result = ft_strjoin(tmp, s3);
	free(tmp);
	return (result);
}

char	**build_exec_argv(t_cmd *cmd)
{
	int		i;
	char	**exec_args;

	i = 0;
	while (cmd->argv && cmd->argv[i])
		i++;
	exec_args = (char **)malloc(sizeof(char *) * (i + 1));
	if (!exec_args)
		return (NULL);
	i = 0;
	while (cmd->argv && cmd->argv[i])
	{
		exec_args[i] = ft_strdup(cmd->argv[i]);
		if (!exec_args[i])
			return (free_partial_argv(exec_args, i));
		i++;
	}
	exec_args[i] = NULL;
	return (exec_args);
}
