/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:11:00 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 14:20:27 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		main(void)
{
	char	s[50];
	char	*t;

	ft_printf("here %s\n", "yo");
	ft_dprintf(2, "here %s\n", "ya");
	ft_fprintf(stderr, "nano %s\n", "ye");
	ft_sprintf(s, "test %s\n", "un test");
	ft_printf("%s", s);
	ft_snprintf(s, 1, "test %s\n", "un test");
	ft_printf("%s\n", s);
	ft_asprintf(&t, "bonjour je suis une test %s\n", "lol");
	ft_printf("%s", t);
	return (0);
}
