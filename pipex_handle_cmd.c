/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_handle_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsepulve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:46:47 by bsepulve          #+#    #+#             */
/*   Updated: 2025/10/22 19:46:49 by bsepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_args(const char *input)
{
	char	**args;

	if (!input)
		return (NULL);
	args = ft_split(input, ' ');
	if (!args)
		return (NULL);
	return (args);
}

int	init_cmd(t_cmd *cmd, char *input, char **envp)
{
	char	**split;

	split = split_args(input);
	if (!split || !split[0])
	{
		free_split(split);
		return (1);
	}
	cmd->path = resolve_command_path(split[0], envp);
	if (!cmd->path)
	{
		perror("Comando não encontrado");
		free_split(split);
		return (1);
	}
	cmd->argv = split;
	return (0);
}
