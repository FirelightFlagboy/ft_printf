/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singleton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:53:25 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/26 10:49:38 by fbenneto         ###   ########.fr       */
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

t_color	*get_color(void)
{
	static	t_color tab[NB_COLOR + 1];

	if (tab[0].color_name == NULL)
	{
		ft_init_color_name((void*)&tab);
		ft_init_color_str((void*)&tab);
	}
	return (tab);
}
