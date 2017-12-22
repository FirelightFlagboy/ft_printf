/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_longchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:15:08 by fbenneto          #+#    #+#             */
/*   Updated: 2017/12/22 12:10:05 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <locale.h>
# include <wchar.h>
# include <unistd.h>

char			*ft_itoa(int n);
char		*ft_convert_base(char *nbr, char *base_from, char *base_to);

int		ft_putlongchar_fd(wchar_t c, int fd)
{
	unsigned char t[11];
	unsigned char tmp;
	int n;
	int nbyte;

	n = 0;
	while (c)
	{
		t[n++] = c % 16;
		t[n] = c / 16;
		c /= 16;
	}
	nbyte = n / 2;
	n--;
	while (n >= 0)
	{
		tmp = t[n] * 16 + t[n - 1];
		write(fd, &tmp, 1);
		n -= 2;
	}
	return (nbyte);
}

int			ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int			ft_putnbr_fd(intmax_t n, int fd)
{
	if (n < 0)
	{
		return (ft_putchar_fd('-', fd) + ft_putnbr_fd(-(n / 10), fd)\
		+ ft_putchar_fd(-(n / 10) % 10, fd));
	}
	if (n > 9)
		return (ft_putnbr_fd(n / 10, fd) + ft_putchar_fd((n % 10) + '0', fd));
	if (n < 10)
		return (ft_putchar_fd(n + '0', fd));
	return (0);
}

static char	*ft_get_char(int len, int n, char s[])
{
	int	utf_bx[] = {0x80, 0xc0, 0xe0, 0xf0, 0xf8};

	if (len == 4)
	{
		s[0] = n / 0x40 / 0x40 / 0x40 + utf_bx[3];
		s[1] = (n / 0x40 / 0x40) % 0x40 + utf_bx[0];
		s[2] = (n / 0x40) % 0x40 + utf_bx[0];
		s[3] = n % 0x40 + utf_bx[0];
	}
	else if (len == 3)
	{
		s[0] = n / 0x40 / 0x40 + utf_bx[2];
		s[1] = (n / 0x40) % 0x40 + utf_bx[0];
		s[2] = n % 0x40 + utf_bx[0];
	}
	else if (len == 2)
	{
		s[0] = n / 0x40 + utf_bx[1];
		s[1] = n % 0x40 + utf_bx[0];
	}
	return (s);
}

static int	ft_p1(char s[], int n, int *len)
{
	if (n >= 0 && n < 0x80)
	{
		*len = 1;
		s[0] = n;
		return (1);
	}
	else if (n < 0x800)
	{
		*len = 2;
		ft_get_char(*len, n, s);
		return (1);
	}
	else if (n < 0x100000)
	{
		*len = 3;
		ft_get_char(*len, n, s);
		return (1);
	}
	*len = 0;
	return (0);
}

int	ft_2unicode(int n)
{
	char s[4];
	int len;

	if (ft_p1(s, n, &len) == -1 && n < 0x20000)
	{
		len = 4;
		ft_get_char(len, n, s);
	}
	if (len == 0)
		return (-1);
	if (MB_CUR_MAX >= len)
		return (write(1, s, (len > 0) ? len : 1));
	return (-1);
}

int	ft_unicode(int n)
{
	int		utf_cp[] = {0x80, 0x800, 0x100000, 0x20000};
	char	s[4];
	int		len;
	int		rt;

	rt = 0;
	if (n >= 0 && n < utf_cp[0])
	{
		len = 1;
		s[0] = n;
	}
	else if (n < utf_cp[1])
	{
		len = 2;
		ft_get_char(len, n, s);
	}
	else if (n < utf_cp[2])
	{
		len = 3;
		ft_get_char(len, n, s);
	}
	else if (n < utf_cp[3])
	{
		len = 4;
		ft_get_char(len, n, s);
	}
	else
		return (-1);
	if (MB_CUR_MAX >= len)
		return (write(1, s, (len > 0) ? len : 1));
	return (-1);
}

int		ft_putlong_str(wchar_t *s)
{
	int rt;
	int tmp;

	rt = 0;
	tmp = 0;
	while (*s)
	{
		if (tmp != -1)
		{
			tmp = ft_unicode(*s);
			rt += tmp;
		}
		else
			ft_unicode(*s);
		s++;
	}
	return ((tmp == -1) ? tmp : rt);
}

int		ft_putchar(int c)
{
	char d = c;
	int rt = write(1, &d, 1);
	if (MB_CUR_MAX == 1 && c >= 0x80)
		rt = -1;
	return (rt);
}
int		ft_check_unicode_char(wchar_t n)
{
	int len;

	if (n >= 0 && n <= 0x80)
		len = 1;
	else if (n < 0x800)
		len = 2;
	else if (n < 0x10000)
		len = 3;
	else if (n < 0x200000)
		len = 4;
	else
		len = 5;
	if (len <= MB_CUR_MAX)
		return (0);
	return (-1);
}

int		main(void)
{
	wchar_t p = L'☢';
	// setlocale(LC_ALL, "");
	printf("%zu\n", write(1, &p, 1));
	printf("%d\n", printf("%c", p));
	// printf(" tada % d\n", printf("☢"));
	// printf(" tada % d\n", printf("sfhlghsldnvlsk"));
	// printf(" tada % d\n", printf("sfhlghsldnvlsk"));
	// printf(" tada % d\n", printf("sfhlghsldnvlsk"));
	// printf(">res %d\n", printf("%c", p));
	// printf(" tada % d\n", printf("☢"));
	// printf(" tada % d\n", printf("sfhlghsldnvlsk"));
	// printf(" tada % d\n", printf("sfhlghsldnvlsk"));
	// printf(" tada % d\n", printf("sfhlghsldnvlsk"));
	// printf("\t % d\n", printf(NULL));
	// printf(">res %d\n", printf("bonjour %C", p));
	// printf(">res %d\n", printf("bonjour %lc", p));
	// printf("\tres : %d\n", printf("%lc", L'☢'));
	// printf("%d\n", ft_check_unicode_char(L'Ξ'));
	// printf(" %d\n", ft_putchar(L'Ξ'));
	// printf(" %d\n", printf("%c", L'Ξ'));
}
