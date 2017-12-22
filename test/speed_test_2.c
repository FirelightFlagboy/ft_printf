/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_test_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 11:28:55 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/21 11:39:57 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdint.h>
#include <time.h>

int ft_printf(char const *str, ...);

int main(void)
{
	clock_t time;
	time = clock();
	long long ll = 9223372036854775807;
	while (1)
	{
		ft_printf("%x %X %p %20.15d\n", 505, 505, &ll, 54321);
	}
	return (0);
}
