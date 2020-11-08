/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:20:20 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 07:39:32 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			size;
	char		*fixed;
	t_dlist		*dl_print_object;
	va_list		list_param;

	va_start(list_param, format);
	fixed = (char *)format;
	size = 0;
	dl_print_object = NULL;
	read_all(fixed, &dl_print_object, list_param);
	print_answer(&size, &dl_print_object);
	delet_all(&dl_print_object);
	va_end(list_param);
	return (size);
}
