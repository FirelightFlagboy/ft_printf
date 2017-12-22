/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:19:56 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 12:29:00 by fbenneto         ###   ########.fr       */
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
	return(rt);
}

int		ft_vfprintf(int fd, char const *s, va_list ap)
{
	va_list node;

	if (fd < 0 || fd > OPEN_MAX || !s)
		return (-1);
	gl_buff.index = 0;
	gl_buff.res = 0;
	va_copy(node, ap);
	va_end(node);
	return (gl_buff.res);
}
