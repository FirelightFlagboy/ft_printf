/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 09:35:08 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/26 16:21:53 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fillnbr(uintmax_t n, t_flags f, int len, char isneg)
{
	ft_filldimen(f, isneg, len);
	if (n != 0 || (n == 0 && f.have_p == 0))
		ft_itoa(n);
	return (0);
}

int		ft_callnbr(intmax_t n, t_flags f, int len, char isneg)
{
	uintmax_t	un;
	size_t		flen;

	un = (isneg) ? -n : n;
	flen = len;
	if (f.have_p)
	{
		f.have_null = 0;
		if (f.precision > len)
			flen = f.precision;
	}
	if (f.have_buff_size && f.have_null
	&& (n == 0 || (isneg && !f.have_minus)))
		f.buff_size--;
	if (f.have_minus == 0 && f.have_buff_size)
		ft_fillforward(f, isneg, flen);
	ft_fillnbr(un, f, len, isneg);
	if (f.have_minus == 1 && f.have_buff_size)
		ft_fillbackward(f, isneg, flen);
	return (1);
}

int		ft_call_fillnbr(va_list *ap, t_flags f)
{
	intmax_t	n;
	int			l;
	char		neg;

	n = ft_get_int(ap, f);
	l = 0;
	neg = 0;
	if (n < 0)
		neg = 1;
	if (n != 0)
		l = ft_len_nb((n >= 0) ? n : -n, 10);
	if (n >= 0 && f.have_null\
	&& (f.have_add || f.have_escape))
		f.buff_size--;
	return (ft_callnbr(n, f, l, neg));
}
