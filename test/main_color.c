/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:50:15 by fbenneto          #+#    #+#             */
/*   Updated: 2017/11/30 11:08:00 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

void ft_purstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int main(void)
{
	int rt;
	int len;

	rt = printf("%s%s%s\t%s%s%s\n", CYAN, "bonjour", RESET, RED, "toi", RESET);
	len = strlen(CYAN) + strlen("bonjour") + strlen(RESET) + strlen(RED) + strlen("toi") + strlen(RESET) + strlen("\t\n");
	printf("res : %d %d\n", rt, len);
	printf("{cyan}%s{eoc}\t{red}%s{eoc}\n", "bonjour", "toi") ;
	ft_purstr(CYAN);
	ft_purstr("bonjour");
	ft_purstr(RESET);
	ft_purstr("\n");
	return 0;
}
