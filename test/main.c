/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 12:05:14 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/27 12:07:05 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int i = 1;

	ft_printf("begin test\n");
	ft_printf("%d", 123456789);
	while (i < argc)
	{
		ft_printf("%20s]\n", argv[i]);
		i++;
	}
	ft_printf("done\n");
	return (0);
}
