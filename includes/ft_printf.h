/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:51:32 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 15:09:04 by fbenneto         ###   ########.fr       */
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

/*
** Printf
*/
int			ft_printf(char const *s, ...);
int			ft_dprintf(int fd, char const *s, ...);
int			ft_vfprintf(int fd, char const *s, va_list ap);
/*
** Classic libft
*/
size_t		ft_strlen(char const *s);
/*
** Buffer fc
*/
void		ft_putbuffer();
int			ft_fill_buffer(char const *s, va_list ap);
int			ft_add_char_to_buff(int c);
int			ft_add_nchar_to_buff(int c, size_t n);
int			ft_add_str_to_buff(char const *s);
int			ft_add_nstr_to_buff(char const *s, size_t n);
/*
** Ft_iswhat
*/
int			ft_isspace(int c);
int			ft_isdigit(int c);
int			ft_islen_flags(int c);
int			ft_isalpha(int c);
int			ft_isdigit_flags(int c);
int			ft_isatt_flags(int c);
int			ft_isspecifier(int c);
/*
** Getter
*/
t_buff		*get_buff(void);
t_type		*get_t_type(void);
t_flags		ft_get_flags(char **astr);
t_flags		ft_get_att(char **astr, t_flags *f);
t_flags		ft_get_len_flags(char **astr, t_flags *f);
int			ft_get_buff_size(char **astr, t_flags *f);
int			ft_get_precision(char **astr, t_flags *f);
/*
** Lib string
*/
char		*ft_strchr(char const *s, int c);
/*
** T_type
*/
t_type		*ft_init_t_type(void);
void		ft_tab_charset(void *data_type);
void		ft_tab_fc(void *data_type);
char		*ft_call_fc(char const *s, va_list *ap, t_type *t);
#endif
