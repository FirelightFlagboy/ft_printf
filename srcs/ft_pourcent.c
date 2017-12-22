/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:45:10 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 14:46:09 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pourcent(va_list *ap, t_flags f)
{
	ft_add_char_to_buff('%');
	(void)ap;
	(void)f;
	return (1);
}
