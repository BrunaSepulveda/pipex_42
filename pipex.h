/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsepulve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:48:44 by bsepulve          #+#    #+#             */
/*   Updated: 2025/10/22 19:48:46 by bsepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_fds
{
	int	infile;
	int	outfile;
}	t_fds;

typedef struct s_cmd
{
	char	*path;
	char	**argv;
}	t_cmd;

int		pipex(t_fds fds, t_cmd *cmds, char **envp);
int		init_cmd(t_cmd *cmd, char *input, char **envp);
char	**split_args(const char *input);
int		open_infile(const char *file);
int		open_outfile(const char *file);
char	**split_paths(char *const *envp);
char	*resolve_command_path(char *cmd, char *const *envp);
void	free_split(char **split);
void	free_cmds(t_cmd *cmds, int count);
void	*free_partial_argv(char **argv, int count);
char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3);
char	**build_exec_argv(t_cmd *cmd);

#endif
