/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 04:08:08 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 07:23:51 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_stars(t_print *print, va_list list_param)
{
	if (print->width == -2)
	{
		print->width = va_arg(list_param, int);
		if (print->width < 0)
		{
			print->width = print->width * -1;
			print->minus = 1;
		}
	}
	if (print->precision == -2)
		print->precision = va_arg(list_param, int);
	if (print->precision < 0)
		print->precision = -1;
}
