/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_typedef.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:19:43 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 16:00:15 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPEDEF_H
# define FT_PRINTF_TYPEDEF_H

# include "ft_printf_d.h"
# include <string.h>
# include <stdarg.h>

typedef struct	s_ite
{
	size_t		i;
	size_t		nbyte;
	size_t		len;
	size_t		max_len;
	int			res;
	int			index;
}				t_ite;

typedef struct	s_data
{
	int			fd;
	int			res;
}				t_data;

typedef struct	s_flags
{
	char		error;
	char		have_add;
	char		have_hash;
	char		have_null;
	char		have_minus;
	char		have_escape;
	char		have_p;
	char		have_buff_size;
	char		type;
	char		*len_flags;
	int			precision;
	int			buff_size;
}				t_flags;

typedef struct	s_type
{
	char		charset;
	int			(*f)(va_list*, t_flags);
}				t_type;

typedef struct	s_buff
{
	char		buffer[BUFF_SIZE];
	size_t		index;
	size_t		res;
	int			fd;
}				t_buff;

#endif
