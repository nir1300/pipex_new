/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:02:02 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/09 23:20:29 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	if (n >= 0 && n <= 9)
		return (i);
	while (n > 9 || n < -9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_helper(int n, int len, char *nbr)
{
	nbr[len] = '\0';
	if (n == 0)
		nbr[0] = '0';
	while (n > 0)
	{
		nbr[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;

	len = ft_intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nbr = malloc((len + 1) * sizeof(char));
	if (nbr == NULL)
		return (NULL);
	if (n < 0)
	{
		nbr[0] = '-';
		n *= -1;
	}
	return (ft_helper(n, len, nbr));
}

/* #include <stdio.h>

int	main(void)
{
	char *arr;

	arr = ft_itoa(2147483647);
	printf("%s", arr);
	free(arr);
} */