/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 02:55:49 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/01 09:39:15 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_c(t_print *print, va_list list_param)
{
	char	c;
	size_t	len;

	set_stars(print, list_param);
	c = (char)va_arg(list_param, int);
	ft_strdel(&(print->printed));
	len = (print->width < 1) ? 1 : print->width;
	if ((print->printed = ft_strnew(len)) == NULL)
		return (-1);
	ft_memset(print->printed, ' ', len);
	if (print->minus == 1)
		print->printed[0] = c;
	else
		print->printed[len - 1] = c;
	print->len_print = len;
	return (0);
}
