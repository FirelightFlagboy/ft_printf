/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:24:04 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 16:28:45 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_get_uint(va_list *ap, t_flags f)
{
	if (f.type == 'U' || f.type == 'O' || f.type == 'B'\
	|| ft_strcmp(f.len_flags, "l") == 0)
		return ((unsigned long)va_arg(*ap, unsigned long));
	if (f.len_flags[0] == 0)
		return ((unsigned int)va_arg(*ap, unsigned int));
	if (f.len_flags[0] == 'h')
	{
		if (f.len_flags[1] == 'h')
			return ((unsigned char)va_arg(*ap, unsigned int));
		return ((unsigned short)va_arg(*ap, unsigned int));
	}
	return ((uintmax_t)va_arg(*ap, uintmax_t));
}

intmax_t	ft_get_int(va_list *ap, t_flags f)
{
	if (f.type == 'D' || ft_strcmp(f.len_flags, "l") == 0)
		return ((long)va_arg(*ap, long));
	if (f.len_flags[0] == 0)
		return ((int)va_arg(*ap, int));
	if (f.len_flags[0] == 'h')
	{
		if (f.len_flags[1] == 'h')
			return ((char)va_arg(*ap, int));
		return ((short)va_arg(*ap, int));
	}
	return ((intmax_t)va_arg(*ap, intmax_t));
}
