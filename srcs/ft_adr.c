/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 10:31:21 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 10:37:49 by fbenneto         ###   ########.fr       */
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
	res = ft_fillforward_hex(f, flen);
	res += ft_filldimen_hex(f, len);
	res += ft_fillhex(n, f.type);
	res += ft_fillbackward(f, 0, flen);
	return (res);
}

int		ft_call_filladr(va_list *ap, t_flags f)
{
	uintmax_t	n;
	int			l;

	n = ft_get_uint(ap, f);
	l = ft_len_nb(n, 16);
	f.type = 'x';
	f.len_flags[0] = 'l';
	f.len_flags[1] = 0;
	return (ft_calladr(n, f, l));
}
