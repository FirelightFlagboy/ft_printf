/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:54:54 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 13:08:40 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_init_t_flags(void)
{
	t_flags f;

	f.error = 0;
	f.have_add = 0;
	f.have_hash = 0;
	f.have_null = 0;
	f.have_minus = 0;
	f.have_escape = 0;
	f.len_flags = NULL;
	f.have_buff_size = 0;
	f.have_p = 0;
	f.buff_size = 0;
	f.precision = 0;
	return (f);
}

t_flags		ft_get_att(char **astr, t_flags *f)
{
	char	*s;

	s = *astr;
	while (ft_isatt_flags(*s))
	{
		if (*s == '#')
			f->have_hash = 1;
		else if (*s == ' ')
			f->have_escape = 1;
		else if (*s == '-')
			f->have_minus = 1;
		else if (*s == '+')
			f->have_add = 1;
		else if (*s == '0')
			f->have_null = 1;
		s++;
	}
	*astr = s;
	return (*f);
}

t_flags		ft_get_flags(char **astr)
{
	t_flags	f;
	char	*s;

	s = *astr;
	s++;
	f = ft_init_t_flags();
	ft_get_att(&s, &f);
	ft_get_buff_size(&s, &f);
	ft_get_precision(&s, &f);
	ft_get_len_flags(&s, &f);
	ft_get_att(&s, &f);
	f.type = *s;
	*astr = s;
	return (f);
}
