/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 09:28:30 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 16:45:40 by fbenneto         ###   ########.fr       */
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

	flen = (f.have_p && f.precision > len) ? f.precision : len;
	flen += (f.have_hash) ? 1 : 0;
	if (f.have_minus == 0 && f.have_buff_size)
		ft_fillforward_oct(f, flen);
	ft_filldimen_oct(f, len);
	if (n != 0 || (n == 0 && f.have_p == 0))
		ft_filloctal(n);
	if (f.have_minus == 1 && f.have_buff_size)
		ft_fillbackward(f, 0, flen);
	return (1);
}

int		ft_call_filloctal(va_list *ap, t_flags f)
{
	uintmax_t	n;
	int			l;

	n = ft_get_uint(ap, f);
	l = ft_len_nb(n, 8);
	if (n == 0)
	{
		f.buff_size++;
		if (f.have_p == 0)
			f.have_hash = 0;
	}
	return (ft_calloctal(n, f, l));
}
