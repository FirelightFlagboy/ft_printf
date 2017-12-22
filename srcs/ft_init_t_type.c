/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:54:56 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 14:53:51 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_tab_charset(void *data_type)
{
	t_type *t;

	t = data_type;
	t[0].charset = '%';
	t[1].charset = 's';
	t[2].charset = 'S';
	t[3].charset = 'p';
	t[4].charset = 'd';
	t[5].charset = 'D';
	t[6].charset = 'i';
	t[7].charset = 'o';
	t[8].charset = 'O';
	t[9].charset = 'u';
	t[10].charset = 'U';
	t[11].charset = 'x';
	t[12].charset = 'X';
	t[13].charset = 'c';
	t[14].charset = 'C';
	t[15].charset = 'b';
	t[16].charset = '\0';
}

void	ft_tab_fc(void	*data_type)
{
	t_type *t;

	t = data_type;
	t[0].f = ft_pourcent;
	/*
	t[0].f = ;
	t[1].f = ;
	t[2].f = ;
	t[3].f = ;
	t[4].f = ;
	t[5].f = ;
	t[6].f = ;
	t[7].f = ;
	t[8].f = ;
	t[9].f = ;
	t[10].f = ;
	t[11].f = ;
	t[12].f = ;
	t[13].f = ;
	t[14].f = ;*/
}

t_type		*ft_init_t_type(void)
{
	t_type *t;

	if (!(t = (t_type*)malloc((NB_FC + 1) * sizeof(t_type))))
		return (NULL);
	t[NB_FC].charset = 0;
	ft_tab_charset(&t);
	ft_tab_fc(&t);
	return (t);
}
