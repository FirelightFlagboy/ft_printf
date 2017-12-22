/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ftprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:11:57 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/04 15:47:24 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

#ifndef NB_TEST
# define NB_TEST 20
#endif

int		*ft_get_tab(size_t len)
{
	int *tab;

	if(!(tab = (int*)malloc(len * sizeof(int))))
		exit(EXIT_FAILURE);
	while (len)
		tab[len--] = 0;
	return (tab);
}

int		*ft_test(int (*f)(char const *s, ...), char *t_type)
{
	int *tab = ft_get_tab(NB_TEST + 1);
	static void *ptr;
	int t[] = {313249263, 883674607};
	printf("---------------------------\n");
	printf("%s\n", t_type);
	printf("---------------------------\n");
	tab[0] = f("0 - bonjour, je suis un test simple\n");
	tab[1] = f("1 - je suis le numero %d\n", 123456789);
	tab[2] = f("2 - le premier char de mon nom est %c\n", 'f');
	tab[3] = f("3 - test aff str : %s", "je suis la phrase en question\n");
	tab[4] = f("4 - %s%d%s%c", "je suis une phrase conpose de ", 4, " mallon", '\n');
	tab[5] = f("5 - test afficher l'adr de ptr :%p\n", &ptr);
	tab[6] = f("6 - test de conv vers hex min :%d = %x\n", t[0], t[0]);
	tab[7] = f("7 - test de conv vers hex maj :%d = %X\n", t[1], t[1]);
	tab[8] = f("8 - test de conv vers octal min :%d = %o\n", t[0], t[0]);
	tab[9] = f("9 - test de conv vers octal long :%d = %O\n", t[1], t[1]);
	tab[10] = f("10 - test dysplay long char 1>%C 2>%C \n", L'f', 14850210);
	tab[11] = f("11 - %S", L"bonjour, je suis une pharse longue\n");
	tab[12] = f("12 - %5%\n");
	return (tab);
}

int main(void)
{
	int *my;
	int *you;
	int i;
	int error;

	setlocale(LC_ALL, "");
	my = ft_test(ft_printf, "ft_printf");
	you = ft_test(printf, "printf");
	printf("---------------------------\n");
	printf("result\n");
	printf("---------------------------\n");
	i = -1;
	error = 0;
	while (++i < NB_TEST)
		if (my[i] != you[i] && (error++) != -1)
			printf("at test %d:\n\tft_printf : %d\n\tprintf : %d\n", i, my[i], you[i]);
	if (error == 0)
		printf("done all test passed with success\n");
	else
		printf("done you have %d error\n", error);
	free(my);
	free(you);
	return 0;
}
