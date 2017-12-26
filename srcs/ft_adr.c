/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 10:31:21 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/26 09:43:12 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_calladr(uintmax_t n, t_flags f, int len)
{
	size_t	flen;

	flen = len;
	if (f.precision > len)
		flen = f.precision;
	if (f.have_hash)
		flen += 2;
	if (n == 0 && f.have_p == 0)
		flen++;
	if (f.have_minus == 0 && f.have_buff_size)
		ft_fillforward_hex(f, flen);
	ft_filldimen_hex(f, len);
	if (n != 0 || (n == 0 && f.have_p == 0))
		ft_itoa_base(n, "0123456789abcdef");
	if (f.have_minus == 1 && f.have_buff_size)
		ft_fillbackward(f, 0, flen);
	return (1);
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
