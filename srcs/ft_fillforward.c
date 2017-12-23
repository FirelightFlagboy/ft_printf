/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillforward.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:53:06 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 15:54:11 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fillforward(t_flags f, char isneg, int len)
{
	int	l;

	if (!f.have_buff_size || f.have_minus == 1)
		return (0);
	l = ft_get_len_forward(&f, len, isneg);
	if (f.have_null && (isneg || ((f.have_add || f.have_escape) && !isneg)))
		ft_fill_char_sign(f, isneg);
	if (f.have_null)
		ft_add_nchar_to_buff('0', l);
	else
		ft_add_nchar_to_buff(' ', l);
	return (l);
}

int		ft_fillforward_hex(t_flags f, int len)
{
	int	l;

	if (!f.have_buff_size || f.have_minus == 1)
		return (0);
	if (f.have_hash && f.have_null)
		ft_fill_ox(f.type);
	if (f.buff_size < len)
		return (0);
	l = f.buff_size - len;
	if (f.have_null)
		ft_add_nchar_to_buff('0', l);
	else
		ft_add_nchar_to_buff(' ', l);
	return (l);
}

int		ft_fillforward_uin(t_flags f, int len)
{
	int	l;

	if (!f.have_buff_size || f.have_minus == 1)
		return (0);
	if (f.buff_size < len)
		return (0);
	l = f.buff_size - len;
	if (f.have_null)
		ft_add_nchar_to_buff('0', l);
	else
		ft_add_nchar_to_buff(' ', l);
	return (l);
}

int		ft_fillforward_oct(t_flags f, int len)
{
	int l;

	if (!f.have_buff_size || f.have_minus == 1)
		return (0);
	if (f.buff_size < len)
		return (0);
	l = f.buff_size - len + (f.have_null && f.have_hash);
	if (f.have_null)
		ft_add_nchar_to_buff('0', l);
	else
		ft_add_nchar_to_buff(' ', l);
	return (l);
}
