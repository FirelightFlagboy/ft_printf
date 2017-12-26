/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_header_fc.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:17:17 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/26 14:45:54 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HEADER_FC_H
# define FT_PRINTF_HEADER_FC_H

# include <stdarg.h>
# include <stdint.h>
# include "ft_printf_typedef.h"

/*
** %d %D %i
*/
int		ft_call_fillnbr(va_list *ap, t_flags f);
/*
** %u %U
*/
int		ft_call_fillunbr(va_list *ap, t_flags f);
/*
** %x %X
*/
int		ft_call_fillhex(va_list *ap, t_flags f);
/*
** %o %O
*/
int		ft_call_filloctal(va_list *ap, t_flags f);
/*
** %b %B
*/
int		ft_call_fillbin(va_list *ap, t_flags f);
/*
** %c %C
*/
int		ft_call_fillchar(va_list *ap, t_flags f);
int		ft_call_fill_longchar(va_list *ap, t_flags f);
/*
** %s %S
*/
int		ft_call_fillstr(va_list *ap, t_flags f);
int		ft_call_fill_longstr(va_list *ap, t_flags f);
/*
** %p
*/
int		ft_call_filladr(va_list *ap, t_flags f);
#endif
