/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:01:54 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/11/25 20:54:03 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countoutput(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_printformat(const char format, va_list args)
{
	int	ret;

	ret = 0;
	if (format == '%')
		ret += ft_putchar('%');
	else if (format == 'c')
		ret += ft_putchar(va_arg(args, int));
	else if (format == 's')
		ret += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		ret += convert_ptr(va_arg(args, void *));
	else if (format == 'i' || format == 'd')
		ret += ft_putnbr(va_arg(args, int), format);
	else if (format == 'u')
		ret += ft_putnbr_uns(va_arg(args, unsigned int));
	else if (format == 'X' || format == 'x')
		ret += convert_dec_hex(va_arg(args, unsigned int), format);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format != 'c' && *format != 's' && *format != 'p'
				&& *format != 'i' && *format != 'u' && *format != 'x'
				&& *format != 'X' && *format != 'd' && *format != '%')
				return (-1);
			if (*format != '\0')
				ret += ft_printformat(*format, args);
		}
		else
			ret += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (ret);
}

/* 
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char			c;
	char			*s;
	int				i;
	void			*ptr;
	int				dec;
	unsigned int	unint;
	int				a;
	int				d;
	unsigned int	x;
	int				q;
	int				b;
	int				e;
	int				y;
	int				p;
	int				n;
	int				u;
	int				m;
	int				uu;

	c = 'h';
	s = "hello";
	i = 123456789;
	ptr = &i;
	dec = 012;
	unint = -234;
	a = printf("c: %c, ", c);
	printf("len c: %d\n", a);
	d = printf("s: %s, ", s);
	printf("len s: %d\n", d);
	n = printf("p: %p, ", ptr);
	printf("len: %d\n", n);
	printf("d: %d\n", dec);
	printf("i: %i\n", i);
	u = printf("u: %u, ", unint);
	printf("len u: %d\n", u);
	x = printf("x: %x, ", i);
	printf("len x: %d\n", x);
	printf("X: %X\n", i);
	q = printf("Percent: %%\n");
	printf("len percent: %d\n", q);
	printf("\n");
	b = ft_printf("c: %c, ", c);
	printf("len c: %d\n", b);
	e = ft_printf("s: %s, ", s);
	ft_printf("len s: %d\n", e);
	m = ft_printf("p: %p, ", ptr);
	ft_printf("len: %d\n", m);
	ft_printf("d: %d\n", dec);
	ft_printf("i: %i\n", i);
	uu = ft_printf("u: %u, ", unint);
	ft_printf("len u: %d\n", uu);
	y = ft_printf("x: %x, ", i);
	ft_printf("len x: %d\n", y);
	ft_printf("X: %X\n", i);
	p = ft_printf("Percent: %%\n");
	ft_printf("len percent: %d\n", p);
}
 */