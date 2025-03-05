/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:21:30 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/09 23:21:32 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			write(fd, "2", 1);
			n = -147483648;
		}
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + '0', fd);
}

/*
#include <unistd.h>

int	main(void)
{
	int	n;
	int	nd;

	n = -2147483648;
	nd = 1;
	ft_putnbr_fd(n, nd);
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
*/
