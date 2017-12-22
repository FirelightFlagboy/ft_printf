/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:26:31 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 12:53:30 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbuffer(int fd)
{
	g_buff.res = write(fd, g_buff.buffer, g_buff.index);
	g_buff.index = 0;
}

int		ft_add_char_to_buff(char c, int fd)
{
	if (g_buff.index + 1 >= BUFF_SIZE)
		ft_putbuffer(fd);
	g_buff.buffer[g_buff.index++] = c;
	return (g_buff.index);
}

int		ft_add_str_to_buff(char *s, int fd)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	if (g_buff.index + len >= BUFF_SIZE)
		ft_putbuffer(fd);
	i = 0;
	while (i < len)
	{
		g_buff.buffer[i] = *s++;
		i++;
	}
	g_buff.index += i;
	return (g_buff.index);
}

int		ft_add_nstr_to_buff(char *s, size_t n, int fd)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	if (len > n)
		len = n;
	if (g_buff.index + len >= BUFF_SIZE)
		ft_putbuffer(fd);
	i = 0;
	while (i < len)
	{
		g_buff.buffer[i] = *s++;
		i++;
	}
	g_buff.index += i;
	return (g_buff.index);
}
