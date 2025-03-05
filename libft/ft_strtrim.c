/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:50:58 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/11/14 12:15:22 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cpyrange(char const *s1, int start, int end)
{
	char	*new;
	int		i;

	new = (char *)malloc(end - start + 2);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (start <= end && s1[start])
	{
		new[i] = s1[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}

static char	*ft_trimend(char const *s1, char const *set, int start, int end)
{
	int	k;

	k = 0;
	while (end >= start)
	{
		if (s1[end] == set[k])
		{
			end--;
			k = 0;
		}
		else if (set[k] != '\0')
			k++;
		else
			break ;
	}
	return (ft_cpyrange(s1, start, end));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	k;
	int	end;

	i = 0;
	k = 0;
	while (set[k])
	{
		if (s1[i] == set[k])
		{
			k = 0;
			i++;
		}
		else
			k++;
	}
	end = ft_strlen((char *)s1);
	return (ft_trimend(s1, set, i, end));
}
/* 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	char *result = ft_strtrim("hellothehtat", "the");
	printf("%s", result);
	free(result);
} */