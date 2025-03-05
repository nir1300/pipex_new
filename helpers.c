/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:00:25 by nrumpfhu          #+#    #+#             */
/*   Updated: 2025/02/01 17:18:10 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialise(t_pipe *data, int argc)
{
	data->args1 = NULL;
	data->args2 = NULL;
	data->path1 = NULL;
	data->path2 = NULL;
	if (argc != 5)
		free_struct(data, errno);
}

void	ft_freedata(char **arr)
{
	int	a;

	a = 0;
	while (arr[a])
		a++;
	while (a >= 0)
	{
		free(arr[a]);
		a--;
	}
	free(arr);
}

void	free_struct(t_pipe *data, int exitnum)
{
	if (data->args1)
		ft_freedata(data->args1);
	if (data->args2)
		ft_freedata(data->args2);
	if (data->path1)
		free(data->path1);
	if (data->path2)
		free(data->path2);
	free(data);
	exit(exitnum);
}

void	ft_close(t_pipe *data)
{
	close(data->fd[0]);
	close(data->fd[1]);
	close(data->fd1);
	close(data->fd2);
}

void	ft_wait(t_pipe *data)
{
	waitpid(data->pid1, &data->wstatus, 0);
	waitpid(data->pid2, &data->wstatus, 0);
	free_struct(data, WEXITSTATUS(data->wstatus));
}
