/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 09:21:37 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/26 14:44:29 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fillbin(uintmax_t n, t_flags f, int len)
{
	if (f.precision)
		ft_filldimen_hex(f, len);
	if (n != 0 || (n == 0 && f.have_p == 0))
		ft_itoa_base(n, "01");
	return (1);
}

int		ft_callbin(uintmax_t n, t_flags f, int len)
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
			ft_fillbin(n, f, len);
			ft_fillbackward(f, 0, flen);
		}
		else
		{
			ft_fillforward_hex(f, flen);
			ft_fillbin(n, f, len);
		}
	}
	else
		ft_fillbin(n, f, len);
	return (1);
}

int		ft_call_fillbin(va_list *ap, t_flags f)
{
	uintmax_t	nb;
	int			l;

	nb = ft_get_uint(ap, f);
	if (nb)
	{
		l = ft_len_nb(nb, 2);
		if (!f.precision)
			f.precision = 1;
	}
	else
	{
		f.have_hash = 0;
		l = 0;
	}
	return (ft_callbin(nb, f, l));
}
