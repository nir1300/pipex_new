/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:20:04 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/11/25 20:53:23 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*arr;

	i = 0;
	arr = NULL;
	if (s != NULL)
		arr = malloc(ft_strlen(s) + 1);
	if (arr != NULL)
	{
		while (s[i])
		{
			arr[i] = f(i, s[i]);
			i++;
		}
		arr[i] = '\0';
		return (arr);
	}
	return (NULL);
}

/*
#include <stdio.h>

static char	ft_tryfunction(unsigned int n, char c)
{
	printf("%c%i", c, n);
	return (c - 32);
}

int	main(void)
{
	const char	*s = "hallo";

	printf("%s", ft_strmapi(s, ft_tryfunction));
}
*/
