/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_global.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 09:15:37 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/24 16:34:49 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_GLOBAL_H
# define FT_PRINTF_GLOBAL_H

# include <stdlib.h>
# include "ft_printf_header_fc.h"
# include "ft_printf_typedef.h"

int	(*const g_conv[55])(va_list*, t_flags*) =
{
	ft_call_fillhex,
	NULL,
	NULL,
	ft_call_fillunbr,
	NULL,
	ft_call_fillstr,
	NULL,
	NULL,
	ft_call_filladr,
	ft_call_filloctal,
	ft_get_index,
	NULL,
	NULL,
	NULL,
	NULL,
	ft_call_fillnbr,
	NULL,
	NULL,
	NULL,
	NULL,
	ft_call_fillnbr,
	ft_call_fillchar,
	ft_call_fillbin,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	ft_call_fillhex,
	NULL,
	NULL,
	ft_call_fillunbr,
	NULL,
	ft_call_fill_longstr,
	NULL,
	NULL,
	NULL,
	ft_call_filloctal,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	ft_call_fillnbr,
	ft_call_fill_longchar,
	ft_call_fillbin
};
#endif
