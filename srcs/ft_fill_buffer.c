/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:16:05 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/24 09:12:04 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putgen(t_flags f, char const *s)
{
	if (f.have_buff_size && f.have_minus == 0)
	{
		if (f.have_null)
			ft_add_nchar_to_buff('0', f.buff_size - 1);
		else
			ft_add_nchar_to_buff(' ', f.buff_size - 1);
	}
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

	f = ft_get_flags((char**)&s, ap);
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
	if (*s)
		return ((char*)s + 1);
	return ((char*)s);
}

char	*ft_putcolor(char const *s)
{
	t_color	*c;
	int		i;

	i = 0;
	c = get_color();
	while (c[i].color_name)
	{
		if (ft_strncmp(s, c[i].color_name, ft_strlen(c[i].color_name)) == 0)
		{
			ft_add_str_to_buff(c[i].color_str);
			return (ft_strchr(s, '}') + 1);
		}
		i++;
	}
	ft_add_char_to_buff('{');
	return ((char*)s + 1);
}

int		ft_fill_buffer(char const *s, va_list ap)
{
	t_buff	*buff;
	char	*p;
	size_t	len;
	t_type	*type;
	va_list	node;

	buff = get_buff();
	va_copy(node, ap);
	type = get_t_type();
	while (*s != '\0')
	{
		p = ft_strchr(s, '%');
		len = (p) ? p - s : ft_strlen(s);
		ft_add_nstr_to_buff(s, len);
		s += len;
		if (*s)
			s = ft_call_fc(s, &node, type);
		if (!s)
			return (-1);
		if (*s)
			s++;
	}
	va_end(node);
	return (0);
}

int		ft_fill_buffer_color(char const *s, va_list ap)
{
	t_buff	*buff;
	va_list	node;
	t_type	*type;

	buff = get_buff();
	type = get_t_type();
	va_copy(node, ap);
	while (*s != '\0')
	{
		if (*s == '{')
		{
			s = ft_putcolor(s);
			continue;
		}
		else if (*s == '%')
			s = ft_call_fc(s, &node, type);
		else
			ft_add_char_to_buff(*s);
		s++;
	}
	va_end(node);
	return (0);
}
