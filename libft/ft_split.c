/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:01:44 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/12/02 22:25:51 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeme(char **arr, int a)
{
	while (a >= 0)
	{
		free(arr[a]);
		a--;
	}
	free(arr);
}

static char	**ft_nbarr(const char *s, char c)
{
	int		i;
	char	**arr;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	return (arr);
}

static char	**ft_charlen(const char *s, char c, char **arr, int count)
{
	int	a;

	a = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			count++;
			s++;
		}
		if (count != 0)
		{
			arr[a] = (char *)malloc(count + 1);
			if (arr[a] == NULL)
			{
				ft_freeme(arr, a);
				return (NULL);
			}
			a++;
			count = 0;
		}
	}
	return (arr);
}

static char	**ft_assign(const char *s, char c, char **arr)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = 0;
	b = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
		{
			arr[a][b] = s[i];
			b++;
			i++;
		}
		arr[a][b] = '\0';
		a++;
		b = 0;
		while (s[i] && s[i] == c)
			i++;
	}
	arr[a] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;

	arr = NULL;
	count = 0;
	if (s != NULL)
	{
		arr = ft_nbarr(s, c);
		if (arr == NULL)
			return (NULL);
		arr = ft_charlen(s, c, arr, count);
		if (arr == NULL)
			return (NULL);
		arr = ft_assign(s, c, arr);
	}
	return (arr);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	/*
// 	ch **new;
//     new = ft_split("\0aa\0bbb", '\0');
//     int i = 0;
//     while (new[i])
//     {
//         printf("%sx", new[i]);
// 		free(new[i]);
//         i++;
//     }
//     free(new);
// 	*/
//  	//const char	*s = "          ";
// 	char		**newarr;
// 	int			i;

// 	newarr = ft_split("hez", 'z');
// 	if (!newarr[0])
// 		printf("ok\n");
// 	else
// 		printf("no");

// 	i = 0;
// 	while (newarr[i])
// 	{
// 		printf("%s", newarr[i]);
// 		i++;
// 	}
// 	i=0;
// 	while (newarr[i])
// 	{
// 		free(newarr[i]);
// 		i++;
// 	}
// 	free(newarr);
// }