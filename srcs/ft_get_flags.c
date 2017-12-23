/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:54:54 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 12:06:11 by fbenneto         ###   ########.fr       */
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

void	tmp(t_flags f)
{
	dprintf(2, "\n============================\n");
	dprintf(2, "%-16s:%3d\n", "error", f.error);
	dprintf(2, "%-16s:%3d\n", "have_add", f.have_add);
	dprintf(2, "%-16s:%3d\n", "have_hash", f.have_hash);
	dprintf(2, "%-16s:%3d\n", "have_null", f.have_null);
	dprintf(2, "%-16s:%3d\n", "have_minus", f.have_minus);
	dprintf(2, "%-16s:%3d\n", "have_escape", f.have_escape);
	dprintf(2, "%-16s:%3d\n", "have_p", f.have_p);
	dprintf(2, "%-16s:%3d\n", "have_buff_size", f.have_buff_size);
	dprintf(2, "%-16s:%3c\n", "type", f.type);
	dprintf(2, "%-16s:%s\n", "len_flags", f.len_flags);
	dprintf(2, "%-16s:%3d\n", "precision", f.precision);
	dprintf(2, "%-16s:%3d\n", "buff_size", f.buff_size);
	dprintf(2, "============================\n");
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
	tmp(f);
	f.type = *s;
	*astr = s;
	return (f);
}
