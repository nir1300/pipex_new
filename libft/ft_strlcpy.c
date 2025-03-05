/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:07:24 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/11 21:00:00 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*

#include <bsd/string.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		n1;
	int		n2;
	char	d1[3] = "h";
	char	d2[] = "hello";

	n1 = ft_strlcpy(d1, "fiii", 5);
	puts(d1);
	n2 = strlcpy("hello", "f", 7);
	puts(d2);
}
*/