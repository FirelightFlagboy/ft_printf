/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 09:28:30 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 09:50:10 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_filloctal(uintmax_t n)
{
	return (ft_itoa_base(n, "01234567"));
}

int		ft_calloctal(uintmax_t n, t_flags f, int len)
{
	size_t	flen;
	int		res;

	flen = (f.have_p && f.precision > len) ? f.precision : len;
	flen += (f.have_hash) ? 1 : 0;
	res = ft_fillforward_oct(f, flen);
	res += ft_filldimen_oct(f, len);
	res += ft_filloctal(n);
	res += ft_fillbackward(f, 0, len);
	return (res);
}

int		ft_call_filloctal(va_list *ap, t_flags f)
{
	uintmax_t	n;
	int			l;

	n = ft_get_uint(ap, f);
	l = ft_len_nb(n, 8);
	f.have_hash = (n == 0) ? 0 : f.have_hash;
	return (ft_calloctal(n, f, l));
}
