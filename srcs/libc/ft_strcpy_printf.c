/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:52:00 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 13:08:03 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

static inline size_t	ft_n_process(char const *s, size_t n)
{
	size_t	i;

	i = ft_strlen_printf(s);
	if (i < n)
		return (i);
	else
		return (n);
}

char	*ft_strncpy_printf(char *dest, char const *s, size_t n)
{
	size_t	i;
	size_t	*bdest;
	size_t	*bs;
	char	*r;

	r = dest;
	bdest = (size_t*)dest;
	bs = (size_t*)s;
	n = ft_n_process(s, n);
	i = 0;
	while (i < n / sizeof(size_t))
	{
		bdest[i] = bs[i];
		i++;
	}
	i = 0;
	dest = dest + n - n % sizeof(size_t);
	s = s + n - n % sizeof(size_t);
	while (i < n % sizeof(size_t))
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (r);
}
