/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_handle_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsepulve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:47:00 by bsepulve          #+#    #+#             */
/*   Updated: 2025/10/22 19:47:02 by bsepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_paths(char *const *envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*resolve_command_path(char *cmd, char *const *envp)
{
	char	**paths;
	char	*test_path;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	paths = split_paths(envp);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		test_path = ft_strjoin_three(paths[i], "/", cmd);
		if (access(test_path, X_OK) == 0)
		{
			free_split(paths);
			return (test_path);
		}
		free(test_path);
		i++;
	}
	free_split(paths);
	return (NULL);
}
