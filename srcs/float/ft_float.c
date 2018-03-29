/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:01:07 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/29 09:44:01 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"
#include "ft_float.h"

static inline int	ft_float_addreel(char *s, double r, int neg, int len)
{
	double	p;
	double	a;
	int		i;

	p = 1.0;
	i = 0;
	if (r < 1.0)
		s[len--] = '0';
	while (r > p)
	{
		a = ft_pow(10, i++ + 1);
		s[len--] = (int)(fmod(r, a) / p) + '0';
		p = a;
	}
	if (neg)
		s[0] = '-';
	return (ft_add_str_to_buff(s));
}

static inline int	ft_fillfloat(double d[2], int n[2], int len)
{
	char	s[1024];
	double	v;
	double	r;
	int		i;

	s[len--] = 0;
	r = d[0];
	v = d[1] * ft_pow(10, n[1]);
	d[1] = 1;
	i = 0;
	while (v > d[1] || i < n[1])
	{
		d[0] = ft_pow(10, i++ + 1);
		s[len--] = (int)(fmod(v, d[0]) / d[1]) + '0';
		d[1] = d[0];
	}
	if (n[1])
		s[len--] = '.';
	return (ft_float_addreel(s, r, n[0], len));
}

static inline int	ft_setvalue(int n[2], int *flen, int len, t_flags *f)
{
	int		neg;

	neg = n[0];
	*flen = len;
	if (n[0] && f->flags & HI_BUFF_SIZE && (f->flags & HI_NULL)\
	&& (f->flags & HI_MINUS) == 0)
	{
		flen = flen - 1;
		n[0] = 0;
	}
	return (neg);
}

static inline int	ft_callfloat(double d[2], int n[2], t_flags *f, int len)
{
	int		neg;
	int		flen;

	neg = ft_setvalue(n, &flen, len, f);
	if (f->buff_size)
	{
		if (f->flags & HI_MINUS)
		{
			ft_fillfloat(d, n, flen);
			ft_fillbackward(f, neg, len);
		}
		else
		{
			ft_fillforward_float(f, neg, flen);
			ft_fillfloat(d, n, len);
		}
	}
	else
		ft_fillfloat(d, n, len);
	return (1);
}

int					ft_call_fillfloat(va_list *ap, t_flags *f)
{
	double	d;
	double	v;
	int		l;
	int		pre;
	int		neg;

	pre = 6;
	if (ft_isnan_or_inf((d = (double)va_arg(*ap, double)), f))
		return (0);
	if (d < 0.0)
	{
		v = modf(-d, &d);
		neg = 1;
	}
	else
		v = modf(d, &d);
	if (f->flags & HI_PRECISION && f->precision >= 0)
	{
		pre = f->precision;
		if (pre > 768)
			pre = 768;
	}
	neg = 0;
	l = ft_len_double(d, v, pre);
	return (ft_callfloat((double [2]){d, v}, (int [2]){neg, pre}, f, l));
}
