/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:34:24 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/21 11:40:52 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

size_t		ft_strlen(char const *s)
{
	size_t l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

size_t		ft_len_nb(uintmax_t nb, size_t len_base)
{
	size_t len;

	len = 0;
	while (nb)
	{
		nb /= len_base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(uintmax_t nb, char *to_base)
{
	char	*res;
	int		len_nb;
	size_t	len_base;

	len_base = ft_strlen(to_base);
	len_nb = ft_len_nb(nb, len_base);
	if (nb == 0)
		len_nb++;
	if (!(res = (char*)malloc((len_nb + 1) * sizeof(char))))
		return (NULL);
	res[len_nb] = 0;
	len_nb--;
	while (len_nb >= 0)
	{
		res[len_nb] = to_base[nb % len_base];
		nb /= len_base;
		len_nb--;
	}
	return (res);
}

char		*ft_itoa(uintmax_t nb)
{
	char	*res;
	int		len_nb;

	len_nb = ft_len_nb(nb, 10);
	if (nb == 0)
		len_nb++;
	if (!(res = (char*)malloc((len_nb + 1) * sizeof(char))))
		return (NULL);
	res[len_nb] = 0;
	len_nb--;
	while (len_nb >= 0)
	{
		res[len_nb] = (nb % 10) + '0';
		nb /= 10;
		len_nb--;
	}
	return (res);
}

int		ft_putstr_fd(char const *s, int fd)
{
	return (write(fd, s, strlen(s)));
}

int		ft_putunbr_fd(uintmax_t n, int fd)
{
	char	*res;
	int		rt;

	if (!(res = ft_itoa(n)))
		exit(EXIT_FAILURE);
	rt = ft_putstr_fd(res, fd);
	free(res);
	return (rt);
}

int			ft_puthex_fd(uintmax_t nb, char high, int fd)
{
	char	*s;
	char	*base;
	int		rt;

	if (high == 0)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (!(s = ft_itoa_base(nb, base)))
		exit(EXIT_FAILURE);
	rt = ft_putstr_fd(s, fd);
	free(s);
	return (rt);
}

int		main()
{
	long long ll = 9223372036854775807;
	while (1)
	{
		ft_putunbr_fd(54321, 1);
		ft_puthex_fd((size_t)&ll, 0, 1);
	}
}
