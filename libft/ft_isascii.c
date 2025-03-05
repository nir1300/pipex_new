/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:07:59 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/03 17:08:00 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
		return (1);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("correct: %i\n", isascii(128));
	printf("correct: %i\n", isascii(0));
	printf("correct: %i\n", isascii(300));
	printf("correct: %i\n", isascii(127));
	printf("correct: %i\n", isascii(48));
	printf("mine: %i\n", ft_isascii(128));
	printf("mine: %i\n", ft_isascii(0));
	printf("mine: %i\n", ft_isascii(300));
	printf("mine: %i\n", ft_isascii(127));
	printf("mine: %i\n", ft_isascii(48));
}
*/
