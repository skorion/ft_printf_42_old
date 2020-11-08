/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 04:11:48 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 07:28:51 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					formating(t_print *print, va_list list_param)
{
	if (print->type == 'd' || print->type == 'i')
		return (format_di(print, list_param));
	if (print->type == 'u')
		return (format_u(print, list_param));
	if (print->type == 'o')
		return (format_o(print, list_param));
	if (print->type == 'x' || print->type == 'X')
		return (format_x(print, list_param));
	if (print->type == 'f' || print->type == 'F')
		return (format_f(print, list_param));
	if (print->type == 'c')
		return (format_c(print, list_param));
	if (print->type == 's')
		return (format_s(print, list_param));
	if (print->type == 'p')
		return (format_p(print, list_param));
	if (print->type == '%')
		return (format_proc(print, list_param));
	return (1);
}
