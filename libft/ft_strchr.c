/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:54:42 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/19 17:43:17 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char s[] = "tripoulline";
// 	printf("%s", ft_strchr(s, '\0'));
// 	char *try = strchr(((void*)0), '\0');
// 	char *try1 = ft_strchr(((void*)0), '\0');

// 	const char	*str = "hello nina";
// 	char		ch;
// 	char		*found;
// 	const char	*str1 = "hello nina";
// 	char		ch1;
// 	char		*found1;

// 	ch = '\0';
// 	found = strchr(str, ch);
// 	printf("%s\n", found);
// 	ch1 = '\0';
// 	found1 = ft_strchr(str1, ch1);
// 	printf("%s\n", found1);
// }