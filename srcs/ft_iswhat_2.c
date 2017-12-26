/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhat_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:56:44 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/26 12:08:51 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isatt_flags(int c)
{
	return (c == '#' || c == '-' || c == '0' || c == ' ' || c == '+');
}

int		ft_isspecifier(int c)
{
	char	*charset;
	short	i;

	charset = "sSpdDioOuUxXcCbBn";
	i = 0;
	while (charset[i] && charset[i] != c)
		i++;
	if (charset[i] == c)
		return (1);
	return (0);
}
