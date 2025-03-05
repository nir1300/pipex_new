/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:07:43 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/03 17:07:44 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tempdest;
	const unsigned char	*tempsrc = (unsigned char *)src;

	i = 0;
	tempdest = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (tempdest > tempsrc)
	{
		while (++i <= n)
			((unsigned char *)tempdest)[n - i] = ((unsigned char *)tempsrc)[n
				- i];
	}
	else
	{
		i = 0;
		while (n-- > 0)
		{
			tempdest[i] = tempsrc[i];
			i++;
		}
	}
	return (dest);
}

/*
// create temporary variable !!
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	d1[] = "123456789";
	char	s1[] = "123456789";
	char	d2[] = "123456789";
	char	s2[] = "123456789";
	char	d3[14] = "hellloooo";
	char	s3[] = "yoo";
	char	d4[14] = "hellloooo";
	char	s4[] = "yoo";
	char	d5[14] = "hellloooo";
	char	s5[] = "hi";
	char	d6[14] = "hellloooo";
	char	s6[] = "hi";
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;
	char	src1[] = "lorem ipsum dolor sit amet";
	char	*dest1;

	puts(memmove(d1+3, s1, 3));
	puts(ft_memmove(d2+3, s2, 3));
	puts(memmove(d3, s3, 4));
	puts(ft_memmove(d4, s4, 4));
	puts(memmove(d5, s5, 4));
	puts(ft_memmove(d6, s6, 4));
	dest = src + 1;
	dest1 = src1 + 1;
	puts(memmove(dest, src, 8));
	puts(ft_memmove(dest1, src1, 8));
	puts(src);
	puts(src1);
}
*/