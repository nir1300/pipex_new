/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:32:00 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/19 17:30:23 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	int		n;
// 	int		i;
// 	int		*array;
// 	int		*array1;

// 	n = 0;
// 	i = 0;
// 	array = (int *)calloc(2000000000, 2000000*4);
// 	while (i < n)
// 	{
// 		array[i] = 2 * i;
// 		i++;
// 	}
// 	
// 	i = 0;
// 	while (i < n)
// 	{
// 		printf("%i", array[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	array1 = (int *)ft_calloc(n, sizeof(int));
// 	i = 0;
// 	while (i < n)
// 	{
// 		((int *)array1)[i] = 2 * i;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < n)
// 	{
// 		printf("%i", array1[i]);
// 		i++;
// 	}
// 	
// 	if (!array)
// 		printf("NULL");
// }
