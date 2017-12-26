/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 15:06:22 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/26 15:16:15 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fillunbr(uintmax_t n, t_flags f, int len)
{
	if (f.precision)
		ft_filldimen_uin(f, len);
	if (n != 0 || (n == 0 && f.have_p == 0))
		ft_itoa(n);
	return (0);
}

int		ft_callunbr(uintmax_t n, t_flags f, int len)
{
	size_t	flen;

	flen = len;
	if (f.precision > len)
		flen = f.precision;
	if (f.have_p)
		f.have_null = 0;
	if (f.buff_size)
	{
		if (n == 0 && f.have_null)
			f.buff_size--;
		if (f.have_minus)
		{
			ft_fillunbr(n, f, len);
			ft_fillbackward(f, 0, flen);
		}
		else
		{
			ft_fillforward_uin(f, flen);
			ft_fillunbr(n, f, len);
		}
	}
	else
		ft_fillunbr(n, f, len);
	return (1);
}

int		ft_call_fillunbr(va_list *ap, t_flags f)
{
	uintmax_t	n;
	int			l;

	n = ft_get_uint(ap, f);
	if (n != 0)
		l = ft_len_nb(n, 10);
	else
		l = 0;
	f.have_add = 0;
	return (ft_callunbr(n, f, l));
}
