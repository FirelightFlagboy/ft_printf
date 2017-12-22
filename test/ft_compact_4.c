/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:07:24 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/21 14:25:41 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ft_free_4(char **s1, char **s2, char **s3, char **s4)
{
	free(*s1);
	free(*s2);
	free(*s3);
	free(*s4);
}

char	*ft_compact_4(char **s1, char **s2, char **s3, char **s4)
{
	char	*res;
	char	*r;
	char	*s;
	size_t	len;

	len = strlen(*s1) + strlen(*s2) + strlen(*s3) + strlen(*s4);
	printf("len:%zu", len);
	if (!(res = (char*)malloc((len + 1) * sizeof(char))))
		exit(EXIT_FAILURE);
	r = res;
	s = *s1;
	while (*s)
		*r++ = *s++;
	s = *s2;
	while (*s)
		*r++ = *s++;
	s = *s3;
	while (*s)
		*r++ = *s++;
	s = *s4;
	while (*s)
		*r++ = *s++;
	ft_free_4(s1, s2, s3, s4);
	return (res);
}

int		main(void)
{
	char	*s1 = strdup("bonjour ");
	char	*s2 = strdup("je suis ");
	char	*s3 = strdup("une phrase ");
	char	*s4 = strdup("en 4 partie");
	char	*res = ft_compact_4(&s1, &s2, &s3, &s4);
	int		i = INT32_MIN;

	i = 0;
	printf("|%s|\n", res);
	free(res);
	while (i < 40)
	{
		s1 = strdup("bonjour ");
		s2 = strdup("je suis ");
		s3 = strdup("une phrase ");
		s4 = strdup("en 4 partie");
		res = ft_compact_4(&s1, &s2, &s3, &s4);
		printf("|%s|\n", res);
		free(res);
		i++;
	}
	return (0);
}
