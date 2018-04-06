/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 11:47:47 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 11:56:09 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int			ft_sprintf(char *s, char *format, ...)
{
	va_list ap;
	int		rt;

	if (!s || !format)
		return (-1);
	return (rt);
}

int			ft_snprintf(char *s, size_t n, char *format, ...)
{
	va_list ap;
	int		rt;

	if (!s || !format)
		return (-1);
	return (rt);

}

int			ft_asprintf(char **as, char *format, ...)
{
	va_list ap;
	int		rt;

	if (!as || !format)
		return (-1);
	return (rt);
}
