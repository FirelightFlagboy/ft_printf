/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:27:10 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/18 10:49:32 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_len_unicode(wchar_t n)
{
	if (n >= 0 && n < 0x80)
		return (1);
	if (n < 0x800)
		return (2);
	if (n < 0x100000)
		return (3);
	if (n < 0x20000)
		return (4);
	return (-1);
}

size_t	ft_strlen_unicode(wchar_t *s)
{
	int	len;
	int		i;
	char	res;

	len = 0;
	i = -1;
	res = 0;
	if (!s)
		return (0);
	while (s[++i])
	{
		res = ft_len_unicode(s[i]);
		// printf("l%d:%d\n", i, res);
		if (res > 0)
			len += res;
	}
	// printf("len:%d\n", len);
	return (len);
}

int		main(void)
{
	// char *s = "bonjour";
	wchar_t *p = L"bonjour";

	// ft_strlen_unicode((wchar_t*)s);
	printf("15 - [youprintf] |%lls|\n", "BON☢JOUR");
	printf("16 - [youprintf] |%ls|\n", "BON☢JOUR");
	printf("17 - [youprintf] |%lls|\n", L"BON☢JOUR");
	printf("18 - [youprintf] |%ls|\n", L"BON☢JOUR");

	ft_strlen_unicode(p);
	return (0);
}
