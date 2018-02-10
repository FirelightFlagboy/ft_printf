/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:22:20 by fbenneto          #+#    #+#             */
/*   Updated: 2018/01/16 13:10:10 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fillhex(uintmax_t n, t_flags f, int len)
{
	char	*base;

	if (f.precision)
		ft_filldimen_hex(f, len);
	if (!(n != 0 || (n == 0 && f.have_p == 0)))
		return (0);
	if (f.type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (ft_itoa_base_buff(n, base));
}

int		ft_callhex(uintmax_t n, t_flags f, int len)
{
	size_t	flen;

	flen = len;
	if (f.precision > len)
		flen = f.precision;
	if (f.have_hash)
		flen += 2;
	if (f.buff_size)
	{
		if (f.have_minus)
		{
			ft_fillhex(n, f, len);
			ft_fillbackward(f, 0, flen);
		}
		else
		{
			ft_fillforward_hex(f, flen);
			ft_fillhex(n, f, len);
		}
	}
	else
		ft_fillhex(n, f, len);
	return (1);
}

int		ft_call_fillhex(va_list *ap, t_flags f)
{
	uintmax_t	nb;
	int			l;

	nb = ft_get_uint(ap, f);
	l = ft_len_nb(nb, 16);
	if (nb)
	{
		if (!f.precision)
			f.precision = 1;
	}
	else
	{
		f.have_hash = 0;
		if (f.have_p && f.precision == 0)
			l = 0;
	}
	return (ft_callhex(nb, f, l));
}
