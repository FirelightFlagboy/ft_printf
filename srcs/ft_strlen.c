/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:36:09 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 11:18:45 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_unicode(wchar_t n)
{
	int	l;

	l = -1;
	if (n >= 0 && n < 0x80)
		l = 1;
	else if (n < 0x800)
		l = 2;
	else if (n < 0x10000)
		l = 3;
	else if (n < 0x200000)
		l = 4;
	if (l <= MB_CUR_MAX)
		return (l);
	return (-1);
}

size_t		ft_strlen(char const *s)
{
	char	*save;

	save = (char*)s;
	while (*save)
		save++;
	return (save - s);
}

int		ft_get_finale_len(wchar_t *s, t_flags f)
{
	int len;
	int l;

	len = 0;
	while (*s)
	{
		l = ft_len_unicode(*s);
		if (l == -1)
			return (-1);
		if (f.have_p && len + l > f.precision)
			break ;
		len += l;
		s++;
	}
	return (len);
}
