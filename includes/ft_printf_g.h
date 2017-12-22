/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_g.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:02:39 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 12:53:03 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_G_H
# define FT_PRINTF_G_H

# include "ft_printf_typedef.h"

t_buff g_buff;
t_type g_type[] = {
	{'%', NULL},
	{'i', NULL},
	{'d', NULL},
	{'D', NULL},
	{'u', NULL},
	{'U', NULL},
	{'o', NULL},
	{'O', NULL},
	{'x', NULL},
	{'X', NULL},
	{'p', NULL},
	{'c', NULL},
	{'C', NULL},
	{'s', NULL},
	{'S', NULL},
	{'b', NULL}
};

#endif
