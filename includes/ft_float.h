/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:20:50 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/29 09:32:16 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLOAT_H
# define FT_FLOAT_H

# include <math.h>
# include <float.h>
# include "ft_printf_typedef.h"

double	ft_pow(double d, int p);
int		ft_len_double(double r, double v, int pre);
int		ft_fillforward_float(t_flags *f, int neg, int len);
int		ft_isnan_or_inf(double d, t_flags *f);
#endif
