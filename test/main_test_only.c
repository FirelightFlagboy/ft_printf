/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_only.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:00:29 by fbenneto          #+#    #+#             */
/*   Updated: 2018/01/16 12:58:19 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <locale.h>
# include <string.h>
# include <wchar.h>

#ifndef NB_TEST
# define NB_TEST 20
#endif

char	*ft_strnew(size_t len)
{
	size_t i = 0;
	char *res;

	if (!(res = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < len)
		res[i++] = '\0';
	return (res);
}

int		*ft_get_tab(void)
{
	int *t;
	int i = NB_TEST;

	if (!(t = (int*)malloc((NB_TEST + 1) * sizeof(int))))
		return (NULL);
	while (i + 1)
		t[i--] = 0;
	return (t);
}

int		ft_test_1(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int i = -1;
	int p = -1;
	int error = 0;
	int nt = 1;

	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - %     %|\n");
	you[++p] =	printf("0 - %     %|\n");
	my[++i] =ft_printf("1 - [ft_printf] |%9.5hhd|\n", 123456);
	you[++p] =	printf("1 - [youprintf] |%9.5hhd|\n", 123456);
	my[++i] =ft_printf("2 - [ft_printf] |%-9.5hhd|\n", 123456);
	you[++p] =	printf("2 - [youprintf] |%-9.5hhd|\n", 123456);
	my[++i] =ft_printf("3 - [ft_printf] |%-9hhd|\n", 123456);
	you[++p] =	printf("3 - [youprintf] |%-9hhd|\n", 123456);
	my[++i] =ft_printf("4 - [ft_printf] |%09hhd|\n", 123456);
	you[++p] =	printf("4 - [youprintf] |%09hhd|\n", 123456);
	my[++i] =ft_printf("5 - [ft_printf] |%-.9hhd|\n", 123456);
	you[++p] =	printf("5 - [youprintf] |%-.9hhd|\n", 123456);
	my[++i] =ft_printf("6 - [ft_printf] |%-5.9hhd|\n", 123456);
	you[++p] =	printf("6 - [youprintf] |%-5.9hhd|\n", 123456);
	my[++i] =ft_printf("7 - [ft_printf] |%-9d|\n", -123);
	you[++p] =	printf("7 - [youprintf] |%-9d|\n", -123);
	my[++i] =ft_printf("8 - [ft_printf] |%D|\n", 9223372036854775807);
	you[++p] =	printf("8 - [youprintf] |%D|\n", 9223372036854775807);
	my[++i] =ft_printf("9 - [ft_printf] |%hhD|\n", 9223372036854775807);
	you[++p] =	printf("9 - [youprintf] |%hhD|\n", 9223372036854775807);
	my[++i] =ft_printf("10 - [ft_printf] |%lD|\n", 9223372036854775807);
	you[++p] =	printf("10 - [youprintf] |%lD|\n", 9223372036854775807);
	my[++i] =ft_printf("11 - [ft_printf] |%D|\n", 9223372036854775807);
	you[++p] =	printf("11 - [youprintf] |%D|\n", 9223372036854775807);
	my[++i] =ft_printf("12 - [ft_printf] |%lD|\n", 9223372036854775807);
	you[++p] =	printf("12 - [youprintf] |%lD|\n", 9223372036854775807);
	my[++i] =ft_printf("13 - [ft_printf] |%llD|\n", 9223372036854775807);
	you[++p] =	printf("13 - [youprintf] |%llD|\n", 9223372036854775807);
	my[++i] =ft_printf("14 - [ft_printf] |%jd|\n", 9223372036854775807);
	you[++p] =	printf("14 - [youprintf] |%jd|\n", 9223372036854775807);
	my[++i] =ft_printf("15 - [ft_printf] |%llD|\n", 9223372036854775807);
	you[++p] =	printf("15 - [youprintf] |%llD|\n", INTMAX_MAX);
	my[++i] =ft_printf("16 - %9k|\n");
	you[++p] =	printf("16 - %9k|\n");
	my[++i] =ft_printf("17 - %09k|%s\n", "bonjour");
	you[++p] =	printf("17 - %09k|%s\n", "bonjour");
	my[++i] =ft_printf("18 - %.5k|\n");
	you[++p] =	printf("18 - %.5k|\n");
	my[++i] =ft_printf("19 - %-9k|\n");
	you[++p] =	printf("19 - %-9k|\n");

	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] =  %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error)	;
}

int		ft_test_2(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int i = -1;
	int p = -1;
	int error = 0;
	int nt = 2;

	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - [ft_printf] |%u|\n", -5);
	you[++p] =	printf("0 - [youprintf] |%u|\n", -5);
	my[++i] =ft_printf("1 - [ft_printf] |%u|\n", 123456789);
	you[++p] =	printf("1 - [youprintf] |%u|\n", 123456789);
	my[++i] =ft_printf("2 - [ft_printf] |%u|\n", UINT32_MAX);
	you[++p] =	printf("2 - [youprintf] |%u|\n", UINT32_MAX);
	my[++i] =ft_printf("3 - [ft_printf] |%U|\n", UINT64_MAX);
	you[++p] =	printf("3 - [youprintf] |%U|\n", UINT64_MAX);
	my[++i] =ft_printf("4 - [ft_printf] |%u|\n", 123456);
	you[++p] =	printf("4 - [youprintf] |%u|\n", 123456);
	my[++i] =ft_printf("5 - [ft_printf] |%9.5u|\n", 123456);
	you[++p] =	printf("5 - [youprintf] |%9.5u|\n", 123456);
	my[++i] =ft_printf("6 - [ft_printf] |%5.9u|\n", 123456);
	you[++p] =	printf("6 - [youprintf] |%5.9u|\n", 123456);
	my[++i] =ft_printf("7 - [ft_printf] |%u|\n", 128);
	you[++p] =	printf("7 - [youprintf] |%u|\n", 128);
	my[++i] =ft_printf("8 - [ft_printf] |%9.5u|\n", 128);
	you[++p] =	printf("8 - [youprintf] |%9.5u|\n", 128);
	my[++i] =ft_printf("9 - [ft_printf] |%5.9u|\n", 128);
	you[++p] =	printf("9 - [youprintf] |%5.9u|\n", 128);
	my[++i] =ft_printf("10 - [ft_printf] |%-5.9u|\n", 128);
	you[++p] =	printf("10 - [youprintf] |%-5.9u|\n", 128);
	my[++i] =ft_printf("11 - [ft_printf] |%-9.5u|\n", 128);
	you[++p] =	printf("11 - [youprintf] |%-9.5u|\n", 128);
	my[++i] =ft_printf("12 - [ft_printf] |%05.9u|\n", 128);
	you[++p] =	printf("12 - [youprintf] |%05.9u|\n", 128);
	my[++i] =ft_printf("13 - [ft_printf] |%09.5u|\n", 128);
	you[++p] =	printf("13 - [youprintf] |%09.5u|\n", 128);
	my[++i] =ft_printf("14 - [ft_printf] |%0-9.5u|\n", 128);
	you[++p] =	printf("14 - [youprintf] |%0-9.5u|\n", 128);
	my[++i] =ft_printf("15 - [ft_printf] |%0-5.9u|\n", 128);
	you[++p] =	printf("15 - [youprintf] |%0-5.9u|\n", 128);
	my[++i] =ft_printf("16 - [ft_printf] |%0-5.9u|\n", 128);
	you[++p] =	printf("16 - [youprintf] |%0-5.9u|\n", 128);
	my[++i] =ft_printf("17 - [ft_printf] |%0-9u|\n", 128);
	you[++p] =	printf("17 - [youprintf] |%0-9u|\n", 128);
	my[++i] =ft_printf("18 - [ft_printf] |%0-.9u|\n", 128);
	you[++p] =	printf("18 - [youprintf] |%0-.9u|\n", 128);
	my[++i] =ft_printf("19 - [ft_printf] |%0-5u|\n", 128);
	you[++p] =	printf("19 - [youprintf] |%0-5u|\n", 128);

	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] =  %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_3(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 3;
	printf("\n");

	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - [ft_printf] |%05d|\n", -123);
	you[++p] =	printf("0 - [youprintf] |%05d|\n", -123);
	my[++i] =ft_printf("1 - [ft_printf] |%-5d|\n", -123);
	you[++p] =	printf("1 - [youprintf] |%-5d|\n", -123);
	my[++i] =ft_printf("2 - [ft_printf] |%.5d|\n", -123);
	you[++p] =	printf("2 - [youprintf] |%.5d|\n", -123);
	my[++i] =ft_printf("3 - [ft_printf] |%9.5d|\n", -123);
	you[++p] =	printf("3 - [youprintf] |%9.5d|\n", -123);
	my[++i] =ft_printf("4 - [ft_printf] |%5.9d|\n", -123);
	you[++p] =	printf("4 - [youprintf] |%5.9d|\n", -123);
	my[++i] =ft_printf("5 - [ft_printf] |%05.9d|\n", -123);
	you[++p] =	printf("5 - [youprintf] |%05.9d|\n", -123);
	my[++i] =ft_printf("6 - [ft_printf] |%kg|\n");
	you[++p] =	printf("6 - [youprintf] |%kg|\n");
	my[++i] =ft_printf("7 - [ft_printf] |%4kg|\n");
	you[++p] =	printf("7 - [youprintf] |%4kg|\n");
	my[++i] =ft_printf("8 - [ft_printf] |%04kg|\n");
	you[++p] =	printf("8 - [youprintf] |%04kg|\n");
	my[++i] =ft_printf("9 - [ft_printf] |%.5kg|\n");
	you[++p] =	printf("9 - [youprintf] |%.5kg|\n");
	my[++i] =ft_printf("10 - [ft_printf] |%#hhhkg|\n");
	you[++p] =	printf("10 - [youprintf] |%#hhhkg|\n");
	my[++i] =ft_printf("11 - [ft_printf] |%ld|\n", -2);
	you[++p] =	printf("11 - [youprintf] |%ld|\n", -2);
	my[++i] =ft_printf("12 - [ft_printf] |%d|\n", -2147483648);
	you[++p] =	printf("12 - [youprintf] |%d|\n", -2147483648);
	my[++i] =ft_printf("13 - %0d\n", -42);
	you[++p] =	printf("13 - %0d\n", -42);
	my[++i] =ft_printf("14 - %00d\n", -42);
	you[++p] =	printf("14 - %00d\n", -42);
	my[++i] =ft_printf("15 - |%+d|\n", 0);
	you[++p] =	printf("15 - |%+d|\n", 0);
	my[++i] =ft_printf("16 - |% d|\n", 0);
	you[++p] =	printf("16 - |% d|\n", 0);
	my[++i] =ft_printf("17 - |%5d|\n", -42);
	you[++p] =	printf("17 - |%5d|\n", -42);
	my[++i] =ft_printf("18 - |%*lu|\n", 5, 0);
	you[++p] =	printf("18 - |%*lu|\n", 5, 0);

	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_4(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 4; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - [ft_printf] |%x|\n", INT32_MIN);
	you[++p] =	printf("0 - [youprintf] |%x|\n", INT32_MIN);
	my[++i] =ft_printf("1 - [ft_printf] |%x|\n", -123456789);
	you[++p] =	printf("1 - [youprintf] |%x|\n", -123456789);
	my[++i] =ft_printf("2 - [ft_printf] |%x|\n", -10);
	you[++p] =	printf("2 - [youprintf] |%x|\n", -10);
	my[++i] =ft_printf("3 - [ft_printf] |%x|\n", -5);
	you[++p] =	printf("3 - [youprintf] |%x|\n", -5);
	my[++i] =ft_printf("4 - [ft_printf] |%x|\n", 0);
	you[++p] =	printf("4 - [youprintf] |%x|\n", 0);
	my[++i] =ft_printf("5 - [ft_printf] |%x|\n", 5);
	you[++p] =	printf("5 - [youprintf] |%x|\n", 5);
	my[++i] =ft_printf("6 - [ft_printf] |%x|\n", 10);
	you[++p] =	printf("6 - [youprintf] |%x|\n", 10);
	my[++i] =ft_printf("7 - [ft_printf] |%x|\n", 123456789);
	you[++p] =	printf("7 - [youprintf] |%x|\n", 123456789);
	my[++i] =ft_printf("8 - [ft_printf] |%x|\n", INT32_MAX);
	you[++p] =	printf("8 - [youprintf] |%x|\n", INT32_MAX);
	my[++i] =ft_printf("9 - [ft_printf] |%o|\n", INT32_MIN);
	you[++p] =	printf("9 - [youprintf] |%o|\n", INT32_MIN);
	my[++i] =ft_printf("10 - [ft_printf] |%o|\n", -123456789);
	you[++p] =	printf("10 - [youprintf] |%o|\n", -123456789);
	my[++i] =ft_printf("11 - [ft_printf] |%o|\n", -10);
	you[++p] =	printf("11 - [youprintf] |%o|\n", -10);
	my[++i] =ft_printf("12 - [ft_printf] |%o|\n", -5);
	you[++p] =	printf("12 - [youprintf] |%o|\n", -5);
	my[++i] =ft_printf("13 - [ft_printf] |%o|\n", 0);
	you[++p] =	printf("13 - [youprintf] |%o|\n", 0);
	my[++i] =ft_printf("14 - [ft_printf] |%o|\n", 5);
	you[++p] =	printf("14 - [youprintf] |%o|\n", 5);
	my[++i] =ft_printf("15 - [ft_printf] |%o|\n", 10);
	you[++p] =	printf("15 - [youprintf] |%o|\n", 10);
	my[++i] =ft_printf("16 - [ft_printf] |%o|\n", 123456789);
	you[++p] =	printf("16 - [youprintf] |%o|\n", 123456789);
	my[++i] =ft_printf("17 - [ft_printf] |%o|\n", INT32_MAX);
	you[++p] =	printf("17 - [youprintf] |%o|\n", INT32_MAX);

	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_5(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 5; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - [ft_printf] |%9x|\n", INT32_MAX);
	you[++p] =	printf("0 - [youprintf] |%9x|\n", INT32_MAX);
	my[++i] =ft_printf("1 - [ft_printf] |%9.5x|\n", -123);
	you[++p] =	printf("1 - [youprintf] |%9.5x|\n", -123);
	my[++i] =ft_printf("2 - [ft_printf] |%09x|\n", INT32_MAX);
	you[++p] =	printf("2 - [youprintf] |%09x|\n", INT32_MAX);
	my[++i] =ft_printf("3 - [ft_printf] |%#9x|\n", INT32_MAX);
	you[++p] =	printf("3 - [youprintf] |%#9x|\n", INT32_MAX);
	my[++i] =ft_printf("4 - [ft_printf] |%#.9x|\n", INT32_MAX);
	you[++p] =	printf("4 - [youprintf] |%#.9x|\n", INT32_MAX);
	my[++i] =ft_printf("5 - [ft_printf] |%#-9x|\n", INT32_MAX);
	you[++p] =	printf("5 - [youprintf] |%#-9x|\n", INT32_MAX);
	my[++i] =ft_printf("6 - [ft_printf] |%#-9d|\n", INT32_MAX);
	you[++p] =	printf("6 - [youprintf] |%#-9d|\n", INT32_MAX);
	my[++i] =ft_printf("7 - [ft_printf] |%+d|\n", 123);
	you[++p] =	printf("7 - [youprintf] |%+d|\n", 123);
	my[++i] =ft_printf("8 - [ft_printf] |% d|\n", 123);
	you[++p] =	printf("8 - [youprintf] |% d|\n", 123);
	my[++i] =ft_printf("9 - [ft_printf] |%+u|\n", 123);
	you[++p] =	printf("9 - [youprintf] |%+u|\n", 123);
	my[++i] =ft_printf("10 - [ft_printf] |% u|\n", 123);
	you[++p] =	printf("10 - [youprintf] |% u|\n", 123);
	my[++i] =ft_printf("11 - [ft_printf] |%.5u|\n", 123);
	you[++p] =	printf("11 - [youprintf] |%.5u|\n", 123);
	my[++i] =ft_printf("12 - [ft_printf] |%9u|\n", 123);
	you[++p] =	printf("12 - [youprintf] |%9u|\n", 123);
	my[++i] =ft_printf("13 - [ft_printf] |%09u|\n", 123);
	you[++p] =	printf("13 - [youprintf] |%09u|\n", 123);
	my[++i] =ft_printf("14 - [printf] |%lld|\n", -9223372036854775808);
	you[++p] =	printf("14 - [printf] |%lld|\n", -9223372036854775808);
	my[++i] =ft_printf("15 - [printf] |%jd|\n", -9223372036854775808);
	you[++p] =	printf("15 - [printf] |%jd|\n", -9223372036854775808);

	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_6(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 6; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - [ft_printf] |%9X|\n", INT32_MAX);
	you[++p] =	printf("0 - [youprintf] |%9X|\n", INT32_MAX);
	my[++i] =ft_printf("1 - [ft_printf] |%9.5X|\n", -123);
	you[++p] =	printf("1 - [youprintf] |%9.5X|\n", -123);
	my[++i] =ft_printf("2 - [ft_printf] |%09X|\n", INT32_MAX);
	you[++p] =	printf("2 - [youprintf] |%09X|\n", INT32_MAX);
	my[++i] =ft_printf("3 - [ft_printf] |%9o|\n", INT32_MAX);
	you[++p] =	printf("3 - [youprintf] |%9o|\n", INT32_MAX);
	my[++i] =ft_printf("4 - [ft_printf] |%9.5o|\n", -123);
	you[++p] =	printf("4 - [youprintf] |%9.5o|\n", -123);
	my[++i] =ft_printf("5 - [ft_printf] |%010o|\n", 123456789);
	you[++p] =	printf("5 - [youprintf] |%010o|\n", 123456789);
	my[++i] =ft_printf("6 - [ft_printf] |%#o|\n", 123456789);
	you[++p] =	printf("6 - [youprintf] |%#o|\n", 123456789);
	my[++i] =ft_printf("7 - [ft_printf] |%#.9o|\n", 123456789);
	you[++p] =	printf("7 - [youprintf] |%#.9o|\n", 123456789);
	my[++i] =ft_printf("8 - [ft_printf] |%#-9o|\n", 123456789);
	you[++p] =	printf("8 - [youprintf] |%#-9o|\n", 123456789);
	my[++i] =ft_printf("9 - [ft_printf] |%#-9o|\n", 123456789);
	you[++p] =	printf("9 - [youprintf] |%#-9o|\n", 123456789);
	my[++i] =ft_printf("10 - [ft_printf] |%9.9o|\n", 123);
	you[++p] =	printf("10 - [youprintf] |%9.9o|\n", 123);
	my[++i] =ft_printf("11 - [ft_printf] |%#9o|\n", 123456789);
	you[++p] =	printf("11 - [youprintf] |%#9o|\n", 123456789);
	my[++i] =ft_printf("12 - [ft_printf] |\%d|\n", 123456789);
	you[++p] =	printf("12 - [youprintf] |\%d|\n", 123456789);
	my[++i] =ft_printf("13 - [ft_printf] |%#x|\n", 123456789);
	you[++p] =	printf("13 - [youprintf] |%#x|\n", 123456789);

	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_7(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 7; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - [ft_printf] |%c|\n", 'a');
	you[++p] =	printf("0 - [youprintf] |%c|\n", 'a');
	my[++i] =ft_printf("1 - [ft_printf] |%#c|\n", 'a');
	you[++p] =	printf("1 - [youprintf] |%#c|\n", 'a');
	my[++i] =ft_printf("2 - [ft_printf] |%05c|\n", 'a');
	you[++p] =	printf("2 - [youprintf] |%05c|\n", 'a');
	my[++i] =ft_printf("3 - [ft_printf] |%0-5c|\n", 'a');
	you[++p] =	printf("3 - [youprintf] |%0-5c|\n", 'a');
	my[++i] =ft_printf("4 - [ft_printf] |%+c|\n", 'a');
	you[++p] =	printf("4 - [youprintf] |%+c|\n", 'a');
	my[++i] =ft_printf("5 - [ft_printf] |% c|\n", 'a');
	you[++p] =	printf("5 - [youprintf] |% c|\n", 'a');
	my[++i] =ft_printf("6 - [ft_printf] |%.5c|\n", 'a');
	you[++p] =	printf("6 - [youprintf] |%.5c|\n", 'a');
	my[++i] =ft_printf("7 - [ft_printf] |%4.5c|\n", 'a');
	you[++p] =	printf("7 - [youprintf] |%4.5c|\n", 'a');
	my[++i] =ft_printf("8 - [ft_printf] |%5.4c|\n", 'a');
	you[++p] =	printf("8 - [youprintf] |%5.4c|\n", 'a');
	my[++i] =ft_printf("9 - [ft_printf] |%c|\n", '\0');
	you[++p] =	printf("9 - [youprintf] |%c|\n", '\0');
	my[++i] =ft_printf("10 - [ft_printf] |% c|\n", '\0');
	you[++p] =	printf("10 - [youprintf] |% c|\n", '\0');
	my[++i] =ft_printf("11 - [ft_printf] |%c|\n", u'Ξ');
	you[++p] =	printf("11 - [youprintf] |%c|\n", u'Ξ');

	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_8(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 8; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - [ft_printf] |%s|\n", "bonjour");
	you[++p] =	printf("0 - [youprintf] |%s|\n", "bonjour");
	my[++i] =ft_printf("1 - [ft_printf] |%#s|\n", "bonjour");
	you[++p] =	printf("1 - [youprintf] |%#s|\n", "bonjour");
	my[++i] =ft_printf("2 - [ft_printf] |%05s|\n", "un");
	you[++p] =	printf("2 - [youprintf] |%05s|\n", "un");
	my[++i] =ft_printf("3 - [ft_printf] |%0-5s|\n", "un");
	you[++p] =	printf("3 - [youprintf] |%0-5s|\n", "un");
	my[++i] =ft_printf("4 - [ft_printf] |%+s|\n", "un");
	you[++p] =	printf("4 - [youprintf] |%+s|\n", "un");
	my[++i] =ft_printf("5 - [ft_printf] |% s|\n", "un");
	you[++p] =	printf("5 - [youprintf] |% s|\n", "un");
	my[++i] =ft_printf("6 - [ft_printf] |%.5s|\n", "un");
	you[++p] =	printf("6 - [youprintf] |%.5s|\n", "un");
	my[++i] =ft_printf("7 - [ft_printf] |%4.5s|\n", "un");
	you[++p] =	printf("7 - [youprintf] |%4.5s|\n", "un");
	my[++i] =ft_printf("8 - [ft_printf] |%5.4s|\n", "un");
	you[++p] =	printf("8 - [youprintf] |%5.4s|\n", "un");
	my[++i] =ft_printf("9 - [ft_printf] |%s|\n", "\0");
	you[++p] =	printf("9 - [youprintf] |%s|\n", "\0");
	my[++i] =ft_printf("10 - [ft_printf] |% s|\n", "\0");
	you[++p] =	printf("10 - [youprintf] |% s|\n", "\0");
	my[++i] =ft_printf("11 - [ft_printf] |% s|\n", NULL);
	you[++p] =	printf("11 - [youprintf] |% s|\n", NULL);
	my[++i] =ft_printf("12 - [ft_printf] |%s|\n", NULL);
	you[++p] =	printf("12 - [youprintf] |%s|\n", NULL);
	my[++i] =ft_printf("13 - [ft_printf] |%9s|\n", NULL);
	you[++p] =	printf("13 - [youprintf] |%9s|\n", NULL);
	my[++i] =ft_printf("14 - [ft_printf] |%09s|\n", NULL);
	you[++p] =	printf("14 - [youprintf] |%09s|\n", NULL);
	my[++i] =ft_printf("15 - [ft_printf] |%0-9s|\n", NULL);
	you[++p] =	printf("15 - [youprintf] |%0-9s|\n", NULL);//
	my[++i] =ft_printf("16 - [ft_printf] |%09lls|\n", "bonjour");
	you[++p] =	printf("16 - [youprintf] |%09lls|\n", "bonjour");
	my[++i] =ft_printf("17 - [ft_printf] |%09hhs|\n", "bonjour");
	you[++p] =	printf("17 - [youprintf] |%09hhs|\n", "bonjour");//

	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_9(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 9; //nb_test
	printf("\n");
	setlocale(LC_ALL, "");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - [ft_printf] |%c|\n", L'Ξ');
	you[++p] =	printf("0 - [youprintf] |%c|\n", L'Ξ');
	my[++i] =ft_printf("1 - [ft_printf] |%hc|\n", L'Ξ');
	you[++p] =	printf("1 - [youprintf] |%hc|\n", L'Ξ');
	my[++i] =ft_printf("2 - [ft_printf] |%C|\n", L'Ξ');
	you[++p] =	printf("2 - [youprintf] |%C|\n", L'Ξ');
	my[++i] =ft_printf("3 - [ft_printf] |%lc|\n", L'Ξ');
	you[++p] =	printf("3 - [youprintf] |%lc|\n", L'Ξ');
	my[++i] =ft_printf("4 - [ft_printf] |%9lc|\n", L'Ξ');
	you[++p] =	printf("4 - [youprintf] |%9lc|\n", L'Ξ');
	my[++i] =ft_printf("5 - [ft_printf] |%09lc|\n", L'Ξ');
	you[++p] =	printf("5 - [youprintf] |%09lc|\n", L'Ξ');
	my[++i] =ft_printf("6 - [ft_printf] |%4.2lc|\n", L'☢');
	you[++p] =	printf("6 - [youprintf] |%4.2lc|\n", L'☢');
	my[++i] =ft_printf("7 - [ft_printf] |%-9lc|\n", L'☢');
	you[++p] =	printf("7 - [youprintf] |%-9lc|\n", L'☢');

	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_10(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 10; //nb_test
	printf("\n");
	setlocale(LC_ALL, "");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - [ft_printf] |%S|\n", L"Ξ");
	you[++p] =	printf("0 - [youprintf] |%S|\n", L"Ξ");
	my[++i] =ft_printf("1 - [ft_printf] |%s|\n", L"Ξ");
	you[++p] =	printf("1 - [youprintf] |%s|\n", L"Ξ");
	my[++i] =ft_printf("2 - [ft_printf] |%ls|\n", L"Ξ");
	you[++p] =	printf("2 - [youprintf] |%ls|\n", L"Ξ");
	my[++i] =ft_printf("3 - [ft_printf] |%hs|\n", L"Ξ");
	you[++p] =	printf("3 - [youprintf] |%hs|\n", L"Ξ");
	my[++i] =ft_printf("4 - [ft_printf] |%9ls|\n", L"Ξ");
	you[++p] =	printf("4 - [youprintf] |%9ls|\n", L"Ξ");
	my[++i] =ft_printf("5 - [ft_printf] |%9ls|\n", L"Ξ");
	you[++p] =	printf("5 - [youprintf] |%9ls|\n", L"Ξ");//
	my[++i] =ft_printf("6 - [ft_printf] |%4.1lc|\n", L'☢');
	you[++p] =	printf("6 - [youprintf] |%4.1lc|\n", L'☢');//
	my[++i] =ft_printf("7 - [ft_printf] |%4.2ls|\n", L"☢b");
	you[++p] =	printf("7 - [youprintf] |%4.2ls|\n", L"☢b");
	my[++i] =ft_printf("8 - [ft_printf] |%-9ls|\n", L"☢");
	you[++p] =	printf("8 - [youprintf] |%-9ls|\n", L"☢");
	my[++i] =ft_printf("9 - [ft_printf] |%-9.9ls|\n", L"BONJOUR");
	you[++p] =	printf("9 - [youprintf] |%-9.9ls|\n", L"BONJOUR");
	my[++i] =ft_printf("10 - [ft_printf] |%-9.2s|\n", "BONJOUR");
	you[++p] =	printf("10 - [youprintf] |%-9.2s|\n", "BONJOUR");
	my[++i] =ft_printf("11 - [ft_printf] |%-9s|\n", "BONJOUR");
	you[++p] =	printf("11 - [youprintf] |%-9s|\n", "BONJOUR");
	my[++i] =ft_printf("12 - [ft_printf] |%-9.2s|\n", NULL);
	you[++p] =	printf("12 - [youprintf] |%-9.2s|\n", NULL);
	my[++i] =ft_printf("13 - [ft_printf] |% S|\n", NULL);
	you[++p] =	printf("13 - [youprintf] |% S|\n", NULL);
	my[++i] =ft_printf("14 - [ft_printf] |% S|\n", L"(null)");
	you[++p] =	printf("14 - [youprintf] |% S|\n", L"(null)");//
	my[++i] =ft_printf("15 - [ft_printf] |%lls|\n", "BON☢JOUR");
	you[++p] =	printf("15 - [youprintf] |%lls|\n", "BON☢JOUR");
	my[++i] =ft_printf("%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	you[++p] =	printf("%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_11(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 11; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - [ft_printf] |%p|\n", my);
	you[++p] =	printf("0 - [youprintf] |%p|\n", my);
	my[++i] =ft_printf("1 - [ft_printf] |%#p|\n", my);
	you[++p] =	printf("1 - [youprintf] |%#p|\n", my);
	my[++i] =ft_printf("2 - [ft_printf] |%14p|\n", my);
	you[++p] =	printf("2 - [youprintf] |%14p|\n", my);
	my[++i] =ft_printf("3 - [ft_printf] |%.14p|\n", my);
	you[++p] =	printf("3 - [youprintf] |%.14p|\n", my);
	my[++i] =ft_printf("4 - [ft_printf] |%15.14p|\n", my);
	you[++p] =	printf("4 - [youprintf] |%15.14p|\n", my);
	my[++i] =ft_printf("5 - [ft_printf] |%14.15p|\n", my);
	you[++p] =	printf("5 - [youprintf] |%14.15p|\n", my);
	my[++i] =ft_printf("6 - [ft_printf] |%014p|\n", my);
	you[++p] =	printf("6 - [youprintf] |%014p|\n", my);
	my[++i] =ft_printf("7 - [ft_printf] |%-14.15p|\n", my);
	you[++p] =	printf("7 - [youprintf] |%-14.15p|\n", my);
	my[++i] =ft_printf("8 - [ft_printf] |%-15.14p|\n", my);
	you[++p] =	printf("8 - [youprintf] |%-15.14p|\n", my);
	my[++i] =ft_printf("9 - [ft_printf] |%0-15.14p|\n", my);
	you[++p] =	printf("9 - [youprintf] |%0-15.14p|\n", my);
	my[++i] =ft_printf("10 - [ft_printf] |%hhp|\n", my);
	you[++p] =	printf("10 - [youprintf] |%hhp|\n", my);
	my[++i] =ft_printf("11 - [ft_printf] |%llp|\n", my);
	you[++p] =	printf("11 - [youprintf] |%llp|\n", my);
	my[++i] =ft_printf("12 - [ft_printf] |%p|\n", NULL);
	you[++p] =	printf("12 - [youprintf] |%p|\n", NULL);
	my[++i] =ft_printf("%p\n", &i);
	you[++p] =	printf("%p\n", &i);
	my[++i] =ft_printf("{%5p}\n", 0);
	you[++p] =	printf("{%5p}\n", 0);
	my[++i] =ft_printf("{%.5p}\n", 0);
	you[++p] =	printf("{%.5p}\n", 0);
	my[++i] =ft_printf("%9.2p\n", 1234);
	you[++p] =	printf("%9.2p\n", 1234);
	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_12(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 12; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - |%#x|\n", 0);
	you[++p] =	printf("0 - |%#x|\n", 0);
	my[++i] =ft_printf("1 - |%#08x|\n", 42);
	you[++p] =	printf("1 - |%#08x|\n", 42);
	my[++i] =ft_printf("2 - @moulitest: |%#.x| |%#.0x|\n", 0, 0);
	you[++p] =	printf("2 - @moulitest: |%#.x| |%#.0x|\n", 0, 0);
	my[++i] =ft_printf("3 - @moulitest: |%.x| |%.0x|\n", 0, 0);
	you[++p] =	printf("3 - @moulitest: |%.x| |%.0x|\n", 0, 0);
	my[++i] =ft_printf("4 - @moulitest: |%5.x| |%5.0x|\n", 0, 0);
	you[++p] =	printf("4 - @moulitest: |%5.x| |%5.0x|\n", 0, 0);
	my[++i] =ft_printf("5 - @moulitest: |%.x| |%.0x|\n", 5, 5);
	you[++p] =	printf("5 - @moulitest: |%.x| |%.0x|\n", 5, 5);
	my[++i] =ft_printf("6 - |%#6o|\n", 2500);
	you[++p] =	printf("6 - |%#6o|\n", 2500);
	my[++i] =ft_printf("7 - |%-#6o|\n", 2500);
	you[++p] =	printf("7 - |%-#6o|\n", 2500);
	my[++i] =ft_printf("8 - @moulitest: |%.o| |%.0o|\n", 0, 0);
	you[++p] =	printf("8 - @moulitest: |%.o| |%.0o|\n", 0, 0);
	my[++i] =ft_printf("9 - @moulitest: |%5.o| |%5.0o|\n", 0, 0);
	you[++p] =	printf("9 - @moulitest: |%5.o| |%5.0o|\n", 0, 0);
	my[++i] =ft_printf("10 - @moulitestf: |%#.o| |%#.0o|\n", 0, 0);
	you[++p] =	printf("10 - @moulitestp: |%#.o| |%#.0o|\n", 0, 0);
	my[++i] =ft_printf("11 - @moulitestf: |%#.4o| |%#.0o|\n", 0, 0);
	you[++p] =	printf("11 - @moulitestp: |%#.4o| |%#.0o|\n", 0, 0);
	my[++i] =ft_printf("12 - @moulitestf: |%#o| |%#.0o|\n", 0, 0);
	you[++p] =	printf("12 - @moulitestp: |%#o| |%#.0o|\n", 0, 0);
	my[++i] =ft_printf("13 - @moulitestf: |%o| |%#.0o|\n", 0, 0);
	you[++p] =	printf("13 - @moulitestp: |%o| |%#.0o|\n", 0, 0);
	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_13(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 13; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - |%0+5d|\n", 42);
	you[++p] =	printf("0 - |%0+5d|\n", 42);
	my[++i] =ft_printf("1 - |%-05d|\n", -42);
	you[++p] =	printf("1 - |%-05d|\n", -42);
	my[++i] =ft_printf("2 - |% 10.5d|\n", 4242);
	you[++p] =	printf("2 - |% 10.5d|\n", 4242);
	my[++i] =ft_printf("3 - |%+10.5d|\n", 4242);
	you[++p] =	printf("3 - |%+10.5d|\n", 4242);
	my[++i] =ft_printf("4 - |%-+10.5d|\n", 4242);
	you[++p] =	printf("4 - |%-+10.5d|\n", 4242);
	my[++i] =ft_printf("5 - |%03.2d|\n", 0);
	you[++p] =	printf("5 - |%03.2d|\n", 0);
	my[++i] =ft_printf("6 - |%03.2d|\n", 1);
	you[++p] =	printf("6 - |%03.2d|\n", 1);
	my[++i] =ft_printf("7 - @moulitest: |%.d| |%.0d|\n", 0, 0);
	you[++p] =	printf("7 - @moulitest: |%.d| |%.0d|\n", 0, 0);
	my[++i] =ft_printf("8 - @moulitest: |%5.d| |%5.0d|\n", 0, 0);
	you[++p] =	printf("8 - @moulitest: |%5.d| |%5.0d|\n", 0, 0);
	my[++i] =ft_printf("9 - |%03d|\n", 0);
	you[++p] =	printf("9 - |%03d|\n", 0);
	my[++i] =ft_printf("10 - |%0.2d|\n", 0);
	you[++p] =	printf("10 - |%0.2d|\n", 0);
	my[++i] =ft_printf("11 - |%09.2d|\n", 0);
	you[++p] =	printf("11 - |%09.2d|\n", 0);
	my[++i] =ft_printf("12 - |%09.2d|\n", 1);
	you[++p] =	printf("12 - |%09.2d|\n", 1);
	my[++i] =ft_printf("{%+03d}\n", 12);
	you[++p] =	printf("{%+03d}\n", 12);

	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_14(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 14; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - |%0+5u|\n", 42);
	you[++p] =	printf("0 - |%0+5u|\n", 42);
	my[++i] =ft_printf("1 - |%-05u|\n", -42);
	you[++p] =	printf("1 - |%-05u|\n", -42);
	my[++i] =ft_printf("2 - |% 10.5u|\n", 4242);
	you[++p] =	printf("2 - |% 10.5u|\n", 4242);
	my[++i] =ft_printf("3 - |%+10.5u|\n", 4242);
	you[++p] =	printf("3 - |%+10.5u|\n", 4242);
	my[++i] =ft_printf("4 - |%-+10.5u|\n", 4242);
	you[++p] =	printf("4 - |%-+10.5u|\n", 4242);
	my[++i] =ft_printf("5 - |%03.2u|\n", 0);
	you[++p] =	printf("5 - |%03.2u|\n", 0);
	my[++i] =ft_printf("6 - |%03.2u|\n", 1);
	you[++p] =	printf("6 - |%03.2u|\n", 1);
	my[++i] =ft_printf("7 - @moulitest: |%.u| |%.0u|\n", 0, 0);
	you[++p] =	printf("7 - @moulitest: |%.u| |%.0u|\n", 0, 0);
	my[++i] =ft_printf("8 - @moulitest: |%5.u| |%5.0u|\n", 0, 0);
	you[++p] =	printf("8 - @moulitest: |%5.u| |%5.0u|\n", 0, 0);
	my[++i] =ft_printf("9 - |%03u|\n", 0);
	you[++p] =	printf("9 - |%03u|\n", 0);
	my[++i] =ft_printf("10 - |%0.2u|\n", 0);
	you[++p] =	printf("10 - |%0.2u|\n", 0);
	my[++i] =ft_printf("11 - |%09.2u|\n", 0);
	you[++p] =	printf("11 - |%09.2u|\n", 0);
	my[++i] =ft_printf("12 - |%09.2u|\n", 1);
	you[++p] =	printf("12 - |%09.2u|\n", 1);

	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_15(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 15; //nb_test
	printf("\n");
	// setlocale(LC_ALL, "");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - %");
	printf("\n");
	you[++p] =	printf("0 - %");
	printf("\n");
	my[++i] =ft_printf("1 - % ");
	printf("\n");
	you[++p] =	printf("1 - % ");
	printf("\n");
	my[++i] =ft_printf("2 - % hZ%");
	printf("\n");
	you[++p] =	printf("2 - % hZ%");
	printf("\n");
	my[++i] =ft_printf("3 - %%%", "test");
	printf("\n");
	you[++p] =	printf("3 - %%%", "test");
	printf("\n");
	my[++i] =ft_printf("4 - a%Sb%sc%S", L" 🀲 ", "42", L"猫");
	printf("\n");
	you[++p] =	printf("4 - a%Sb%sc%S", L" 🀲 ", "42", L"猫");
	printf("\n");
	my[++i] =ft_printf("5 - {%5p}\n", 0);
	you[++p] =	printf("5 - {%5p}\n", 0);
	my[++i] =ft_printf("6 - {%05p}\n", 0);
	you[++p] =	printf("6 - {%05p}\n", 0);
	my[++i] =ft_printf("7 - %#o\n", 0);
	you[++p] =	printf("7 - %#o\n", 0);
	my[++i] =ft_printf("8 - {% 03d}\n", 0);
	you[++p] =	printf("8 - {% 03d}\n", 0);
	my[++i] =ft_printf("9 - {%+03d}\n", 0);
	you[++p] =	printf("9 - {%+03d}\n", 0);
	my[++i] =ft_printf("10 - %.0p, %.p\n", 0, 0);
	you[++p] =	printf("10 - %.0p, %.p\n", 0, 0);
	my[++i] =ft_printf("11 - {%.5p}, {%5.p}\n", 0, 0);
	you[++p] =	printf("11 - {%.5p}, {%5.p}\n", 0, 0);
	my[++i] =ft_printf("12 - {%.4S}\n", L"我是一只猫。");
	you[++p] =	printf("12 - {%.4S}\n", L"我是一只猫。");
	my[++i] =ft_printf("13 - [ft_printf] |%4.2ls|\n", L"☢b");
	you[++p] =	printf("13 - [youprintf] |%4.2ls|\n", L"☢b");
	my[++i] =ft_printf("14 - [ft_printf] |%.2ls|\n", L"☢b");
	you[++p] =	printf("14 - [youprintf] |%.2ls|\n", L"☢b");
	my[++i] =ft_printf("15 - [ft_printf] |%.3ls|\n", L"☢b");
	you[++p] =	printf("15 - [youprintf] |%.3ls|\n", L"☢b");
	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_16(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 16; //nb_test
	printf("\n");
	// setlocale(LC_ALL, "");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("%#.3o\n", 1);
	you[++p] =	printf("%#.3o\n", 1);
	my[++i] =ft_printf("{%15.4S}\n", L"我是一只猫。");
	you[++p] =	printf("{%15.4S}\n", L"我是一只猫。");
	my[++i] =ft_printf("|%C|\n", 0);
	you[++p] =	printf("|%C|\n", 0);
	ft_printf("f - |%b|\nf - |%B|\n", INT32_MAX, INT64_MAX);
	ft_printf("f - |%#04.0b|\n", 5);
	ft_printf("f - |%#4.b|\n", 5);
	ft_printf("f - |%#.0b|\n", 0);
	ft_printf("f - |%#0b|\n", 0);
	ft_printf("f - |%#.b|\n", 0);
	ft_printf("f - |%#.5b|\n", 0);
	printf("p - |%#.5x|\n", 0);
	printf("p - |%#.0x|\n", 0);
	printf("p - |%#0x|\n", 0);
	printf("p - |%#.x|\n", 0);
	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_17(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 17; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	ft_printf("|{red}red{eoc}|\n");
	ft_printf("|{black}black{eoc}|\n");
	ft_printf("|{green}green{eoc}|\n");
	ft_printf("|{yellow}yellow{eoc}|\n");
	ft_printf("|{blue}blue{eoc}|\n");
	ft_printf("|{magenta}magenta{eoc}|\n");
	ft_printf("|{cyan}cyan{eoc}|\n");
	ft_printf("|{white}white{eoc}|\n");
	ft_printf("|{bold}bold{eoc}|\n");
	ft_printf("|{underline}underline{eoc}|\n");
	ft_printf("|{dim}dim{eoc}|\n");
	ft_printf("|{blink}blink{eoc}|\n");
	ft_printf("|{inverted}inverted{eoc}|\n");
	ft_printf("|{hidden}hidden{eoc}|\n");
	ft_printf("|{}{eoc}|\n");
	ft_printf("|{green}{}|\n");
	ft_printf("|bonjour|\n");
	ft_printf("|{eoc}{}|\n");

	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_18(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int	t[] = {0, 0};
	int nt = 18; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	ft_printf("      {green}{inverted} {eoc}\n");
	ft_printf("     {green}{inverted}   {eoc}\n");
	ft_printf("    {green}{inverted} {cyan} {green} {red} {green} {eoc}\n");
	ft_printf("   {green}{inverted}       {eoc}\n");
	ft_printf("  {green}{inverted}  {blue} {green}  {yellow} {green}   {eoc}\n");
	ft_printf(" {green}{inverted}  {white} {green}      {black} {green} {eoc}\n");
	ft_printf("{green}{inverted}         {magenta} {green}   {eoc}\n");
	ft_printf("      {yellow}{inverted} {eoc}\n");
	my[++i] =ft_printf("bonjourholla%lc%n\n", L'☢', t);
	you[++p] =	printf("bonjourholla%lc%n\n", L'☢', t + 1);
	printf("%d %d\n", t[0], t[1]);
	my[++i] =ft_printf("bonjourholla%n%lc\n", t, L'☢');
	you[++p] =	printf("bonjourholla%n%lc\n", t + 1, L'☢');
	printf("%d %d\n", t[0], t[1]);
	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_19(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 19; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*\n");
	dprintf(2, "\n\n");
	you[++p] =	printf("Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*\n");
	my[++i] =ft_printf("%s", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*\n");
	you[++p] =	printf("%s", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*\n");
	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_20(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 20; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	ft_printf("%ll#x\n", 9223372036854775807);
	ft_printf("%0 d\n", 42);
	ft_printf("% 0d\n", 42);
	ft_printf("%5+d\n", 42);
	ft_printf("%5+d\n", -42);
	ft_printf("%-5+d\n", 42);
	ft_printf("%-0+5d\n", 42);
	ft_printf("%-5+d\n", -42);
	ft_printf("%lhlz\n", 9223372036854775807);
	ft_printf("%hhld\n", 128);
	ft_printf("@main_ftprintf: %####0000 33..1..#00d\\n\n", 256);
	ft_printf("@main_ftprintf: %####0000 33..1d\n", 256);
	ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d\n", 256);
	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_21(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 21; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - |%*d|\n", 5, 3);
	you[++p] =	printf("0 - |%*d|\n", 5, 3);
	my[++i] =ft_printf("1 - |%.*d|\n", 5, 3);
	you[++p] =	printf("1 - |%.*d|\n", 5, 3);
	my[++i] =ft_printf("2 - |%*.*d|\n", 10, 5, 3);
	you[++p] =	printf("2 - |%*.*d|\n", 10, 5, 3);
	my[++i] =ft_printf("3 - |%5*d|\n", 10, 3);
	you[++p] =	printf("3 - |%5*d|\n", 10, 3);
	my[++i] =ft_printf("4 - |%*5d|\n", 10, 3);
	you[++p] =	printf("4 - |%*5d|\n", 10, 3);
	my[++i] =ft_printf("5 - |%.5*d|\n", 10, 3);
	you[++p] =	printf("5 - |%.5*d|\n", 10, 3);
	my[++i] =ft_printf("6 - |%.*5d|\n", 10, 3);
	you[++p] =	printf("6 - |%.*5d|\n", 10, 3);
	my[++i] =ft_printf("7 - |%5*.5*d|\n", 10, 6, 3);
	you[++p] =	printf("7 - |%5*.5*d|\n", 10, 6, 3);
	my[++i] =ft_printf("8 - |%*5.*5d|\n", 10, 6, 3);
	you[++p] =	printf("8 - |%*5.*5d|\n", 10, 6, 3);
	my[++i] =ft_printf("9 - |%**d|\n", 10, 9, 6);
	you[++p] =	printf("9 - |%**d|\n", 10, 9, 6);
	my[++i] =ft_printf("10 - |%.**d|\n", 10, 9, 6);
	you[++p] =	printf("10 - |%.**d|\n", 10, 9, 6);
	my[++i] =ft_printf("11 - |%*d|\n", -5, 3);
	you[++p] =	printf("11 - |%*d|\n", -5, 3);
	my[++i] =ft_printf("12 - |%.*d|\n", -5, 3);
	you[++p] =	printf("12 - |%.*d|\n", -5, 3);
	my[++i] =ft_printf("13 - |%*.*d|\n", -10, -5, 3);
	you[++p] =	printf("13 - |%*.*d|\n", -10, -5, 3);
	my[++i] =ft_printf("14 - |%-*d|\n", -5, 3);
	you[++p] =	printf("14 - |%-*d|\n", -5, 3);
	my[++i] =ft_printf("15 - |%-.*d|\n", -5, 3);
	you[++p] =	printf("15 - |%-.*d|\n", -5, 3);
	my[++i] =ft_printf("16 - |%-*.*d|\n", -10, -5, 3);
	you[++p] =	printf("16 - |%-*.*d|\n", -10, -5, 3);
	my[++i] =ft_printf("17 - |%-*d|\n", 5, 3);
	you[++p] =	printf("17 - |%-*d|\n", 5, 3);
	my[++i] =ft_printf("18 - |%-.*d|\n", 5, 3);
	you[++p] =	printf("18 - |%-.*d|\n", 5, 3);
	my[++i] =ft_printf("19 - |%-*.*d|\n", 10, 5, 3);
	you[++p] =	printf("19 - |%-*.*d|\n", 10, 5, 3);
	(void)p;
	return (0);
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_22(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int	b[2];
	int nt = 22; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	my[++i] =ft_printf("0 - %5d\n", 0);
	you[++p] =	printf("0 - %5d\n", 0);
	my[++i] =ft_printf("1 - %5u\n", 0);
	you[++p] =	printf("1 - %5u\n", 0);
	my[++i] =ft_printf("2 - %5x\n", 0);
	you[++p] =	printf("2 - %5x\n", 0);
	my[++i] =ft_printf("3 - %5o\n", 0);
	you[++p] =	printf("3 - %5o\n", 0);
	ft_printf("4 - %5b\n", 0);
	my[++i] =ft_printf("5 - %05d\n", 0);
	you[++p] =	printf("5 - %05d\n", 0);
	my[++i] =ft_printf("6 - %05u\n", 0);
	you[++p] =	printf("6 - %05u\n", 0);
	my[++i] =ft_printf("7 - %05x\n", 0);
	you[++p] =	printf("7 - %05x\n", 0);
	my[++i] =ft_printf("8 - %05o\n", 0);
	you[++p] =	printf("8 - %05o\n", 0);
	ft_printf("9 - %05b\n", 0);
	ft_printf("%.*s\n", -5, "42");
	printf("%.*s\n", -5, "42");
	printf("bonjour%n\n", b);
	ft_printf("bonjour%n\n", b + 1);
	printf("%d %d\n", b[0], b[1]);
	printf("%nbonjour\n", b);
	ft_printf("%nbonjour\n", b + 1);
	printf("%d %d\n", b[0], b[1]);
	printf("bon%njour\n", b);
	ft_printf("bon%njour\n", b + 1);
	printf("%d %d\n", b[0], b[1]);
	printf("11 - |%5d|\n", 5);
	printf("11 - |%*d|\n", 9, 5);
	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

int		ft_test_23(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = 23; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);
	ft_printf("%s%s%s\n", "\033[91m", "bonjour", "\033[0m");
	printf("%s%s%s\n", "\033[91m", "bonjour", "\033[0m");
	ft_printf("{Bred}Bred{eoc}\n");
	ft_printf("{Bgreen}Bgreen{eoc}\n");
	ft_printf("{Byellow}Byellow{eoc}\n");
	ft_printf("{Bblue}Bblue{eoc}\n");
	ft_printf("{Bpurple}Bpurple{eoc}\n");
	ft_printf("{Bcyan}Bcyan{eoc}\n");
	ft_printf("{Bwhite}Bwhite{eoc}\n");
	ft_printf("{blink}{Bcyan}{red}{bold}p{eoc}\n");
	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}

/*
int		ft_test_n123(void)
{
	int *my = ft_get_tab();
	int *you = ft_get_tab();
	int error = 0;
	int i = -1;
	int p = -1;
	int nt = n123; //nb_test
	printf("\n");
	printf("=====================\nft_test_%d\n=====================\n", nt);

	(void)p;
	printf("\n");
	i = -1;
	while (++i < NB_TEST)
		if ((my[i] != 0 || you[i] != 0) && my[i] != you[i])
		{
			printf("%1$d> ft_printf[%1$d] = %2$d printf[%1$d] = %3$d\n", i, my[i], you[i]);
			error = 1;
		}
	free(my);
	free(you);
	return (error);
}
*/

