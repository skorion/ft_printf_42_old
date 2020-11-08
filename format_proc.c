/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 03:15:07 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/03 21:19:32 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_proc(t_print *print, va_list list_param)
{
	size_t len;

	if (print->minus == 1 && print->zero == 1)
		print->zero = -1;
	set_stars(print, list_param);
	ft_strdel(&(print->printed));
	len = (print->width < 1) ? 1 : print->width;
	if ((print->printed = ft_strnew(len)) == NULL)
	{
		print->printed = NULL;
		print->len_print = 0;
		return (-1);
	}
	if (print->zero == 1)
		ft_memset(print->printed, '0', len);
	else
		ft_memset(print->printed, ' ', len);
	if (print->minus == 1)
		print->printed[0] = '%';
	else
		print->printed[len - 1] = '%';
	print->len_print = len;
	return (1);
}
