/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:06:42 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/19 18:32:59 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s11;
	const unsigned char	*s22;

	i = 0;
	s11 = (const unsigned char *)s1;
	s22 = (const unsigned char *)s2;
	while (i < n)
	{
		if (s11[i] != s22[i])
			return (s11[i] - s22[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "ABd";
	char	s2[] = "ABd";
	char	s3[] = "ABd";
	char	s4[] = "ABd";

	printf("%i\n", memcmp(s1, s2, 30));
	printf("%i\n", ft_memcmp(s3, s4, 30));
}
*/