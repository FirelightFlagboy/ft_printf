/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:36:09 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 14:40:52 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_len_unicode(wchar_t n)
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

static size_t	my_ft_strlen_long\
	(const char *str, const unsigned long int *longword_ptr)
{
	unsigned long int longword;
	const char *cp;
	
	while (1)
	{
		longword = *longword_ptr++;
		if (((longword - 0x01010101L) & 0x80808080L))
		{
			cp = (const char *) (longword_ptr - 1);
			if (cp[0] == 0)
				return cp - str;
			if (cp[1] == 0)
				return cp - str + 1;
			if (cp[2] == 0)
				return cp - str + 2;
			if (cp[3] == 0)
				return cp - str + 3;
		}
	}
}

size_t			my_ft_strlen (char const *str)
{
	const char *char_ptr;
	const unsigned long int *longword_ptr;

	char_ptr = str;
	while ((unsigned long int)char_ptr & (sizeof(unsigned long int) - 1))
	{
		if (*char_ptr == '\0')
			return char_ptr - str;
		char_ptr++;
	}
	longword_ptr = (unsigned long int *) char_ptr;
	return (my_ft_strlen_long(str, longword_ptr));
}

int			ft_get_finale_len(wchar_t *s, t_flags f)
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
