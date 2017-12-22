/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:09:15 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/08 09:37:28 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>

#ifndef NB_TEST
# define NB_TEST 20
#endif

int		*ft_get_tab(size_t len)
{
	int *t;

	if (!(t = (int*)malloc(sizeof(int) * len)))
		exit(EXIT_FAILURE);
	while (len)
		t[len--] = 0;
	return (t);
}

int		*test_1(void)
{
	int *t = ft_get_tab(NB_TEST);
	int i[] = {1234564789, 10, 255};
	size_t	index = 0;

	printf("\n======================\n%s\n======================\n", "test_1");
	t[index++] = printf("%5%|\n");
	t[index++] = printf("%-5%|\n");
	t[index++] = printf("%.5s|\n", "bonjour je suis la");
	t[index++] = printf("%5d|\n", i[0]);
	t[index++] = printf("%-5d|\n", i[0]);
	t[index++] = printf("%.5d|\n", i[0]);
	t[index++] = printf("%5x|\n", i[2]);
	t[index++] = printf("%-5x|\n", i[2]);
	t[index++] = printf("%-2x|\n", i[2]);
	t[index++] = printf("%5x|\n", i[2]);
	t[index++] = printf("%.5x|\n", i[2]);
	t[index++] = printf("%5o|\n", i[2]);
	t[index++] = printf("%.5o|\n", i[2]);
	t[index++] = printf("%5p|\n", &i);
	t[index++] = printf("%p|\n", &i);
	return (t);
}

int		*test_2(void)
{
	int *t = ft_get_tab(NB_TEST);
	int i[] = {1234564789, 10, 255};
	size_t	index = 0;

	printf("\n======================\n%s\n======================\n", "test_2");
	t[index++] = printf("%5.5%|\n");
	t[index++] = printf("%-5.5%|\n");
	t[index++] = printf("%5.5s|\n", "bonjour je suis la");
	t[index++] = printf("%5.5d|\n", i[0]);
	t[index++] = printf("%-5.5d|\n", i[0]);
	t[index++] = printf("%5.5d|\n", i[0]);
	t[index++] = printf("%5.5x|\n", i[2]);
	t[index++] = printf("%-5.5x|\n", i[2]);
	t[index++] = printf("%-2.5x|\n", i[2]);
	t[index++] = printf("%5.5x|\n", i[2]);
	t[index++] = printf("%5.5x|\n", i[2]);
	t[index++] = printf("%5.5o|\n", i[2]);
	t[index++] = printf("%5.5o|\n", i[2]);
	t[index++] = printf("%5p|\n", &i);
	t[index++] = printf("%-5p|\n", &i);
	return (t);
}

int		*test_3(void)
{
	int *t = ft_get_tab(NB_TEST);
	int i[] = {1234564789, 10, 255, -10};
	intmax_t l[] = {2147483648, -2147483648};
	char c[] = {'c', 'b', 'd'};
	short s[] = {123, 456, 789};
	size_t	index = 0;

	printf("\n======================\n%s\n======================\n", "test_3");
	t[index++] = printf("%hh%|\n");
	t[index++] = printf("%h%|\n");
	t[index++] = printf("%s|\n", "bonjour je suis la");
	t[index++] = printf("%hhd|\n", c[0]);
	t[index++] = printf("%hd|\n", s[0]);
	t[index++] = printf("%jd|\n", l[0]);
	t[index++] = printf("%jd|\n", l[1]);	
	t[index++] = printf("%-d|\n", i[1]);
	t[index++] = printf("%+d|\n", i[1]);
	t[index++] = printf("%x|\n", i[1]);
	t[index++] = printf("%#x|\n", i[1]);
	t[index++] = printf("%#05x|\n", i[1]);
	t[index++] = printf("%0#5x|\n", i[1]);
	t[index++] = printf("%00#0005x|\n", i[1]);
	t[index++] = printf("%        %|\n");
	t[index++] = printf("%hd|\n", s[2]);

	return (t);
}

