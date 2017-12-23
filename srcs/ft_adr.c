/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 10:31:21 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 14:13:47 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_calladr(uintmax_t n, t_flags f, int len)
{
	size_t	flen;
	int		res;

	flen = (f.have_p && f.precision > len) ? f.precision : len;
	flen += (f.have_hash) ? 2 : 0;
	flen += (n == 0 && !f.have_p) ? 1 : 0;
	dprintf(2, "flen:%zu\n", flen);
	res = ft_fillforward_hex(f, flen);
	res += ft_filldimen_hex(f, len);
	if (n != 0 || (n == 0 && f.have_p == 0))
		res += ft_fillhex(n, f.type);
	res += ft_fillbackward(f, 0, flen);
	return (res);
}

int		ft_call_filladr(va_list *ap, t_flags f)
{
	uintmax_t	n;
	int			l;

	f.len_flags[0] = 'l';
	f.len_flags[1] = 0;
	n = ft_get_uint(ap, f);
	if (n != 0)
		l = ft_len_nb(n, 16);
	else
		l = 0;
	f.type = 'x';
	f.have_hash = 1;
	return (ft_calladr(n, f, l));
}
