/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillforward.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:53:06 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 16:39:56 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fillforward(t_flags f, char isneg, int len)
{
	int	l;

	l = ft_get_len_forward(&f, len, isneg);
	if (l == 0)
		return (0);
	if (f.have_null && (isneg || ((f.have_add || f.have_escape) && !isneg)))
		ft_fill_char_sign(f, isneg);
	ft_add_nchar_to_buff((f.have_null) ? '0' : ' ', l);
	return (l);
}

int		ft_fillforward_hex(t_flags f, int len)
{
	int	l;

	l = 0;
	if (!f.have_buff_size || f.have_minus == 1)
		return (0);
	if (f.have_hash && f.have_null)
		ft_fill_ox(f.type);
	if (f.buff_size > len)
		l += f.buff_size - len;
	ft_add_nchar_to_buff((f.have_null) ? '0' : ' ', l);
	return (l);
}

int		ft_fillforward_uin(t_flags f, int len)
{
	int	l;

	l = 0;
	if (f.buff_size < len)
		return (0);
	l += f.buff_size - len;
	ft_add_nchar_to_buff((f.have_null) ? '0' : ' ', l);
	return (l);
}

int		ft_fillforward_oct(t_flags f, int len)
{
	int l;

	if (f.buff_size < len)
		return (0);
	l = 0;
	if (f.have_null && f.have_hash)
		l++;
	l += f.buff_size - len;
	ft_add_nchar_to_buff((f.have_null) ? '0' : ' ', l);
	return (l);
}
