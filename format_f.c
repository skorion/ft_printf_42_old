/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 03:10:11 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 06:51:21 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_start_f(t_print *print, va_list list_param,
											long double *value, char *znak)
{
	set_stars(print, list_param);
	ft_strdel(&print->printed);
	if (print->len == 5 || print->len == 4)
		*value = va_arg(list_param, long double);
	else
		*value = (long double)va_arg(list_param, double);
	if ((print->minus == 1) && (print->zero == 1))
		print->zero = 0;
	if ((print->plus == 1) && (print->white == 1))
		print->white = 0;
	*znak = (print->white == 1) ? ' ' : '?';
	*znak = (print->plus == 1) ? '+' : *znak;
	*znak = ((*value < 0) || (1 / *value == -1 * INFINITY)) ? '-' : *znak;
	*value = (*value < 0) ? *value * -1 : *value;
}

int		set_number_2(t_print *print, char znak, char *number, size_t size)
{
	size_t	star_pos;

	print->len_print = (znak == '?') ? size : size + 1;
	if (print->width > 0)
		print->len_print = ((unsigned long)print->width > print->len_print)
											? print->width : print->len_print;
	if (!(print->printed = ft_strnew(print->len_print)))
	{
		ft_strdel(&number);
		print->len_print = 0;
		return (-1);
	}
	if (print->zero == 1)
		ft_memset(print->printed, '0', print->len_print);
	else
		ft_memset(print->printed, ' ', print->len_print);
	if (print->minus == 1)
		star_pos = (znak != '?') ? 1 : 0;
	else
		star_pos = print->len_print - size;
	ft_strncpy(&(print->printed[star_pos]), number, size);
	if (znak != '?')
		print->printed[(print->zero == 1) ? 0 : star_pos - 1] = znak;
	ft_strdel(&number);
	return (1);
}

int		set_number(t_print *print, long double value, char znak)
{
	size_t	size;
	char	*number;
	char	*tmp;

	if (!(number = ft_gcvt(value, print->precision)))
		return (-1);
	size = ft_strlen(number);
	if ((print->sign == 1) && (print->precision == 0))
	{
		size = size + 1;
		if (!(tmp = ft_strnew(size)))
		{
			ft_strdel(&number);
			return (-1);
		}
		ft_strncpy(tmp, number, size - 1);
		tmp[size - 1] = '.';
		ft_strdel(&number);
		number = tmp;
	}
	return (set_number_2(print, znak, number, size));
}

int		format_f_nan_and_inf(t_print *print, long double value, char znak)
{
	char		*num;
	size_t		size;
	int			col;

	if (!(num = get_nan_and_inf(value, znak)))
		return (-1);
	col = ft_strlen(num);
	size = (col > print->width) ? col : print->width;
	if (!(print->printed = ft_strnew(size)))
	{
		ft_strdel(&num);
		return (-1);
	}
	ft_memset(print->printed, ' ', size);
	(print->minus == 1) ? ft_strncpy(print->printed, num, col)
			: ft_strncpy(&(print->printed[size - col]), num, col);
	print->len_print = size;
	ft_strdel(&num);
	return (1);
}

int		format_f(t_print *print, va_list list_param)
{
	long double	value;
	char		znak;

	set_start_f(print, list_param, &value, &znak);
	print->len_print = 0;
	print->printed = NULL;
	if (ft_is_a_inf_or_nan(value) == 1)
		return (format_f_nan_and_inf(print, value, znak));
	if ((set_number(print, value, znak)) == -1)
		return (-1);
	return (1);
}
