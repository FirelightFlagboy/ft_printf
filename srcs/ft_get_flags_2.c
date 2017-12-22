/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:55:51 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 12:58:43 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_get_precision(char **astr, t_flags *f)
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
	{
		res = (res * 10) + (*s - '0');
		s++;
	}
	f->precision = res;
	*astr = s;
	return (res);
}

int			ft_get_buff_size(char **astr, t_flags *f)
{
	int		res;
	char	*s;

	s = *astr;
	res = 0;
	while (*s && ft_isdigit(*s))
	{
		res = (res * 10) + (*s - '0');
		s++;
	}
	f->have_buff_size = (res != 0) ? 1 : 0;
	f->buff_size = res;
	*astr = s;
	return (res);
}

t_flags		ft_get_len_flags(char **astr, t_flags *f)
{
	char	*s;
	char	tmp[4];
	size_t	i;
	size_t	flags_len;

	s = *astr;
	i = 0;
	flags_len = 0;
	while (s[flags_len] && ft_islen_flags(s[flags_len]))
		flags_len++;
	while (i < flags_len && i < 3)
	{
		tmp[i] = *s;
		i++;
		s++;
	}
	tmp[i] = 0;
	f->len_flags = tmp;
	*astr = s;
	return (*f);
}
