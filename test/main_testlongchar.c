/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_testlongchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:49:35 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/18 10:25:17 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>

int		ft_putlongchar_fd(wchar_t c, int fd)
{
	unsigned char t[11];
	unsigned char tmp;
	int n;
	int nbyte;

	n = 0;
	while (c)
	{
		t[n++] = c % 16;
		t[n] = c / 16;
		c /= 16;
	}
	nbyte = n / 2;
	n--;
	while (n >= 0)
	{
		tmp = t[n] * 16 + t[n - 1];
		write(fd, &tmp, 1);
		n -= 2;
	}
	return (nbyte);
}



int		main(void)
{
	wchar_t p = L'☢';
	wchar_t g = 14850210;
	char s[] = {0xe2, 0x98, 0xa2, 0x00};
	setlocale(LC_ALL, "UTF-8");
	int r1 = printf("%s", s);
	printf("\ntest: %1$u\n", p);
	int r2 = ft_putlongchar_fd(g, 1);
	printf("\n printf :%d ft_longchar : %d\n", r1, r2);
	return (0);
}
