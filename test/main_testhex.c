/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_testhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:45:20 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/13 11:43:30 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int		ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	return (write(1, s, strlen(s)));
}

static int ft_putval(char val, char hight)
{
	char h;

	h = val % 16;
	if (h >= 10)
		return (ft_putchar(h - 10 + hight));
	return (ft_putchar(h + '0'));
}

int		ft_puthex(size_t nb)
{
	if (nb / 16)
		return (ft_puthex(nb / 16) + ft_putval(nb % 16, 'a'));
	return (ft_putval(nb % 16, 'a'));
}

int		ft_putoctal(size_t nb)
{
	char t[11];
	size_t dup;
	size_t n;

	dup = nb;
	n = 0;
	while (nb)
	{
		t[n++] = nb % 8;
		nb /= 8;
		t[n] = nb;
	}
	dup = n;
	while (n > 0)
		ft_putchar(t[--n] + '0');
	return (dup);
}

int		ft_putoctal2(size_t nb)
{
	if (nb / 8)
		return (ft_putoctal2(nb / 8) + ft_putchar((nb % 8) + '0'));
	return (ft_putchar((nb % 8) + '0'));
}

int		main(void)
{
	char *adr;
	void **ptr;
	int n1 = 123456789;
	ptr = (void**)&adr;

	// printf("********************************************\n");
	// printf("before test\n");
	// printf("********************************************\n");
	// printf("CHAR_MAX = %d\n", CHAR_MAX);
	// printf("INT_MAX = %d\n", INT_MAX);
	// printf("LONG_MAX = %ld\n", LONG_MAX);
	// printf("SSIZE_MAX = %ld\n", SSIZE_MAX);
	// printf("SIZE_T_MAX = %lu\n", SIZE_T_MAX);
	printf("********************************************\n");
	printf("test\n");
	printf("********************************************\n");
	ft_putstr("0x");
	ft_puthex((size_t)ptr);
	printf("\n%p\n", ptr);
	ptr = 0;
	ft_putstr("0x");	
	ft_puthex((size_t)ptr);
	printf("\n%p\n", ptr);
	ft_putoctal(n1);
	printf("\n%o\n", n1);
	ft_putoctal2(n1);
}
