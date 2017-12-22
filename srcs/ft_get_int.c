/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:24:04 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 15:28:45 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_uint_size(t_flags f)
{
	int size;

	if (f.type == 'U' || f.type == 'O')
		return (2);
	size = 0;
	if (ft_strcmp(f.len_flags, "hh") == 0)
		size -= 2;
	else if (ft_strcmp(f.len_flags, "h") == 0)
		size--;
	else if (ft_strcmp(f.len_flags, "") == 0)
		size += 0;
	else if (ft_strcmp(f.len_flags, "l") == 0)
		size++;
	else
		size += 2;
	return (size);
}

static int	ft_int_size(t_flags f)
{
	if (f.type == 'D')
		return (1);
	if (ft_strcmp(f.len_flags, "hh") == 0)
		return (-2);
	if (ft_strcmp(f.len_flags, "h") == 0)
		return (-1);
	if (ft_strcmp(f.len_flags, "") == 0)
		return (0);
	if (ft_strcmp(f.len_flags, "l") == 0)
		return (1);
	else
		return (2);
}

uintmax_t	ft_get_uint(va_list *ap, t_flags f)
{
	uintmax_t	n;
	int			size;

	size = ft_uint_size(f);
	if (size == -2)
		n = (unsigned char)va_arg(*ap, unsigned int);
	else if (size == -1)
		n = (unsigned short)va_arg(*ap, unsigned int);
	else if (size == 0)
		n = (unsigned int)va_arg(*ap, unsigned int);
	else if (size == 1)
		n = (unsigned long)va_arg(*ap, unsigned long);
	else
		n = (uintmax_t)va_arg(*ap, uintmax_t);
	return (n);
}

intmax_t	ft_get_int(va_list *ap, t_flags f)
{
	intmax_t	nm;
	int			size;

	nm = 0;
	size = ft_int_size(f);
	if (size == -2)
		nm = (char)va_arg(*ap, int);
	else if (size == -1)
		nm = (short)va_arg(*ap, int);
	else if (size == 0)
		nm = (int)va_arg(*ap, int);
	else if (size == 1)
		nm = (long)va_arg(*ap, long);
	else
		nm = (intmax_t)va_arg(*ap, long long);
	return (nm);
}
