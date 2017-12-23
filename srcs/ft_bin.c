/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 09:21:37 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 16:38:27 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fillbin(uintmax_t n)
{
	return (ft_itoa_base(n, "01"));
}

int		ft_callbin(uintmax_t n, t_flags f, int len)
{
	size_t	flen;

	flen = (f.have_p && f.precision > len) ? f.precision : len;
	flen += (f.have_hash) ? 2 : 0;
	if (f.have_minus == 0 && f.have_buff_size)
		ft_fillforward_hex(f, len);
	ft_filldimen_hex(f, len);
	if (n != 0 || (n == 0 && f.have_p == 0))
		ft_fillbin(n);
	if (f.have_minus == 1 && f.have_buff_size)
		ft_fillbackward(f, 0, len);
	return (1);
}

int		ft_call_fillbin(va_list *ap, t_flags f)
{
	uintmax_t	nb;
	int			l;

	nb = ft_get_uint(ap, f);
	if (nb != 0)
		l = ft_len_nb(nb, 2);
	else
		l = 0;
	f.have_hash = (nb == 0) ? 0 : f.have_hash;
	return (ft_callbin(nb, f, l));
}
