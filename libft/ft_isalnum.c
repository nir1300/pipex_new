/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:08:08 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/03 17:08:09 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	if ((a >= 48 && a <= 57) || (a >= 'A' && a <= 'Z') || (a >= 'a'
			&& a <= 'z'))
		return (8);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("isalnum: %i\n", isalnum('a'));
	printf("isalnum: %i\n", isalnum('1'));
	printf("isalnum: %i\n", isalnum('!'));
	printf("ft: %i\n", isalnum('a'));
	printf("ft: %i\n", isalnum('1'));
	printf("ft: %i\n", isalnum('!'));
}
*/