int		*test_4(void)
{
	int *t = ft_get_tab(NB_TEST);
	short s[] = {123, 456, 789, -123};
	size_t	index = 0;
	
	printf("\n======================\n%s\n======================\n", "test_4");	
	t[index++] = printf("%5.5hd|\n", s[2]);
	t[index++] = printf("%05.5hd|\n", s[2]);
	t[index++] = printf("%05.5hx|\n", s[2]);
	t[index++] = printf("%#05.5hx|\n", s[2]);
	t[index++] = printf("%0#5.5hx|\n", s[2]);
	t[index++] = printf("%5hd|\n", s[3]);
	t[index++] = printf("%-5hd|\n", s[3]);
	t[index++] = printf("%--5hd|\n", s[3]);
	t[index++] = printf("%+hd|\n", s[2]);
	t[index++] = printf("% hd|\n", s[2]);
	t[index++] = printf("% hd|\n", s[3]);
	t[index++] = printf("%-#hx|\n", s[3]);	
	return (t);
}

int		*test_5(void)
{
	int *t = ft_get_tab(NB_TEST);
	/*int s[] = {123, 456, 789, -123};
	size_t	index = 0;
	intmax_t max = INT32_MAX;
	
	printf("\n======================\n%s\n======================\n", "test_5");
	t[index++] = printf("0 - %#-X|\n", s[1]);
	t[index++] = printf("1 - %0-5X|\n", s[1]);
	t[index++] = printf("2 - %#5d|\n", s[1]);
	t[index++] = printf("3 - %#5x|\n", s[1]);
	t[index++] = printf("4 - %-+5d|\n", s[3]);
	t[index++] = printf("5 - %#0X|\n", s[1]);
	t[index++] = printf("6 - %hhd|\n", s[1]);
	t[index++] = printf("7 - %lld|\n", s[1]);
	t[index++] = printf("8 - %lhd|\n", s[1]);
	t[index++] = printf("9 - %hld|\n", s[1]);
	t[index++] = printf("10 - %h h d|\n", s[1]);
	t[index++] = printf("11 - %hhd|\n", s[1]);
	t[index++] = printf("12 - %h h d|\n", s[0]);
	t[index++] = printf("13 - %hhd|\n", s[0]);
	t[index++] = printf("14 - % h h d|\n", s[0]);
	t[index++] = printf("15 - % hhd|\n", s[0]);
	t[index++] = printf("16 - %+jd\n", max);
	t[index++] = printf("17 - %+jd\n", max);
	t[index++] = printf("18 - %5.5 h h d\n", s[1]);
	t[index++] = printf("19 - % 5.5h h d\n", s[1]);
	t[index++] = printf("20 - % 5.5hhd\n", s[1]);
	t[index++] = printf("21 - %5.5 h h d\n", s[1]);	
	t[index++] = printf("21 - %05 h h d\n", s[1]);		*/
	return (t);
}

int		main(void)
{
	int		*t = 0;
	size_t	i;
	/*
	t = test_1();
	printf("\n======================\n%s\n======================\n", "res 1");	
	for (i = 0; i < NB_TEST; i++)
		if (t[i] != 0)
			printf("%4zu:%4d\n", i, t[i]);
	free(t);
	t = test_2();
	printf("\n======================\n%s\n======================\n", "res 2");	
	for (i = 0; i < NB_TEST; i++)
		if (t[i] != 0)
			printf("%4zu:%4d\n", i, t[i]);
	free(t);
	t = test_3();
	printf("\n======================\n%s\n======================\n", "res 3");	
	for (i = 0; i < NB_TEST; i++)
		if (t[i] != 0)
			printf("%4zu:%4d\n", i, t[i]);
	free(t);
	t = test_4();
	printf("\n======================\n%s\n======================\n", "res 4");	
	for (i = 0; i < NB_TEST; i++)
		if (t[i] != 0)
			printf("%4zu:%4d\n", i, t[i]);
	free(t);*/
	t = test_5();
	printf("\n======================\n%s\n======================\n", "res 5");	
	for (i = 0; i < NB_TEST; i++)
		if (t[i] != 0)
			printf("%4zu:%4d\n", i, t[i]);
	free(t);
/*	printf("\n======================\n%s\n======================\n", "test");	
	printf("%jld\n", (intmax_t)LONG_MAX);
	printf("%hld\n", (intmax_t)LONG_MAX);
	printf("%kd\n", (intmax_t)LONG_MAX);
	printf("%llkd\n", (intmax_t)LONG_MAX);		*/
	return (0);
}
