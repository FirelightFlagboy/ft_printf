/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singleton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:53:25 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 14:39:37 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buff	*get_buff(void)
{
	static t_buff buff;

	return (&buff);
}

t_type	*get_t_type(void)
{
	static t_type type[NB_FC + 1];

	if (type[0].f == NULL)
	{
		ft_tab_charset((void*)&type);
		ft_tab_fc((void*)&type);
	}
	return (type);
}
