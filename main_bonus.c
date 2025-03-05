/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:37:05 by nrumpfhu          #+#    #+#             */
/*   Updated: 2025/02/01 17:16:38 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	initialise(int argc, char *argv[], t_pipe *data)
{
	data->args = NULL;
	data->path = NULL;
	data->path = NULL;
	data->pipe_fd = NULL;
	if (argc < 5)
		free_struct(data, errno);
	data->input_fd = open(argv[1], O_RDONLY);
	if (data->input_fd < 0)
		perror(argv[1]);
	data->output_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->output_fd < 0)
	{
		perror(argv[argc - 1]);
		close(data->input_fd);
		free_struct(data, 1);
	}
	data->cmdcount = argc - 3;
}

void	create_cmd(t_pipe *data, char *argv[], int i)
{
	if (data->args)
		ft_freedata(data->args);
	if (data->path)
	{
		free(data->path);
		data->path = NULL;
	}
	data->args = ft_split(argv[i + 2], ' ');
	if (!data->args || data->args[0] == NULL)
		free_struct(data, errno);
	data->path = ft_strjoin("/bin/", data->args[0]);
	if (!data->path)
		free_struct(data, errno);
	if (access(data->path, R_OK | X_OK) == -1)
		perror(data->args[0]);
}

void	first_child(t_pipe *data, char *argv[], char *envp[])
{
	create_cmd(data, argv, 0);
	data->pid[0] = fork();
	if (data->pid[0] == 0)
	{
		if (dup2(data->input_fd, STDIN_FILENO) == -1)
			free_struct(data, errno);
		if (dup2(data->pipe_fd[1], STDOUT_FILENO) == -1)
			free_struct(data, errno);
		ft_close(data);
		execve(data->path, data->args, envp);
		strerror(errno);
		free_struct(data, 127);
	}
}

void	middle_child(t_pipe *data, char *argv[], int i, char *envp[])
{
	create_cmd(data, argv, i);
	data->pid[i] = fork();
	if (data->pid[i] == 0)
	{
		if (dup2(data->pipe_fd[(i - 1) * 2], STDIN_FILENO) == -1)
			free_struct(data, errno);
		if (i == data->cmdcount - 1)
		{
			if (dup2(data->output_fd, STDOUT_FILENO) == -1)
				free_struct(data, errno);
		}
		else
		{
			if (dup2(data->pipe_fd[(i * 2) + 1], STDOUT_FILENO) == -1)
				free_struct(data, errno);
		}
		ft_close(data);
		execve(data->path, data->args, envp);
		free_struct(data, 127);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	*data;
	int		i;

	if (argc < 5)
		exit(errno);
	data = malloc(sizeof(t_pipe) + (sizeof(pid_t) * (argc - 3)));
	if (!data)
		exit(errno);
	initialise(argc, argv, data);
	data->pipe_fd = malloc(sizeof(int) * (data->cmdcount - 1) * 2);
	if (!data->pipe_fd)
		free_struct(data, errno);
	i = 0;
	while (i < (data->cmdcount - 1))
	{
		if (pipe(&data->pipe_fd[i++ *2]) == -1)
			free_struct(data, errno);
	}
	first_child(data, argv, envp);
	i = 1;
	while (i < data->cmdcount)
		middle_child(data, argv, i++, envp);
	ft_close(data);
	ft_wait(data);
}
