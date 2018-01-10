/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 09:57:18 by fbenneto          #+#    #+#             */
/*   Updated: 2018/01/10 10:15:48 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_len_nb(intmax_t n, int base)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa(intmax_t nb)
{
	static char	s[65];
	size_t		len;

	len = ft_len_nb(nb, 10);
	s[len] = 0;
	len--;
	while (len)
	{
		s[len] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	s[len] = (nb) + '0';
	return (s);
}

void	ft_putstr(char *s)
{
	write(1, s, strlen(s));
}

void	ft_putnbr(intmax_t nb)
{
	char *s;

	s = ft_itoa(nb);
	ft_putstr(s);
}

int		ft_pow(int n, int p)
{
	if (p == 0)
		return (1);
	return (n * ft_pow(n, p - 1));
}

void	ft_float(double floa, int pre)
{
	signed long int decipart;
	signed long int intpart;
	size_t	len;

	if (floa < 0)
	{
		ft_putchar('-');
		floa *= -1;
	}
	intpart = (signed long int)floa;
	ft_putnbr(intpart);
	ft_putchar('.');
	floa -= intpart;
	floa *= ft_pow(10, pre);
	decipart = (signed long int)(floa + 0.5);	//+0.5 to round of the value
	len = ft_len_nb(decipart, 10);
	while (pre - len)
	{
		ft_putchar('0');
		len++;
	}
	ft_putnbr(decipart);
}

int		main(void)
{
	double	i = 1.42;
	double	p = 1.424352;
	double	c = 1.004243;
	double	b = 12313.0001341;
	ft_float(i, 6);
	ft_putchar('\n');
	ft_float(p, 6);
	ft_putchar('\n');
	ft_float(c, 6);
	ft_putchar('\n');
	ft_float(b, 6);
	ft_putchar('\n');
	printf("%.2f\n", c);
}
