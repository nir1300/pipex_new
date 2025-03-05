/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:00:25 by nrumpfhu          #+#    #+#             */
/*   Updated: 2025/01/31 18:14:11 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_freedata(char **arr)
{
	int	a;

	a = 0;
	if (!arr)
		return ;
	while (arr[a])
		a++;
	while (a >= 0)
	{
		free(arr[a]);
		a--;
	}
	free(arr);
	arr = NULL;
}

void	free_struct(t_pipe *data, int exitnum)
{
	if (data->pipe_fd)
		free(data->pipe_fd);
	if (data->args)
		ft_freedata(data->args);
	data->args = NULL;
	if (data->path != NULL)
		free(data->path);
	data->path = NULL;
	free(data);
	exit(exitnum);
}

void	ft_close(t_pipe *data)
{
	int	i;

	close(data->input_fd);
	close(data->output_fd);
	i = 0;
	while (i < (data->cmdcount - 1) * 2)
	{
		close(data->pipe_fd[i]);
		i++;
	}
}

void	ft_wait(t_pipe *data)
{
	int	i;

	i = 0;
	while (i < (data->cmdcount))
	{
		if (waitpid(data->pid[i], &data->wstatus, 0) == -1)
			exit(WEXITSTATUS(data->wstatus));
		i++;
	}
	free_struct(data, WEXITSTATUS(data->wstatus));
}
