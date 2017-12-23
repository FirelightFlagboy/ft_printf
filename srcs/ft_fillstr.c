/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 10:54:34 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 11:20:00 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fill_longstr(wchar_t *s)
{
	return (ft_len_longstr(s));
}

int		ft_callstr(char *s, t_flags f, int len)
{
	size_t	flen;
	int		res;

	len = ft_strlen(s);
	flen = (f.have_p && f.precision < len) ? f.precision : len;
	res = ft_fillforward(f, 0, flen);
	res += ft_add_nstr_to_buff(s, flen);
	res += ft_fillbackward(f, 0, flen);
	return (res);
}

int		ft_call_longstr(wchar_t *s, t_flags f)
{
	long	flen;
	int		res;

	flen = ft_get_finale_len(s, f);
	if (flen == -1)
		return (-1);
	flen = (!f.have_p || (ft_len_unicode(*s) <= f.precision)) ? flen : 0;
	res = ft_fillforward(f, flen, 0);
	res += ft_fill_longstr(s);
	res += ft_fillbackward(f, 0, flen);
	return (res);
}

int		ft_call_fill_longstr(va_list *ap, t_flags f)
{
	wchar_t *s;

	s = (wchar_t*)va_arg(*ap, wchar_t*);
	f.have_add = 0;
	f.have_escape = 0;
	if (s == NULL)
		return (ft_callstr("(null)", f, 6));
	return (ft_call_longstr(s, f));
}

int		ft_call_fillstr(va_list *ap, t_flags f)
{
	char	*s;

	if (f.type == 'S' || ft_strcmp(f.len_flags, "l") == 0)
		return (ft_call_fill_longstr(ap, f));
	s = (char*)va_arg(*ap, char*);
	f.have_add = 0;
	f.have_escape = 0;
	if (s == NULL)
		return (ft_callstr("(null)", f, 6));
	return (ft_callstr(s, f, ft_strlen(s)));
}
