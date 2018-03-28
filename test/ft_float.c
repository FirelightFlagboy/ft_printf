/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:55:36 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/27 16:48:56 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <string.h>
#include <ctype.h>
#include <float.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

static inline size_t ft_len_double(double d, double t, int pre)
{
	size_t l;
	int i;

	l = 0;
	i = 0;
	t = t * pow(10, pre);
	i = 0;
	while (t > pow(10, i) || i < pre)
	{
		l++;
		i++;
	}
	l++;
	i = 0;
	if (d < pow(10, i))
		l++;
	while (d > pow(10, i++))
		l++;
	return (l);
}

char	*__ftoap2(char *s, double d[2], int neg, int k[2])
{
	double	t;
	double	p;
	int		i;
	int		len;

	t = d[0];
	p = d[1];
	len = k[1];
	i = 0;
	while (t > pow(10, i) || i < k[0])
	{
		s[len--] = (int)(fmod(t, pow(10, i + 1)) / pow(10, i)) + '0';
		i++;
	}
	s[len--] = '.';
	i = 0;
	if (p < pow(10, i))
		s[len--] = '0';
	while (p > pow(10, i))
	{
		s[len--] = (int)(fmod(p, pow(10, i + 1)) / pow(10, i)) + '0';
		i++;
	}
	if (neg)
		s[0] = '-';
	return (s);
}

char	*ftoa(double d, int pre)
{
	double t;
	double p;
	size_t len;
	char *s;
	int neg;

	if (pre < 6)
		pre = 6;
	neg = 0;
	if (d < 0.0)
	{
		t = modf(-d, &p);
		neg = 1;
	}
	else
		t = modf(d, &p);
	len = ft_len_double(p, t, pre) + neg;
	if (!(s = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	s[len--] = 0;
	t = t * pow(10, pre);
	return (__ftoap2(s, (double [2]){t, d}, d < 0.0, (int [2]){pre, len}));
}

char *etoa(long double d, int pre)
{
	long double expo;

	(void)pre;
	printf(">>>>>>>  etoa <<<<<<<<\n");
	expo = logl(d);
	printf("expo :%Lf\n", expo);
	printf(">>>>>>>  etoa end <<<<<<<<\n");
	return (NULL);
}

int main(void)
{
	uint32_t i = 0;
	int pre = 20;
	char *s;
	double d[] =
		{
			0.42,
			0.31546,
			-785.640625,
			999999999999900000001.0,
			0.0,
			__FLT_MAX__,
			__FLT_MIN__,
			0.000000000000000000000000000000000000000000000001,
			INTMAX_MAX,
			9223372036854775808.00000000000000000000000000005,
			0.41999999999999998445687765525,
			0.000000000419999999999999987765525};

	dprintf(9, "\e[2J\e[3J\e[0;0H");
	while (i < sizeof(d) / sizeof(double))
	{
		printf(">>>>>>>>>> %d <<<<<<<<<\n", i);
		s = ftoa(d[i], pre);
		printf("str f :%s\n", s);
		free(s);
		printf("float :%.*f\n", pre, d[i]);
		// s = etoa(d[i], pre);
		// printf("str e :%s\n", s);
		// free(s);
		// printf("expo  :%*e\n", pre, d[i]);
		// printf("short :%*g\n", pre, d[i]);
		// printf("hex   :%*a\n", pre, d[i]);
		i++;
	}
	return (0);
}
