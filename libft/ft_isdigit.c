/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:07:55 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/03 17:07:56 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (2048);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("ft_isdigit: %i\n", ft_isdigit('?'));
	printf("isdigit: %i\n", isdigit('?'));
	printf("ft_isdigit: %i\n", ft_isdigit('2'));
	printf("isdigit: %i", isdigit('2'));
}
*/
