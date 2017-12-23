/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:04:33 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 14:41:11 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_len_nb(uintmax_t n, size_t lenbase)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= lenbase;
		len++;
	}
	return (len);
}

int			ft_itoa(uintmax_t n)
{
	char	s[20];
	int		lennb;

	lennb = ft_len_nb(n, 10);
	s[lennb] = 0;
	lennb--;
	while (lennb >= 0)
	{
		s[lennb] = (n % 10) + '0';
		n /= 10;
		lennb--;
	}
	return (ft_add_str_to_buff(s));
}

int			ft_itoa_base(uintmax_t n, char *base)
{
	char		s[65];
	int			len_base;
	int			lennb;
	t_buff		*buff;

	buff = get_buff();
	len_base = ft_strlen(base);
	lennb = ft_len_nb(n, len_base);
	s[lennb] = 0;
	lennb--;
	while (lennb >= 0)
	{
		s[lennb] = base[n % len_base];
		n /= len_base;
		lennb--;
	}
	return (ft_add_str_to_buff(s));
}
