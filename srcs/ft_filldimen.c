/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filldimen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:52:57 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 09:16:17 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_filldimen(t_flags f, char isneg, int len)
{
	int l;

	if ((isneg && (f.have_minus || !(f.have_buff_size && f.have_null)))\
	|| (!isneg && !(f.have_buff_size && f.have_null)\
		&& (f.have_add || f.have_escape)))
		ft_fill_char_sign(f, isneg);
	l = 0;
	if (f.precision > len)
		l += f.precision - len;
	if (l == 0)
		return (0);
	ft_add_nchar_to_buff('0', l);
	return (l);
}

int		ft_filldimen_hex(t_flags f, int len)
{
	int	l;

	l = 0;
	if (f.have_hash && !((!f.have_minus && f.have_null) && f.have_buff_size))
		ft_fill_ox(f.type);
	if (f.precision > len)
		l += f.precision - len;
	ft_add_nchar_to_buff('0', l);
	return (l);
}

int		ft_filldimen_oct(t_flags f, int len)
{
	int	l;

	l = 0;
	if (f.have_hash && (!f.have_null && f.have_buff_size))
	{
		f.precision--;
		ft_fill_ox(f.type);
	}
	if (f.precision > len)
		l += f.precision - len;
	ft_add_nchar_to_buff('0', l);
	return (l);
}

int		ft_filldimen_uin(t_flags f, int len)
{
	int	l;

	if (f.precision < len)
		return (0);
	l = f.precision - len;
	ft_add_nchar_to_buff('0', l);
	return (l);
}
