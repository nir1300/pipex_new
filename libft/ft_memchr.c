/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:14:51 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/04 13:14:55 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == ((unsigned char)c))
			return (((void *)s) + i);
		i++;
	}
	return (NULL);
}

/* 
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	char *ret = memchr(s, 0, 1);
	printf("%s\n", ret);

	//char s1[] = {0, 1, 2 ,3 ,4 ,5};
	//char *ret1 = ft_memchr(s1, 0, 1);
	//printf("%s\n", ret1);

	char s[] = "heBlo";
	char *ret = memchr(s, 'B', 3);
	printf("%s\n", ret);

	char s1[] = "heBlo";
	char *ret1 = ft_memchr(s1, 'B', 3);
	printf("%s\n", ret1);
}
 */
