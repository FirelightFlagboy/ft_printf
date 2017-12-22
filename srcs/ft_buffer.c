/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:26:31 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 15:21:26 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbuffer(void)
{
	t_buff *buff;

	buff = get_buff();
	buff->res += write(buff->fd, buff->buffer, buff->index);
	buff->index = 0;
}

int		ft_add_char_to_buff(int c)
{
	t_buff *buff;

	buff = get_buff();
	if (buff->index + 1 >= BUFF_SIZE)
		ft_putbuffer();
	buff->buffer[buff->index++] = c;
	return (buff->index);
}

int		ft_add_nchar_to_buff(int c, size_t n)
{
	t_buff *buff;

	buff = get_buff();
	if (n + buff->index < BUFF_SIZE)
	{
		while (n > 0)
		{
			buff->buffer[buff->index++] = c;
			n--;
		}
		return(buff->index);
	}
	while (buff->index < BUFF_SIZE)
	{
		buff->buffer[buff->index++] = c;
		n--;
	}
	ft_putbuffer();
	while (n > 0)
	{
		buff->buffer[buff->index++] = c;
		n--;
	}
	return (buff->index);
}

int		ft_add_str_to_buff(char const *s)
{
	t_buff	*buff;
	size_t	len;
	size_t	i;

	buff = get_buff();
	len = ft_strlen(s);
	if (buff->index + len >= BUFF_SIZE)
		ft_putbuffer();
	i = 0;
	while (i < len)
	{
		buff->buffer[i] = *s++;
		i++;
	}
	buff->index += i;
	return (buff->index);
}

int		ft_add_nstr_to_buff(char const *s, size_t n)
{
	t_buff	*buff;
	size_t	len;
	size_t	i;

	buff = get_buff();
	len = ft_strlen(s);
	if (len > n)
		len = n;
	if (buff->index + len >= BUFF_SIZE)
		ft_putbuffer();
	i = 0;
	while (i < len)
	{
		buff->buffer[i] = *s++;
		i++;
	}
	buff->index += i;
	return (buff->index);
}
