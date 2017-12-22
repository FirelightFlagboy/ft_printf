/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:26:31 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 12:37:08 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbuffer(int fd)
{
	gl_buff.res = write(fd, gl_buff.buffer, gl_buff.index);
	gl_buff.index = 0;
}

int		ft_add_char_to_buff(char c, int fd)
{
	if (gl_buff.index + 1 >= BUFF_SIZE)
		ft_putbuffer(fd);
	gl_buff.buffer[gl_buff.index++] = c;
	return (gl_buff.index);
}

int		ft_add_str_to_buff(char *s, int fd)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	if (gl_buff.index + len >= BUFF_SIZE)
		ft_putbuffer(fd);
	i = 0;
	while (i < len)
	{
		gl_buff.buffer[i] = *s++;
		i++;
	}
	gl_buff.index += i;
	return (gl_buff.index);
}
