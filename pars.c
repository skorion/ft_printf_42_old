/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 05:36:35 by scorion           #+#    #+#             */
/*   Updated: 2020/07/17 16:19:29 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_this_flag(char c, t_print *obj)
{
	if (c == '+')
		obj->plus = 1;
	if (c == '-')
		obj->minus = 1;
	if (c == ' ')
		obj->white = 1;
	if (c == '#')
		obj->sign = 1;
	if (c == '0')
		obj->zero = 1;
}

void	set_size(t_print *print, size_t ps)
{
	if (ps != 0)
	{
		if (print->printed[ps] == 'h')
		{
			if (print->printed[ps + 1] == 'h')
				print->len = 2;
			else
				print->len = 1;
		}
		if (print->printed[ps] == 'l')
		{
			if (print->printed[ps + 1] == 'l')
				print->len = 4;
			else
				print->len = 3;
		}
		if (print->printed[ps] == 'L')
			print->len = 5;
	}
}

void	set_width(t_print *print, size_t pw)
{
	if (print->printed[pw] == '*')
		print->width = -2;
	if (pw != 0 && print->printed[pw] != '*')
		print->width = ft_atoi(&(print->printed[pw]));
}

void	set_precision(t_print *print, size_t pp)
{
	if (print->printed[pp] == '*')
		print->precision = -2;
	if (pp != 0 && print->printed[pp] != '*')
		print->precision = ft_atoi(&(print->printed[pp]));
}

int		pars(t_print *print)
{
	size_t pw;
	size_t pp;
	size_t lp;
	size_t ps;
	size_t i;

	lp = ft_strlen(print->printed);
	pw = get_pw(print->printed);
	pp = get_pp(print->printed);
	ps = get_ps(print->printed);
	i = 0;
	set_width(print, pw);
	set_precision(print, pp);
	set_size(print, ps);
	print_set_type(print, print->printed[lp - 1]);
	lp = get_lpf(pp, pw, lp);
	while (i < lp)
	{
		if (is_a_flag(print->printed[i]))
			set_this_flag(print->printed[i], print);
		i++;
	}
	return (0);
}
