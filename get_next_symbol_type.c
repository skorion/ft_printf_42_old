/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_symbol_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:28:40 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 07:35:26 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_symbol_type(char c)
{
	if (c == 'd' ||
		c == 'i' ||
		c == 'u' ||
		c == 'o' ||
		c == 'x' ||
		c == 'X' ||
		c == 'f' ||
		c == 'F' ||
		c == 'e' ||
		c == 'E' ||
		c == 'g' ||
		c == 'G' ||
		c == 'a' ||
		c == 'A' ||
		c == 'c' ||
		c == 's' ||
		c == 'p' ||
		c == 'n' ||
		c == '%')
		return (1);
	return (-1);
}

size_t		get_next_symbol_type(char *format, size_t start)
{
	size_t end;

	end = start + 1;
	while (is_symbol_type(format[end]) != 1 && format[end] != '\0')
		end++;
	return (end);
}
