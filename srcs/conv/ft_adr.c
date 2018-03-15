/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 10:31:21 by fbenneto          #+#    #+#             */
/*   Updated: 2018/01/16 13:10:43 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_filladr(uintmax_t n, t_flags f, int len)
{
	ft_filldimen_hex(f, len);
	if (n != 0 || (n == 0 && f.have_p == 0))
		ft_itoa_base_buff(n, "0123456789abcdef");
	return (0);
}

int		ft_calladr(uintmax_t n, t_flags f, int len)
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
			ft_filladr(n, f, len);
			ft_fillbackward(f, 0, flen);
		}
		else
		{
			ft_fillforward_hex(f, flen);
			ft_filladr(n, f, len);
		}
	}
	else
		ft_filladr(n, f, len);
	return (1);
}

int		ft_call_filladr(va_list *ap, t_flags f)
{
	uintmax_t	n;
	int			l;

	f.len_flags[0] = 'l';
	f.len_flags[1] = 0;
	f.type = 'x';
	f.have_hash = 1;
	n = ft_get_uint(ap, f);
	if (n != 0)
		l = ft_len_nb(n, 16);
	else
	{
		if (!f.have_p)
			l = 1;
		else
			l = 0;
	}
	return (ft_calladr(n, f, l));
}
