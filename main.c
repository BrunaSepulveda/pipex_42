/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsepulve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:48:17 by bsepulve          #+#    #+#             */
/*   Updated: 2025/10/22 19:48:27 by bsepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_fds	fds;
	t_cmd	*cmds;
	int		i;

	if (argc != 5)
		return (1);
	fds.infile = open_infile(argv[1]);
	fds.outfile = open_outfile(argv[4]);
	if (fds.infile < 0 || fds.outfile < 0)
		return (1);
	cmds = malloc(sizeof(t_cmd) * 2);
	if (!cmds)
		return (1);
	i = 0;
	while (i < 2)
	{
		if (init_cmd(&cmds[i], argv[i + 2], envp))
			return (free_cmds(cmds, i), 1);
		i++;
	}
	if (pipex(fds, cmds, envp))
		return (free_cmds(cmds, 2), 1);
	free_cmds(cmds, 2);
	return (0);
}
