/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 03:11:59 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/01 08:17:09 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_copu_for_arg(t_print *print, va_list list_param)
{
	print->poiter = va_arg(list_param, char *);
	ft_strdel(&(print->printed));
	if (print->poiter == NULL)
	{
		if ((print->poiter = ft_strdup("(null)\0")) == NULL)
			return (-1);
		print->type = 'j';
	}
	return (1);
}

int	format_s(t_print *print, va_list list_param)
{
	size_t	starpos;

	set_stars(print, list_param);
	if (string_copu_for_arg(print, list_param) == -1)
	{
		print->len_print = 0;
		return (-1);
	}
	if (print->precision < 0 ||
				(unsigned long)print->precision > ft_strlen(print->poiter))
		print->precision = (int)ft_strlen(print->poiter);
	if (print->precision > print->width)
		print->width = print->precision;
	if (print->width > 0)
		print->len_print = (unsigned long)print->width;
	if (!(print->printed = (char *)ft_strnew(print->len_print)))
	{
		print->len_print = 0;
		return (-1);
	}
	ft_memset(print->printed, ' ', print->len_print);
	starpos = (print->minus == 1) ? 0 : print->width - print->precision;
	ft_strncpy(&(print->printed[starpos]), print->poiter, print->precision);
	print->len_print = ft_strlen(print->printed);
	return (0);
}
