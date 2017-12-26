/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 10:38:59 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/26 11:19:57 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fill_longchar(wchar_t c)
{
	return (ft_unicode(c));
}

int		ft_call_longchar(wchar_t c, t_flags f)
{
	int		len;

	len = ft_len_unicode(c);
	if (len == -1)
		return (-1);
	if (f.have_minus == 0 && f.have_buff_size)
		ft_fillforward(f, 0, len);
	ft_fill_longchar(c);
	if (f.have_minus == 1 && f.have_buff_size)
		ft_fillbackward(f, 0, len);
	return (1);
}

int		ft_callchar(int c, t_flags f)
{
	if (f.have_minus == 0 && f.have_buff_size)
		ft_fillforward(f, 0, 1);
	ft_add_char_to_buff(c);
	if (f.have_minus == 1 && f.have_buff_size)
		ft_fillbackward(f, 0, 1);
	return (1);
}

int		ft_call_fill_longchar(va_list *ap, t_flags f)
{
	wchar_t c;

	f.have_add = 0;
	f.have_escape = 0;
	c = (wchar_t)va_arg(*ap, wchar_t);
	return (ft_call_longchar(c, f));
}

int		ft_call_fillchar(va_list *ap, t_flags f)
{
	int	c;

	if (f.type == 'C' || ft_strcmp(f.len_flags, "l") == 0)
		return (ft_call_fill_longchar(ap, f));
	c = (int)va_arg(*ap, int);
	f.have_add = 0;
	f.have_escape = 0;
	return (ft_callchar(c, f));
}
