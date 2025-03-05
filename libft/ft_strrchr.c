/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:08:32 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/14 19:05:29 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (c == '\0')
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*str = "hello nina";
	char		ch;
	char		*found;
	const char	*str1 = "hello nina";
	char		ch1;
	char		*found1;

	ch = 'u';
	found = strrchr(str, ch);
	printf("%s\n", found);
	ch1 = 'u';
	found1 = ft_strrchr(str1, ch1);
	printf("%s\n", found1);
}
*/
