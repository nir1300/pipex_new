/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:01:45 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/11/14 12:25:17 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	puthex(unsigned int dec)
{
	int	count;

	count = 0;
	if (dec == 0)
		count++;
	while (dec != 0)
	{
		dec /= 16;
		count++;
	}
	return (count);
}

int	convert_dec_hex(unsigned int dec, const char format)
{
	unsigned int	temp;

	temp = dec;
	if (dec >= 16)
	{
		convert_dec_hex(dec / 16, format);
		convert_dec_hex(dec % 16, format);
	}
	else
	{
		if (dec < 10)
			ft_putchar(dec + 48);
		else if (format == 'x')
			ft_putchar(dec - 10 + 'a');
		else if (format == 'X')
			ft_putchar(dec - 10 + 'A');
	}
	return (puthex(temp));
}
