/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:30:05 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/28 13:35:21 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>

/*
** Printf
*/
int			ft_printf(char const *s, ...);
int			ft_eprintf(char const *s, ...);
int			ft_dprintf(int fd, char const *s, ...);
int			ft_fprintf(FILE *stream, char const *s, ...);
int			ft_vfprintf(FILE *stream, char const *s, va_list ap);
int			ft_vdprintf(int fd, char const *s, va_list ap);
#endif
