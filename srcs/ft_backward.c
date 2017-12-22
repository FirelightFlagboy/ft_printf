/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backward.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:55:09 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 16:00:16 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fillbackward(t_flags f, char neg, int len)
{
	int	l;

	if (!f.have_buff_size || f.have_minus == 0)
		return (0);
	f.buff_size -= (neg || ((f.have_add || f.have_escape) && !neg)) ? 1 : 0;
	if (f.buff_size < len)
		return (0);
	l = f.buff_size - len;
	ft_add_nchar_to_buff(' ', l);
	return (l);
}
