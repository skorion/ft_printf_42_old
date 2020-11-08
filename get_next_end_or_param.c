/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_end_or_param.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:17:58 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 07:36:21 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		get_next_end_or_param(char *format, size_t start)
{
	size_t end;

	end = start;
	while (format[end] != '\0' && format[end] != '%')
		end = end + 1;
	return (end);
}
