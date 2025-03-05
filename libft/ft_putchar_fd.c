/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:41:58 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/09 23:21:16 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

	fd = open("hallo1.txt", O_WRONLY);
	if (fd < 0)
		write(0, "a", 1);
	ft_putchar_fd('c', fd);
}
*/