int		main(int argc, char **argv)
{
	int		nb_fc = 23;
	char	*test_to_make = ft_strnew(nb_fc);
	char	stres[NB_TEST];
	int		i = -1;
	int		nb;
	int		error = 0;

	setlocale(LC_ALL, "");
	while (++i < NB_TEST)
		stres[i] = 1;
	i = -1;
	if (argc == 1) {
		while (++i < nb_fc)
			test_to_make[i] = 1;
	} else {
		while (argc - 1 > 0) {
			if ((nb = atoi(argv[argc - 1]) - 1) < nb_fc)
				test_to_make[nb] = 1;
			else
			{
				if (error == 0)
					printf("====================================\n");
				printf("error ft_test_%d, doesn't exits (%d <= %d == %d)\n", nb + 1, nb + 1, nb_fc, nb + 1 <= nb_fc);
				error = (error == 0) ? 1 : error;
			}
			argc--;
		}
	}
	if (error)
	{
		printf("an error occured, Stop\n");
		printf("====================================\n");
		exit(EXIT_FAILURE);
	}
	error = 0;
	i = -1;
	if (test_to_make[++i])
		stres[i] = ft_test_1();		//nb wrong flags
	if (test_to_make[++i])
		stres[i] = ft_test_2();		//nb wrong flags
	if (test_to_make[++i])
		stres[i] = ft_test_3();		//nb u wrong flags
	if (test_to_make[++i])
		stres[i] = ft_test_4();		//conv
	if (test_to_make[++i])
		stres[i] = ft_test_5();		//conv flags | nb
	if (test_to_make[++i])
		stres[i] = ft_test_6();		//conv flags
	if (test_to_make[++i])
		stres[i] = ft_test_7();		//char flags wrong
	if (test_to_make[++i])
		stres[i] = ft_test_8();		//str flags wrong
	if (test_to_make[++i])
		stres[i] = ft_test_9();		//unicode char
	if (test_to_make[++i])
		stres[i] = ft_test_10();	//unicode str
	if (test_to_make[++i])
		stres[i] = ft_test_11();	//adr
	if (test_to_make[++i])
		stres[i] = ft_test_12();	//conv flags bis
	if (test_to_make[++i])
		stres[i] = ft_test_13();	//nb flags bis
	if (test_to_make[++i])
		stres[i] = ft_test_14();	//nb flags bis
	if (test_to_make[++i])
		stres[i] = ft_test_15();	//unicode | no flags | adr
	if (test_to_make[++i])
		stres[i] = ft_test_16();
	if (test_to_make[++i])
		stres[i] = ft_test_17();
	if (test_to_make[++i])
		stres[i] = ft_test_18();
	if (test_to_make[++i])
		stres[i] = ft_test_19();
	if (test_to_make[++i])
		stres[i] = ft_test_20();
	if (test_to_make[++i])
		stres[i] = ft_test_21();
	if (test_to_make[++i])
		stres[i] = ft_test_22();
	if (test_to_make[++i])
		stres[i] = ft_test_23();

	i = 0;
	printf("=====%s=====\n", "_-resultat-_");
	while (i < nb_fc)
	{
		if (stres[i] != 0 && test_to_make[i] == 1)
			printf("ft_test_%d failed\n", i + 1);
		error = (stres[i] != 0 && test_to_make[i] == 1) ? 1 : error;
		i++;
	}
	if (error == 0)
		printf("all test past\n");
	printf("=====%s=====\n", "_-end  res-_");
	free(test_to_make);
	return (0);
}
