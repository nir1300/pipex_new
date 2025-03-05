/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:31:47 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/10 22:49:34 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_assignsub(char *substr, size_t i)
{
	if (substr == NULL)
		return (NULL);
	substr[i] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;
	size_t	slen;
	size_t	maxlen;

	slen = ft_strlen(s);
	maxlen = slen - start;
	if (len < (slen - start))
		maxlen = len;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= slen)
		substr = (char *)malloc(1);
	else
	{
		substr = (char *)malloc(maxlen + 1);
		while (i < len && (start + i) < (unsigned int)slen && substr != NULL)
		{
			substr[i] = s[start + i];
			i++;
		}
	}
	return (ft_assignsub(substr, i));
}

/*
#include <stdio.h>
#include <stdlib.h>


int	main(void)
{
	char	*s;
	char	*res;

	s = "hello";
	res = ft_substr(s, 2, 1000);
	puts(res);
	free(res);
}
*/