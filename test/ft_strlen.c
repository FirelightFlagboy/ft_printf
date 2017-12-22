/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 10:07:03 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 10:39:43 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen_1(const char *str)
{
	const char *char_ptr;
	const unsigned long int *longword_ptr;
	unsigned long int longword, himagic, lomagic;
	char	*cp;

	for (char_ptr = str; ((unsigned long int) char_ptr
			& (sizeof (longword) - 1)) != 0;
			 ++char_ptr)
		if (*char_ptr == '\0')
			return char_ptr - str;

	longword_ptr = (unsigned long int *) char_ptr;
	himagic = 0x80808080L;
	lomagic = 0x01010101L;
	if (sizeof (longword) > 4)
		{
			himagic = ((himagic << 16) << 16) | himagic;
			lomagic = ((lomagic << 16) << 16) | lomagic;
		}
	if (sizeof (longword) > 8)
		abort ();
	for (;;)
	{
		longword = *longword_ptr++;

		if (((longword - lomagic) & ~longword & himagic) != 0)
		{
			cp = (char *) (longword_ptr - 1);

			if (cp[0] == 0)
				return cp - str;
			if (cp[1] == 0)
				return cp - str + 1;
			if (cp[2] == 0)
				return cp - str + 2;
			if (cp[3] == 0)
				return cp - str + 3;
			if (sizeof (longword) > 4)
			{
				if (cp[4] == 0)
					return cp - str + 4;
				if (cp[5] == 0)
					return cp - str + 5;
				if (cp[6] == 0)
					return cp - str + 6;
				if (cp[7] == 0)
					return cp - str + 7;
			}
		}
	}
}

size_t	ft_strlen_2(const char *str)
{
	char	*s;

	s = (char*)str;
	while (*s++);
	return (s - str - 1);
}

size_t	ft_strlen_3(const char *str)
{
	char	*s;
	for (s = (char*)str; *s; s++);
	return (s - str);
}

int		main(void)
{
	double	test_o[2];
	double	test_m[2];
	double	res[2];
	size_t	len1;
	size_t	len2;
	char	*s;

	if (!(s = (char*)malloc((123456789) * sizeof(char))))
		return (0);
	s[123456788] = 0;
	memset(s, 't', 123456788);
	printf("begin test\n");
	test_o[0] = clock();
	len1 = strlen(s);
	test_o[1] = clock();
	res[0] = (test_o[1] - test_o[0])/CLOCKS_PER_SEC;
	printf("strlen    : %e res:%zu\n",res[0], len1);
	test_m[0] = clock();
	len2 = ft_strlen_3(s);
	test_m[1] = clock();
	res[1] = (test_m[1] - test_m[0])/CLOCKS_PER_SEC;
	printf("ft_strlen : %e res:%zu\n",res[1], len2);
	if (res[0] > res[1])
		printf("you win with  :%e\n", res[0] - res[1]);
	else
		printf("you lose with :%e\n", res[1] - res[0]);
	free(s);
	return (0);
}
