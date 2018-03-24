/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:23:55 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/24 15:31:33 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		i;

	i = 5;
	dprintf(9, "\e[1;1H");
	dprintf(9, "\e[2J");
	dprintf(9, "\e[3J");
	ft_printf("%%\n");
	printf("%%\n");
	ft_printf("%x\n", 42);
	printf("%x\n", 42);
	ft_printf("|%-5%|\n");
	printf("|%-5%|\n");
	ft_printf("|%-10x|\n", 42);
	printf("|%-10x|\n", 42);
	ft_printf("|%010x|\n", 542);
	printf("|%010x|\n", 542);
	ft_printf("|%s|\n", "abc");
	printf("|%s|\n", "abc");
	ft_printf("|%5c|\n", 42);
	printf("|%5c|\n", 42);
	ft_printf("|%5o|\n", 41);
	printf("|%5o|\n", 41);
	ft_printf("|%#6o|\n", 2500);
	printf("|%#6o|\n", 2500);
	ft_printf("|%o|\n", 0);
	printf("|%o|\n", 0);
	ft_printf("|%0d|\n", -42);
	printf("|%0d|\n", -42);
	ft_printf("|%00d|\n", -42);
	printf("|%00d|\n", -42);
	ft_printf("|%0+5d|\n", 42);
	printf("|%0+5d|\n", 42);
	ft_printf("|%05d|\n", -42);
	printf("|%05d|\n", -42);
	ft_printf("|%p|\n", &i);
	printf("|%p|\n", &i);
	return (0);
}
