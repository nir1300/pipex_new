/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:20:43 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/11/14 12:25:17 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	convert_ptr_hex(unsigned long dec_a)
{
	if (dec_a >= 16)
	{
		convert_ptr_hex(dec_a / 16);
		convert_ptr_hex(dec_a % 16);
	}
	else
	{
		if (dec_a < 10)
			ft_putchar(dec_a + 48);
		else
			ft_putchar(dec_a - 10 + 'a');
	}
}

int	convert_ptr(void *dec)
{
	unsigned long	dec_a;
	int				res;

	dec_a = (unsigned long)dec;
	if (dec == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	res = ft_putstr("0x");
	convert_ptr_hex(dec_a);
	while (dec_a != 0)
	{
		dec_a /= 16;
		res++;
	}
	return (res);
}
