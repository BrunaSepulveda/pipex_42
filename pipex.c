/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsepulve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:47:54 by bsepulve          #+#    #+#             */
/*   Updated: 2025/10/22 19:47:57 by bsepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_cmd1(t_fds fds, int pipefd[2], t_cmd *cmd, char **envp)
{
	char	**exec_args;

	close(pipefd[0]);
	dup2(fds.infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(fds.infile);
	close(pipefd[1]);
	exec_args = build_exec_argv(&cmd[0]);
	execve(cmd[0].path, exec_args, envp);
	perror("Erro ao executar cmd1");
	free_split(exec_args);
	exit(EXIT_FAILURE);
}

void	handle_cmd2(t_fds fds, int pipefd[2], t_cmd *cmd, char **envp)
{
	char	**exec_args;

	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fds.outfile, STDOUT_FILENO);
	close(pipefd[0]);
	close(fds.outfile);
	exec_args = build_exec_argv(&cmd[1]);
	execve(cmd[1].path, exec_args, envp);
	perror("Erro ao executar cmd2");
	free_split(exec_args);
	exit(EXIT_FAILURE);
}

int	pipex(t_fds fds, t_cmd *cmd, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipefd) == -1)
		return (perror("pipe"), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("fork"), 1);
	if (pid1 == 0)
		handle_cmd1(fds, pipefd, cmd, envp);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("fork"), 1);
	if (pid2 == 0)
		handle_cmd2(fds, pipefd, cmd, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
