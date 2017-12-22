/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 08:36:30 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/13 16:28:17 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_convert_base(char *nbr, char *base_from, char *base_to);

long long	ft_to_base10(char *nbr, char *base_f, int len_nbr, int len_b);

char		*ft_to_base_xx(long long nb, char *base_to, char c);

int			ft_base_is_correct(char *base, int *l_b);

char		*ft_strrev(char *str);

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int nb;
	int l_b;
	int i;
	int j;

	if (!(ft_base_is_correct(base_to, &l_b)
	&& ft_base_is_correct(base_from, &l_b)))
		return (NULL);
	i = (nbr[0] == '-' || nbr[0] == '+') ? 0 : -1;
	while (nbr[++i] && (nb = 1) != 0)
	{
		j = -1;
		while (base_from[++j])
			nb = (base_from[j] != nbr[i]) ? nb : 0;
		if (nb)
			return (NULL);
	}
	while (nbr[nb])
		nb++;
	return (ft_strrev(ft_to_base_xx(ft_to_base10(nbr, base_from, nb, l_b + 1)
	, base_to, *nbr)));
}

long long	ft_to_base10(char *nbr, char *base_f, int len_nbr, int len_b)
{
	int			i;
	long long	vpow;
	int			temp;

	if (len_nbr < 1)
		return (0);
	vpow = 1;
	i = -1;
	len_nbr += (*nbr == '-') ? -1 : 0;
	nbr += (*nbr == '-' || *nbr == '+') ? 1 : 0;
	while (base_f[++i])
		if (base_f[i] == *nbr)
			break ;
	temp = len_nbr;
	while (temp-- > 1)
		vpow *= len_b;
	return (i * vpow + ft_to_base10(nbr + 1, base_f, len_nbr - 1, len_b));
}

char		*ft_to_base_xx(long long nb, char *base_to, char c)
{
	int			len_base;
	char		*result;
	int			i;
	int			j;

	len_base = 0;
	i = (c == '-' || nb == 0) ? 0 : -1;
	while (base_to[len_base])
		len_base++;
	result = malloc(33 * sizeof(char));
	result[0] = (c == '-') ? '-' : '0';
	result[0] = (nb == 0) ? base_to[0] : result[0];
	while (nb > 0 && (j = -1) != -2)
	{
		result[++i] = base_to[(nb % len_base)];
		nb /= (len_base);
	}
	i++;
	result[i++] = '\0';
	return (result);
}

int			ft_base_is_correct(char *base, int *l_b)
{
	int i;
	int j;

	i = -1;
	while (base[++i])
		*l_b = i;
	i = -1;
	while (base[++i])
	{
		j = i;
		while (base[++j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
		}
	}
	if (i < 1)
		return (0);
	return (1);
}

char		*ft_strrev(char *str)
{
	int		len_str;
	int		i;
	char	temp;

	len_str = 0;
	i = (str[0] == '-') ? 1 : 0;
	while (str[len_str])
		len_str++;
	len_str--;
	while (i < len_str)
	{
		temp = str[i];
		str[i] = str[len_str];
		str[len_str] = temp;
		i++;
		len_str--;
	}
	return (str);
}
