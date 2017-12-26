/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:19:56 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/26 10:17:08 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char const *s, ...)
{
	va_list ap;
	int		rt;

	if (!s)
		return (-1);
	va_start(ap, s);
	rt = ft_vfprintf(1, s, ap);
	va_end(ap);
	return (rt);
}

int		ft_dprintf(int fd, char const *s, ...)
{
	va_list	ap;
	int		rt;

	if (fd < 0 || fd > OPEN_MAX || !s)
		return (-1);
	va_start(ap, s);
	rt = ft_vfprintf(fd, s, ap);
	va_end(ap);
	return (rt);
}

int		ft_vfprintf(int fd, char const *s, va_list ap)
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
