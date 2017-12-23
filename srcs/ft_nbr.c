/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 09:35:08 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 16:03:34 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fillunbr(uintmax_t n)
{
	return (ft_itoa(n));
}

int		ft_callunbr(uintmax_t n, t_flags f, int len)
{
	size_t	flen;
	int		res;

	f.have_null = (f.have_p) ? 0 : f.have_null;
	if (f.have_buff_size && f.have_null && n == 0)
		f.buff_size--;
	flen = (f.have_p && f.precision > len) ? f.precision : len;
	res = ft_fillforward_uin(f, flen);
	res += ft_filldimen_uin(f, len);
	if (n != 0 || (n == 0 && f.have_p == 0))
		res += ft_fillunbr(n);
	res += ft_fillbackward(f, 0, flen);
	return (res);
}

int		ft_callnbr(intmax_t n, t_flags f, int len)
{
	uintmax_t	un;
	size_t		flen;
	int			res;
	char		isneg;

	isneg = (n >= 0) ? 0 : 1;
	un = (isneg) ? -n : n;
	f.have_null = (f.have_null && f.have_p) ? 0 : f.have_null;
	if (f.have_buff_size && f.have_null
	&& (n == 0 || (isneg && !f.have_minus)))
		f.buff_size--;
	flen = (f.have_p && f.precision > len) ? f.precision : len;
	res = ft_fillforward(f, isneg, flen);
	res += ft_filldimen(f, isneg, len);
	if (n != 0 || (n == 0 && f.have_p == 0))
		res += ft_fillunbr(un);
	res += ft_fillbackward(f, isneg, flen);
	return (res);
}

int		ft_call_fillunbr(va_list *ap, t_flags f)
{
	uintmax_t	n;
	int			l;

	n = ft_get_uint(ap, f);
	if (n != 0)
		l = ft_len_nb(n, 10);
	else
		l = 0;
	f.have_add = 0;
	return (ft_callunbr(n, f, l));
}

int		ft_call_fillnbr(va_list *ap, t_flags f)
{
	intmax_t	n;
	int			l;

	n = ft_get_int(ap, f);
	if (n != 0)
		l = ft_len_nb((n >= 0) ? n : -n, 10);
	else
		l = 0;
	if (n >= 0 && f.have_null\
	&& (f.have_add || f.have_escape))
		f.buff_size--;
	return (ft_callnbr(n, f, l));
}
