/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:55:51 by fbenneto          #+#    #+#             */
/*   Updated: 2018/01/09 16:24:09 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_get_precision(char **astr, t_flags *f, va_list *ap)
{
	int		res;
	char	*s;

	s = *astr;
	res = 0;
	if (*s != '.')
		return (0);
	f->have_p = 1;
	s++;
	while (*s && ft_isdigit(*s))
		res = (res * 10) + (*s++ - '0');
	if (*s == '*')
	{
		res = (int)va_arg(*ap, int);
		s++;
		if (ft_isdigit(*s))
			res = 0;
		while (*s && ft_isdigit(*s))
			res = (res * 10) + (*s++ - '0');
	}
	f->precision = res;
	*astr = s;
	return (res);
}

int			ft_get_buff_size(char **astr, t_flags *f, va_list *ap)
{
	int		res;
	char	*s;

	s = *astr;
	res = 0;
	while (*s && ft_isdigit(*s))
		res = (res * 10) + (*s++ - '0');
	if (*s == '*')
	{
		res = (int)va_arg(*ap, int);
		if (s++ != 0 && ft_isdigit(*s))
			res = 0;
		while (*s && ft_isdigit(*s))
			res = (res * 10) + (*s++ - '0');
	}
	if (res != 0)
		f->have_buff_size = 1;
	if (res > 0)
		f->buff_size = res;
	else
		f->buff_size = -res;
	if (res < 0)
		f->have_minus = 1;
	*astr = s;
	return (res);
}

t_flags		ft_get_len_flags(char **astr, t_flags *f)
{
	char	*s;
	size_t	i;
	size_t	flags_len;

	s = *astr;
	i = 0;
	flags_len = 0;
	while (s[flags_len] && ft_islen_flags(s[flags_len]))
		flags_len++;
	while (i < flags_len && i < 3)
	{
		f->len_flags[i] = *s;
		i++;
		s++;
	}
	f->len_flags[i] = 0;
	*astr = s;
	return (*f);
}
