/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rtval.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:50:19 by fbenneto          #+#    #+#             */
/*   Updated: 2017/11/30 10:55:28 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *s = "bonjour";
	int rt;

	rt = printf("%s", s);
	printf(">%d\n", rt);
	rt = printf("holla");
	printf(">%d\n", rt);
	rt = printf("%d", rt);
	printf(">%d\n", rt);
	rt = printf("%d", 10);
	printf(">%d\n", rt);
	rt = printf("%d", 123456789);
	printf(">%d\n", rt);
	return 0;
}
