/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:32:10 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/05 21:06:22 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		n;
	char	*new;

	n = 0;
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	if (new != NULL)
	{
		while (s1[n])
			new[i++] = s1[n++];
		n = 0;
		while (s2[n])
			new[i++] = s2[n++];
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	puts(ft_strjoin("", "there"));
}
*/