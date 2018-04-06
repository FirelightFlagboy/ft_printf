/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:24:34 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 13:46:24 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_vfprintf(FILE *stream, char const *format, va_list ap)
{
	va_list node;
	t_buff	*buff;
	int		(*f)(const char*, va_list);

	if (stream->_file < 0 || stream->_file > OPEN_MAX || !format)
		return (-1);
	buff = get_buff();
	buff->index = 0;
	buff->res = 0;
	buff->fd = stream->_file;
	buff->put = ft_putbuffer;
	va_copy(node, ap);
	if (ft_strchr_printf(format, '{'))
		f = ft_fill_buffer_color;
	else
		f = ft_fill_buffer;
	if (f(format, node) != -1)
		buff->put(buff);
	else
		return (-1);
	va_end(node);
	return (buff->res);
}

int		ft_vdprintf(int fd, char const *format, va_list ap)
{
	va_list node;
	t_buff	*buff;
	int		(*f)(const char*, va_list);

	if (fd < 0 || fd > OPEN_MAX || !format)
		return (-1);
	buff = get_buff();
	buff->index = 0;
	buff->res = 0;
	buff->fd = fd;
	buff->put = ft_putbuffer;
	va_copy(node, ap);
	if (ft_strchr_printf(format, '{'))
		f = ft_fill_buffer_color;
	else
		f = ft_fill_buffer;
	if (f(format, node) != -1)
		buff->put(buff);
	else
		return (-1);
	va_end(node);
	return (buff->res);
}
