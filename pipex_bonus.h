/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:44:56 by nrumpfhu          #+#    #+#             */
/*   Updated: 2025/01/31 18:14:19 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include "sys/types.h"
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipe
{
	char	**args;
	char	*path;
	int		wstatus;
	int		cmdcount;
	int		*pipe_fd;
	int		input_fd;
	int		output_fd;
	pid_t	pid[];
}			t_pipe;

typedef struct s_fds
{
	int		input_fd;
	int		output_fd;
}			t_fds;

void		ft_freedata(char **arr);
void		create_cmd(t_pipe *data, char *argv[], int i);
void		free_struct(t_pipe *data, int exitnum);
void		initialise(int argc, char *argv[], t_pipe *data);
void		first_child(t_pipe *data, char *argv[], char *envp[]);
void		middle_child(t_pipe *data, char *argv[], int i, char *envp[]);
void		ft_close(t_pipe *data);
void		ft_wait(t_pipe *data);

#endif
