/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:54:56 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/23 10:29:18 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_tab_charset(void *data_type)
{
	t_type *t;

	t = data_type;
	t[0].charset = 's';
	t[1].charset = 'S';
	t[2].charset = 'p';
	t[3].charset = 'd';
	t[4].charset = 'D';
	t[5].charset = 'i';
	t[6].charset = 'o';
	t[7].charset = 'O';
	t[8].charset = 'u';
	t[9].charset = 'U';
	t[10].charset = 'x';
	t[11].charset = 'X';
	t[12].charset = 'c';
	t[13].charset = 'C';
	t[14].charset = 'b';
	t[15].charset = 'B';
	t[16].charset = '\0';
}

void	ft_tab_fc(void	*data_type)
{
	t_type *t;

	t = data_type;
	t[0].f = ft_call_fillstr;
	t[1].f = ft_call_fillstr;
	t[2].f = ft_call_filladr;
	t[3].f = ft_call_fillnbr;
	t[4].f = ft_call_fillnbr;
	t[5].f = ft_call_fillnbr;
	t[6].f = ft_call_filloctal;
	t[7].f = ft_call_filloctal;
	t[8].f = ft_call_fillunbr;
	t[9].f = ft_call_fillunbr;
	t[10].f = ft_call_fillhex;
	t[11].f = ft_call_fillhex;
	t[12].f = ft_call_fillchar;
	t[13].f = ft_call_fillchar;
	t[14].f = ft_call_fillbin;
	t[15].f = ft_call_fillbin;
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
