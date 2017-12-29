/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 12:05:14 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/29 09:54:58 by fbenneto         ###   ########.fr       */
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
	printf("0 - |%*d|\n", 5, 3);
	printf("1 - |%.*d|\n", 5, 3);
	printf("2 - |%*.*d|\n", 10, 5, 3);
	printf("3 - |%5*d|\n", 10, 3);
	printf("4 - |%*5d|\n", 10, 3);
	printf("5 - |%.5*d|\n", 10, 3);
	printf("6 - |%.*5d|\n", 10, 3);
	printf("7 - |%5*.5*d|\n", 10, 6, 3);
	printf("8 - |%*5.*5d|\n", 10, 6, 3);
	printf("9 - |%**d|\n", 10, 9, 6);
	return (0);
}
