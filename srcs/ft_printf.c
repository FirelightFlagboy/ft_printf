/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:19:56 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/16 10:25:48 by fbenneto         ###   ########.fr       */
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
	rt = ft_vfprintf(stdout, s, ap);
	va_end(ap);
	return (rt);
}

int		ft_eprintf(char const *s, ...)
{
	va_list ap;
	int		rt;

	if (!s)
		return (-1);
	va_start(ap, s);
	rt = ft_vdprintf(STDERR_FILENO, s, ap);
	va_end(ap);
	return (rt);
}

int		ft_dprintf(int fd, char const *s, ...)
{
	va_list	ap;
	int		rt;

	if (!s)
		return (-1);
	va_start(ap, s);
	rt = ft_vdprintf(fd, s, ap);
	va_end(ap);
	return (rt);
}

int		ft_fprintf(FILE *stream, char const *s, ...)
{
	va_list	ap;
	int		rt;

	if (!s)
		return (-1);
	va_start(ap, s);
	rt = ft_vfprintf(stream, s, ap);
	va_end(ap);
	return (rt);
}
