/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:22:20 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/26 09:42:57 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fillhex(uintmax_t n, char high)
{
	char	*base;

	if (high == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (ft_itoa_base(n, base));
}

int		ft_callhex(uintmax_t n, t_flags f, int len)
{
	size_t	flen;

	flen = len;
	if (f.precision > len)
		flen = f.precision;
	if (f.have_hash)
		flen += 2;
	if (f.have_minus == 0 && f.have_buff_size)
		ft_fillforward_hex(f, flen);
	ft_filldimen_hex(f, len);
	if (n != 0 || (n == 0 && f.have_p == 0))
		ft_fillhex(n, f.type);
	if (f.have_minus == 1 && f.have_buff_size)
		ft_fillbackward(f, 0, flen);
	return (1);
}

int		ft_call_fillhex(va_list *ap, t_flags f)
{
	uintmax_t	nb;
	int			l;

	nb = ft_get_uint(ap, f);
	l = ft_len_nb(nb, 16);
	if (nb == 0)
	{
		f.buff_size++;
		f.have_hash = 0;
	}
	return (ft_callhex(nb, f, l));
}
