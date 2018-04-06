/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:28:21 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 15:09:22 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_call_fillcolor(va_list *ap, t_flags *f)
{
	int			index;
	const char	*tab[NB_COLOR + 1] = {"\x1b[0m", "\x1b[31m", "\x1b[36m",
	"\x1b[32m", "\x1b[33m", "\x1b[34m", "\x1b[35m", "\x1b[37m", "\x1b[30m",
	"\x1b[1m", "\x1b[2m", "\x1b[4m", "\x1b[5m", "\x1b[7m", "\x1b[8m",
	"\x1b[41m", "\x1b[42m", "\x1b[43m", "\x1b[44m", "\x1b[45m", "\x1b[46m",
	"\x1b[47m"};

	(void)f;
	index = (int)va_arg(*ap, int);
	if (index < 0 || index > NB_COLOR)
		return (0);
	ft_add_str_to_buff(tab[index]);
	return (0);
}
