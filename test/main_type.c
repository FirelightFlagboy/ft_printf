/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:38:07 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 14:46:17 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	t_type	*t;
	t_type	*p;
	int		i;

	t = get_t_type();
	i = 0;
	while (t[i].charset)
		printf("%c", t[i++].charset);
	printf("\n");
	p = get_t_type();
	i = 0;
	while (p[i].charset)
		printf("%c", p[i++].charset);
	return (0);
}
