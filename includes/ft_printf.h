/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:51:32 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 12:36:02 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <wchar.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "ft_printf_typedef.h"
# include "ft_printf_header_fc.h"
# include "ft_printf_d.h"
# include "ft_printf_g.h"

/*
** Printf
*/
int		ft_printf(char const *s, ...);
int		ft_dprintf(int fd, char const *s, ...);
int		ft_vfprintf(int fd, char const *s, va_list ap);
/*
** Classic libft
*/
size_t	ft_strlen(char const *s);
#endif
