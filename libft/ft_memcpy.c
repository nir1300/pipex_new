/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:07:50 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/03 17:07:51 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

// if dest not big enough, it overflows in standard function (not in mine)

int	main(void)
{

	char	dest[] = "helloooooooo";
	char	src[] = "world";
	char	dest1[] = "heloooooooo";
	char	src1[] = "world";

	memcpy(dest, src, 7);
	puts(dest);
	ft_memcpy(dest1, src1, 7);
	puts(dest1);


	char	src2[] = "world";
	char	*dest2 = src2+2;

	char	src3[] = "world";
	char	*dest3 = src3+2;

	memcpy(src2+2, src2, 7);
	puts(dest2);
	ft_memcpy(src3+2, src3, 7);
	puts(dest3);
} */