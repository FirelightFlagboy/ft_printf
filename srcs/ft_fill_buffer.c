/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:16:05 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 12:55:10 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putgen(t_flags f, char const *s)
{
	if (f.have_buff_size && f.have_minus == 0)
		ft_add_nchar_to_buff((f.have_null) ? '0' : ' ', f.buff_size - 1);
	if (*s)
		ft_add_char_to_buff(*s);
	if (f.have_buff_size && f.have_minus == 1)
		ft_add_nchar_to_buff(' ', f.buff_size - 1);
	return ((*s) ? (char*)s++ : (char*)s);
}

char	*ft_call_fc(char const *s, va_list *ap, t_type *t)
{
	t_flags f;
	int		i;

	f = ft_get_flags((char**)&s);
	if (!ft_isspecifier(*s))
		return (ft_putgen(f, s));
	i = 0;
	while (t[i].charset)
	{
		if (t[i].charset == f.type)
		{
			if (t[i].f(ap, f) == -1)
				return (NULL);
			return ((char*)s);
		}
		i++;
	}
	return ((char*)s);
}

int		ft_fill_buffer(char const *s, va_list ap)
{
	t_buff	*buff;
	char	*p;
	size_t	len;
	va_list	node;

	buff = get_buff();
	va_copy(node, ap);
	while (*s != '\0')
	{
		p = ft_strchr(s, '%');
		len = (p) ? p - s : ft_strlen(s);
		ft_add_nstr_to_buff(s, len);
		s += len;
		s = (*s) ? ft_call_fc(s, &node, get_t_type()) : s;
		if (!s)
			return (-1);
		if (*s)
			s++;
	}
	va_end(node);
	return (0);
}
