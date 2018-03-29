/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:19:54 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/29 09:34:42 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"
#include "ft_float.h"

double	ft_pow(double d, int p)
{
	double r;

	r = 1;
	while (p)
	{
		r *= d;
		p--;
	}
	return (r);
}

int	ft_len_double(double r, double v, int pre)
{
	int		l;
	int		i;

	l = 0;
	i = 0;
	v = v * ft_pow(10, pre);
	while (v > ft_pow(10, i) || i < pre)
	{
		l++;
		i++;
	}
	if (pre > 0)
		l++;
	i = 0;
	if (r < ft_pow(10, i))
		l++;
	while (r > ft_pow(10, i++))
		l++;
	return (l);
}

int		ft_isnan_or_inf(double d, t_flags *f)
{
	(void)f;
	if (isnan(d))
	{
		return (ft_add_str_to_buff("NaN"));
	}
	if (isinf(d))
	{
		if (d < 0.0)
			return (ft_add_str_to_buff("-inf"));
		return (ft_add_str_to_buff("inf"));
	}
	return (0);
}
