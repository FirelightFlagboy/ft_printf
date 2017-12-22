/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:34:31 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 12:17:36 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_D_H
# define FT_PRINTF_D_H
/*
** Header that contains all perso define
*/
# ifndef NB_FC
#  define NB_FC 15
# endif

# ifndef EOF
#  define EOF "\\033[0m"
# endif

# ifndef RED
#  define RED "\\033[31m"
# endif

# ifndef GREEN
#  define GREEN "\\033[32m"
# endif

# ifndef YELLOW
#  define YELLOW "\\033[33m"
# endif

# ifndef BLUE
#  define BLUE "\\033[34m"
# endif

# ifndef MAJENTA
#  define MAJENTA "\\033[35m"
# endif

# ifndef CYAN
#  define CYAN "\\033[36m"
# endif

# ifndef BUFF_SIZE
#  define BUFF_SIZE 4096
# endif

#endif
