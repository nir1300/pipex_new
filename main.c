/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:37:05 by nrumpfhu          #+#    #+#             */
/*   Updated: 2025/02/01 16:51:46 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_args(int argc, char *argv[], t_pipe *data)
{
	initialise(data, argc);
	data->args1 = ft_split(argv[2], ' ');
	data->args2 = ft_split(argv[3], ' ');
	if (!data->args1 || !data->args2 || data->args1[0] == NULL
		|| data->args2[0] == NULL)
		free_struct(data, 1);
	data->fd1 = open(argv[1], O_RDONLY);
	if (data->fd1 < 0)
		perror(argv[1]);
	data->fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd2 < 0)
	{
		close(data->fd1);
		perror(argv[argc - 1]);
		free_struct(data, 1);
	}
	data->path1 = ft_strjoin("/bin/", data->args1[0]);
	data->path2 = ft_strjoin("/bin/", data->args2[0]);
	if (!data->fd2 || !data->path1 || !data->path2)
		free_struct(data, errno);
	if (access(data->path1, R_OK | X_OK) == -1)
		perror(data->args1[0]);
	if (access(data->path2, R_OK | X_OK) == -1)
		perror(data->args2[0]);
}

void	first_child(t_pipe *data, char *envp[])
{
	data->pid1 = fork();
	if (data->pid1 == 0)
	{
		close(data->fd[0]);
		if (dup2(data->fd1, STDIN_FILENO) == -1)
			free_struct(data, 1);
		if (dup2(data->fd[1], STDOUT_FILENO) == -1)
			free_struct(data, 1);
		ft_close(data);
		execve(data->path1, data->args1, envp);
		free_struct(data, 127);
	}
}

void	second_child(t_pipe *data, char *envp[])
{
	data->pid2 = fork();
	if (data->pid2 == 0)
	{
		close(data->fd[1]);
		if (dup2(data->fd[0], STDIN_FILENO) == -1)
			free_struct(data, 1);
		if (dup2(data->fd2, STDOUT_FILENO) == -1)
			free_struct(data, 1);
		ft_close(data);
		execve(data->path2, data->args2, envp);
		free_struct(data, 127);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	*data;

	data = malloc(sizeof(t_pipe));
	if (!data)
		exit(1);
	set_args(argc, argv, data);
	if (pipe(data->fd) == -1)
		free_struct(data, 1);
	first_child(data, envp);
	second_child(data, envp);
	ft_close(data);
	ft_wait(data);
}
