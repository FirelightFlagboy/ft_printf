/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:50:18 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/08 12:56:37 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include<stdint.h>
#include <wchar.h>

int main(void)
{
	int d = 456;
	int i = 123;
	int o = 156;
	int x = 255;
	int X = 227;
	unsigned int u = 4294967295;
	char c = 'c';
	char *s = "bj";
	// wchar_t *S = (wchar_t*)"coca";
	double f = 3.14;
	double e = 1.25;
	double E = 1.23456789;
	double g = 987.45613;
	double G = 98746512.5456;
	int *p = &i;

	// int
	printf("\nint\n");
	printf("%d\n", d);
	printf("%i\n", i);
	printf("%i%%\n", i);
	// octal
	printf("\noctal\n");
	printf("%o\n", o);
	// hex
	printf("\nhex\n");
	printf("%x\n", x);
	printf("%X\n", X);
	// unsigned int
	printf("\nunsigned int\n");
	printf("%u\n", u);
	// char
	printf("\nchar\n");
	printf("%c\n", c);
	// string
	printf("\nstring\n");
	printf("%s\n", s);
	printf("%p\n", s);
	printf("return val:%d", printf(">%S\n", (wchar_t*)s));
	// double
	printf("\ndouble\n");
	printf("%f\n", f);
	printf("%e\n", e);
	printf("%E\n", E);
	printf("%g\n", g);
	printf("%G\n", G);
	//	ptr
	printf("\nptr\n");
	printf("%p\n", p);
	// other
	printf("\nother\n");
	printf("%%\n");
	printf("%% bonjour\n");
	printf("bonsoir %%\n");
	printf("%n\n", p);
	printf("%n bonjour\n", p);
	printf("bonsoir %n\n", p);
	//test
	return 0;
}
