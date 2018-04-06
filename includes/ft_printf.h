/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:30:05 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 14:43:21 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdio.h>

enum e_color
{
	P_NO_COLOR,
	P_RED,
	P_CYAN,
	P_GREEN,
	P_BLUE,
	P_MAGENTA,
	P_WHITE,
	P_BLACK,
	P_BOLD,
	P_DIM,
	P_UNDERLINE,
	P_BLINK,
	P_INVERTED,
	P_HIDDEN,
	P_BACK_RED,
	P_BACK_YELLOW,
	P_BACK_BLUE,
	P_BACK_PURPLE,
	P_BACK_CYAN,
	P_BACK_WHITE
};
/*
** Printf display
*/
int			ft_printf(char const *format, ...);
int			ft_eprintf(char const *format, ...);
int			ft_dprintf(int fd, char const *format, ...);
int			ft_fprintf(FILE *stream, char const *format, ...);
/*
** Printf string
*/
int			ft_sprintf(char *s, char *format, ...);
int			ft_snprintf(char *s, size_t n, char *format, ...);
int			ft_asprintf(char **as, char *format, ...);
/*
** vprintf display
*/
int			ft_vfprintf(FILE *stream, char const *format, va_list ap);
int			ft_vdprintf(int fd, char const *format, va_list ap);
/*
** vprintf string
*/
int			ft_vsprintf(char *s, char *format, va_list ap);
int			ft_vsnprintf(char *s, size_t n, char *format, va_list ap);
int			ft_vasprintf(char **as, char *format, va_list ap);
#endif
