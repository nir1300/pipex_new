/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:32:44 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/10 22:59:17 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>

static void	ft_function(unsigned int i, char *s)
{
	write(1, &s[i], 1);
}
int	main(void)
{
	char	*s;

	s = "hallo";
	ft_striteri(s, ft_function);
	printf("%s", s);
}
*/