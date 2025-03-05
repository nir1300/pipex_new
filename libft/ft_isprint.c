/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:07:53 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/03 17:07:54 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int a)
{
	if (a >= 32 && a <= 126)
		return (16384);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("correct: %i\n", isprint(48));
	printf("correct: %i\n", isprint(31));
	printf("correct: %i\n", isprint(32));
	printf("correct: %i\n", isprint(126));
	printf("correct: %i\n", isprint(127));
	printf("mine: %i\n", ft_isprint(48));
	printf("mine: %i\n", ft_isprint(31));
	printf("mine: %i\n", ft_isprint(32));
	printf("mine: %i\n", ft_isprint(126));
	printf("mine: %i\n", ft_isprint(127));
}
*/
