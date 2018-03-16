/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:24:34 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/16 10:25:03 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vfprintf(FILE *stream, char const *s, va_list ap)
{
	va_list node;
	t_buff	*buff;
	int		(*f)(const char*, va_list);

	if (stream->_file < 0 || stream->_file > OPEN_MAX || !s)
		return (-1);
	buff = get_buff();
	buff->index = 0;
	buff->res = 0;
	buff->fd = stream->_file;
	va_copy(node, ap);
	if (ft_strchr(s, '{'))
		f = ft_fill_buffer_color;
	else
		f = ft_fill_buffer;
	if (f(s, node) != -1)
		ft_putbuffer();
	else
		return (-1);
	va_end(node);
	return (buff->res);
}

int		ft_vdprintf(int fd, char const *s, va_list ap)
{
	va_list node;
	t_buff	*buff;
	int		(*f)(const char*, va_list);

	if (fd < 0 || fd > OPEN_MAX || !s)
		return (-1);
	buff = get_buff();
	buff->index = 0;
	buff->res = 0;
	buff->fd = fd;
	va_copy(node, ap);
	if (ft_strchr(s, '{'))
		f = ft_fill_buffer_color;
	else
		f = ft_fill_buffer;
	if (f(s, node) != -1)
		ft_putbuffer();
	else
		return (-1);
	va_end(node);
	return (buff->res);
}

