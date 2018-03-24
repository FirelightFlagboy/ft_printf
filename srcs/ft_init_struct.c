/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:54:56 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/24 11:33:10 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init_color_name(void *data)
{
	t_color *t;

	t = data;
	t[0].color_name = "{eoc}";
	t[1].color_name = "{red}";
	t[2].color_name = "{cyan}";
	t[3].color_name = "{green}";
	t[4].color_name = "{yellow}";
	t[5].color_name = "{blue}";
	t[6].color_name = "{magenta}";
	t[7].color_name = "{white}";
	t[8].color_name = "{black}";
	t[9].color_name = "{bold}";
	t[10].color_name = "{dim}";
	t[11].color_name = "{underline}";
	t[12].color_name = "{blink}";
	t[13].color_name = "{inverted}";
	t[14].color_name = "{hidden}";
	t[15].color_name = "{Bred}";
	t[16].color_name = "{Bgreen}";
	t[17].color_name = "{Byellow}";
	t[18].color_name = "{Bblue}";
	t[19].color_name = "{Bpurple}";
	t[20].color_name = "{Bcyan}";
	t[21].color_name = "{Bwhite}";
}

void		ft_init_color_str(void *data)
{
	t_color *t;

	t = data;
	t[0].color_str = "\x1b[0m";
	t[1].color_str = "\x1b[31m";
	t[2].color_str = "\x1b[36m";
	t[3].color_str = "\x1b[32m";
	t[4].color_str = "\x1b[33m";
	t[5].color_str = "\x1b[34m";
	t[6].color_str = "\x1b[35m";
	t[7].color_str = "\x1b[37m";
	t[8].color_str = "\x1b[30m";
	t[9].color_str = "\x1b[1m";
	t[10].color_str = "\x1b[2m";
	t[11].color_str = "\x1b[4m";
	t[12].color_str = "\x1b[5m";
	t[13].color_str = "\x1b[7m";
	t[14].color_str = "\x1b[8m";
	t[15].color_str = "\x1b[41m";
	t[16].color_str = "\x1b[42m";
	t[17].color_str = "\x1b[43m";
	t[18].color_str = "\x1b[44m";
	t[19].color_str = "\x1b[45m";
	t[20].color_str = "\x1b[46m";
	t[21].color_str = "\x1b[47m";
}
