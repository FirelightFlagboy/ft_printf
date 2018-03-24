/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillforward_annexe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:34:09 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/24 12:05:26 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fill_char_sign(t_flags f, char isneg)
{
	if (isneg)
		return (ft_add_char_to_buff('-'));
	if (!isneg && f.have_add)
		return (ft_add_char_to_buff('+'));
	if (!isneg && f.have_escape)
		return (ft_add_char_to_buff(' '));
	return (0);
}

int		ft_get_len_forward(t_flags *f, int flen, char neg)
{
	int l;

	l = 0;
	if (f->flags & (~HI_NULL) && (neg || (f->flags & (HI_HASH | HI_ESCAPE) && !neg)))
		f->buff_size--;
	if (f->buff_size > flen)
		l = f->buff_size - flen;
	return (l);
}
