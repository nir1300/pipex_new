/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:01:48 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/11/14 12:25:17 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countnum_uns(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	else
	{
		while (n > 0)
		{
			count++;
			n /= 10;
		}
	}
	return (count);
}

int	ft_putnbr_uns(unsigned int n)
{
	int	res;

	if ((int)n < 0)
		n = 4294967295 + (int)n + 1;
	res = ft_countnum_uns(n);
	if (n > 9)
	{
		ft_putnbr_uns(n / 10);
		n = n % 10;
	}
	if (n <= 9)
	{
		ft_putchar(n + '0');
	}
	return (res);
}

int	ft_countnum(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	else if (n == 0)
		count++;
	if (n > 0)
	{
		while (n > 0)
		{
			count++;
			n /= 10;
		}
	}
	return (count);
}

int	ft_putnbr(int n, const char format)
{
	int	res;

	res = ft_countnum(n);
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			write(1, "2", 1);
			n = -147483648;
			res = 11;
		}
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, format);
		n = n % 10;
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	return (res);
}
