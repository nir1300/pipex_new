/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:07:41 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/03 17:07:42 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i++] = c;
	}
	return (str);
}

/*
//overflow??
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	s12[] = "i";
	char	s[] = "l";

	ft_memset(s1, 'a', 2);
	puts(s1);
	ft_bzero(s1, sizeof(s1));
	memset(s, 'b', 2);
	puts(s);
	ft_bzero(s, sizeof(s1));
}
*/
