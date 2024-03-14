/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaizkor <ceaizkor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:54:06 by ceaizkor          #+#    #+#             */
/*   Updated: 2024/03/14 16:54:06 by ceaizkor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int file1, char **commands, int file2, char *envp[])
{
	int		pipes[2];
	int		res;
	int		status;
	pid_t	child;

	res = 0;
	pipe (pipes);
	child = fork();
	if (child == -1)
		ft_error("ERROR the creation of child was unsuccessful\n", 1);
	if (child == 0)
	{
		close(pipes[1]);
		ft_child(file2, commands[1], pipes, envp);
	}
	else
	{
		close (pipes[0]);
		ft_father (file1, commands[0], pipes, envp);
	}
	while (wait(&status) > 0)
		res = ft_exit (status);
	return (res);
}

int	ft_father(int file1, char *commands, int *pipes, char *envp[])
{
	char	**c;
	char	*path;

	dup2(file1, STDIN_FILENO);
	dup2(pipes[1], STDOUT_FILENO);
	close(pipes[0]);
	c = ft_split(commands, ' ');
	path = ft_get_path(c[0], envp);
	if (execve(path, c, envp) == -1)
	{
		ft_error("Error execve\n", 1);
		exit(1);
	}
	return (0);
}

int	ft_child(int file2, char *commands, int *pipes, char *envp[])
{
	char	**c;
	char	*path;

	dup2 (pipes[0], STDIN_FILENO);
	dup2 (file2, STDOUT_FILENO);
	close(pipes[1]);
	c = ft_split(commands, ' ');
	path = ft_get_path(c[0], envp);
	if (execve(path, c, envp) == -1)
	{
		ft_error("Error execve\n", 1);
		exit(1);
	}
	return (0);
}
