/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:22:20 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 09:30:32 by fbenneto         ###   ########.fr       */
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
	int		res;

	flen = (f.have_p && f.precision > len) ? f.precision : len;
	flen += (f.have_hash) ? 2 : 0;
	res = ft_fillforward_hex(f, len);
	res += ft_filldimen_hex(f, len);
	res += ft_fillhex(n, f.type);
	res += ft_fillbackward(f, 0, len);
	return (res);
}

int		ft_call_fillhex(va_list *ap, t_flags f)
{
	uintmax_t	nb;
	int			l;

	nb = ft_get_uint(ap, f);
	l = ft_len_nb(nb, 16);
	f.have_hash = (nb == 0) ? 0 : f.have_hash;
	return (ft_callhex(nb, f, l));
}
