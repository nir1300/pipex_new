/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:24:09 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/11 00:39:04 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	lillen;

	i = 0;
	k = 0;
	lillen = ft_strlen(lil);
	if (big == lil || lillen == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		k = 0;
		while (big[i + k] && lil[k] && i + k < len && big[i + k] == lil[k])
			k++;
		if (k == lillen)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/* 
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	b[] = "Hello";
	char	s[] = "e";
	char	b1[] = "Hello";
	char	s1[] = "e";

	printf("%s\n", ft_strnstr(b, s, 0));
	printf("%s\n", strnstr(b1, s1, 0));
} */