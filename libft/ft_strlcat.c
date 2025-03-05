/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:12:07 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/19 18:33:29 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	result;
	size_t	dstlen;

	i = 0;
	k = 0;
	result = 0;
	if (size == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	if (size < dstlen)
		result = ft_strlen(src) + size;
	else
		result = ft_strlen(src) + dstlen;
	while (dst[i])
		i++;
	while (src[k] && size != 0 && i < size - 1)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (result);
}

// int	main(void)
// {
// 	char	*d1 = "hello";
// 	int		n1;
// 	char	*d2 = "hello";
// 	int		n2;

// 	n1 = strlcat(d1, NULL, 3);
// 	printf("Length: %d\n", n1);
// 	//printf("%li", ft_strlcat(d2, NULL, 3));
// }