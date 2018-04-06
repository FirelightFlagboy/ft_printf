/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:28:21 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 14:48:56 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf_header.h"

int		ft_call_fillcolor(va_list *ap, t_flags *f)
{
	int		index;
	(void)f;
	(void)ap;
	index = (int)va_arg(*ap, int);
	if (index < 0 || index > COLOR_TAB)
		return (0);
	return (0);
}
