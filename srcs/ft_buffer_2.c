/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:12:19 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 16:14:26 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fill_ox(char type)
{
	ft_add_char_to_buff('0');
	if (type == 'x' || type == 'X' || type == 'b')
	{
		ft_add_char_to_buff(type);
		return (2);
	}
	return (1);
}
