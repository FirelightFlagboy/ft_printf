/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stdarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:00:14 by fbenneto          #+#    #+#             */
/*   Updated: 2017/11/30 13:29:17 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>
#include <stdarg.h>

size_t	ft_strlen(unsigned char *s)
{
	size_t i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int		ft_putchar(unsigned char *s)
{
	int n;

	n = 1;
	write(1, s, ft_strlen(s));
	return (n);
}

int		ft_test(char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (strncmp(str + i, "%s", 2) == 0)
		{
			printf("%s", va_arg(ap, char *));
			i++;
		}
		else if (strncmp(str + i, "%d", 2) == 0)
		{
			printf("%d", va_arg(ap, int));
			i++;
		}
		else if (strncmp(str + i, "%c", 2) == 0)
		{
			printf("%c", (char)va_arg(ap, int));
			i++;
		}
		else
			printf("%c", str[i]);
		i++;
	}
	va_end(ap);
	return(i);
}

int		main(void)
{
	int c = u'¾';
	c = 513;
	char happy[] = {0xe2, 0x98, 0xba, 0};
	char test[] = {0x12, 0x99, 0};
	int i;

	setlocale(LC_ALL, "");
	i = printf(">%lc\n>%lc\n>%d\n", u'¾', c, c);
	i = printf("%lc", c);
	printf("\n%d %d\n", i, 2);
	printf("%zu %p\n", (size_t)&i, &i);
	ft_test("bonjour je suis %s\n%d\n%lc\n", "moi", 132456789, c);

	ft_putchar((unsigned char *)">\0");
	write(1, happy, strlen(happy));
	write(1, test, strlen(test));
	ft_putchar((unsigned char *)"\0");
	ft_putchar((unsigned char *)">\0");
	ft_putchar((unsigned char *)&c);
	printf("%u\n", c);
	ft_putchar((unsigned char *)"<\n\0");
	ft_putchar((unsigned char *)">\0");
	ft_putchar((unsigned char *)"c\0");
	ft_putchar((unsigned char *)"\n\0");
	return 0;
}
