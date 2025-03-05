/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:09:32 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/03 17:09:33 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (n-- > 0)
		((char *)s)[i++] = '\0';
}

/*
#include <stdio.h>
#include <strings.h>

int	main(void)
{
	char	s[] = "hello";
	char	m[] = "hello";

	bzero(s, sizeof(s));
	puts(s);
	ft_bzero(m, sizeof(m));
	puts(m);
}
*/
