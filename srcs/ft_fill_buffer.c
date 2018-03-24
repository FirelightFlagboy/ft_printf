/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:16:05 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/24 14:10:40 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_global.h"

char	*ft_putgen(t_flags f, char const *s)
{
	if (f.flags & HI_BUFF_SIZE && f.flags & ~HI_MINUS)
	{
		if (f.flags & HI_NULL)
			ft_add_nchar_to_buff('0', f.buff_size - 1);
		else
			ft_add_nchar_to_buff(' ', f.buff_size - 1);
	}
	if (*s)
		ft_add_char_to_buff(*s);
	if (f.flags & HI_BUFF_SIZE && f.flags & HI_MINUS)
		ft_add_nchar_to_buff(' ', f.buff_size - 1);
	return ((*s) ? (char*)s++ : (char*)s);
}

char	*ft_call_fc_g(char const *s, va_list *ap)
{
	t_flags f;
	int		i;

	f = ft_get_flags((char**)&s, ap);
	i = 120 - f.type;
	if (i >= 0 && i <= 54 && g_conv[i])
	{
		if (g_conv[i](ap, f) == -1)
			return (NULL);
		return ((char*)s);
	}
	return (ft_putgen(f, s));
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
	va_list	node;

	buff = get_buff();
	va_copy(node, ap);
	while (*s != '\0')
	{
		p = ft_strchr(s, '%');
		len = (p) ? p - s : ft_strlen(s);
		ft_add_nstr_to_buff(s, len);
		s += len;
		if (*s)
			s = ft_call_fc_g(s, &node);
		if (!s)
			return (-1);
		if (*s == 0)
			break ;
		s++;
	}
	va_end(node);
	return (0);
}

int		ft_fill_buffer_color(char const *s, va_list ap)
{
	t_buff	*buff;
	va_list	node;

	buff = get_buff();
	va_copy(node, ap);
	while (*s != '\0')
	{
		if (*s == '{')
		{
			s = ft_putcolor(s);
			continue;
		}
		else if (*s == '%')
			s = ft_call_fc_g(s, &node);
		else
			ft_add_char_to_buff(*s);
		s++;
	}
	va_end(node);
	return (0);
}
