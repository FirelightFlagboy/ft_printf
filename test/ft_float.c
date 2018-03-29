/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:55:36 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/28 16:17:25 by fbenneto         ###   ########.fr       */
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
	if (pre > 0)
		l++;
	i = 0;
	if (d < pow(10, i))
		l++;
	while (d > pow(10, i++))
		l++;
	return (l);
}

char	*__ftoap2_cte(char *s, double d[2], int neg, int k[2])
{
	double	t;
	double	p;
	int		i;
	int		len;

	t = d[0];
	p = d[1];
	len = k[1];
	i = 0;
	d[1] = 1.0;
	while (t > d[1] || i < k[0])
	{
		d[0] = pow(10, i + 1);
		s[len--] = (int)(fmod(t, d[0]) / d[1]) + '0';
		d[1] = d[0];
		i++;
	}
	if (k[0] > 0)
		s[len--] = '.';
	i = 0;
	d[1] = 1.0;
	if (p < d[1])
		s[len--] = '0';
	while (p > d[1])
	{
		d[0] = pow(10, i + 1);
		s[len--] = (int)(fmod(p, d[0]) / d[1]) + '0';
		d[1] = d[0];
		i++;
	}
	if (neg)
		s[0] = '-';
	return (s);
}

int		ftoa_cte(char *s, double d, int pre)
{
	double t;
	double p;
	size_t len;
	int neg;

	if (pre < 0)
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
	s[len--] = 0;
	t = t * pow(10, pre) + 0.5;
	__ftoap2_cte(s, (double [2]){t, p}, d < 0.0, (int [2]){pre, len});
	return (len + 1);
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
	int pre = -1;
	char s[2048];
	double d[] =
	{
			0.42,
			0.31546,
			-785.640625,
			999999999999900000001.0,
			M_PI,
			0.0,
			__FLT_MAX__,
			__FLT_MIN__,
			0.000000000000000000000000000000000000000000000001,
			INTMAX_MAX,
			9223372036854775808.00000000000000000000000000005,
			0.41999999999999998445687765525,
			0.000000000419999999999999987765525
	};
	dprintf(1, "\e[2J\e[3J\e[0;0H");
	dprintf(9, "\e[2J\e[3J\e[0;0H");
	while (i < sizeof(d) / sizeof(double))
	{
		printf(">>>>>>>>>> %d <<<<<<<<<\n", i);
		ftoa_cte(s, d[i], pre);
		printf("str f :%s|\n", s);
		printf("float :%.*f|\n", pre, d[i]);
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
