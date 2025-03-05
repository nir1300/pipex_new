/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:44:56 by nrumpfhu          #+#    #+#             */
/*   Updated: 2025/02/01 16:19:10 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "sys/types.h"
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipe
{
	char	*cmd1;
	char	*cmd2;
	char	**args1;
	char	**args2;
	char	*path1;
	char	*path2;
	pid_t	pid1;
	pid_t	pid2;
	int		wstatus;
	int		fd1;
	int		fd2;
	int		fd[2];
}			t_pipe;

void		ft_freedata(char **arr);
void		free_struct(t_pipe *data, int exitnum);
void		set_args(int argc, char *argv[], t_pipe *data);
void		initialise(t_pipe *data, int argc);
void		first_child(t_pipe *data, char *envp[]);
void		second_child(t_pipe *data, char *envp[]);
void		ft_close(t_pipe *data);
void		ft_wait(t_pipe *data);

#endif
