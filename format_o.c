/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 03:04:34 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/04 06:39:58 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_o_sta(t_print *print, va_list list_param, unsigned int long long *l)
{
	set_stars(print, list_param);
	ft_strdel(&(print->printed));
	if (print->plus == 1 && print->white == 1)
		print->white = 0;
	if (print->minus == 1 && print->zero == 1)
		print->zero = 0;
	if (print->precision == -1 && print->zero == 1)
		print->precision = print->width;
	if (print->len == 0)
		*l = va_arg(list_param, unsigned int);
	if (print->len == 1)
		*l = (unsigned short)va_arg(list_param, unsigned int);
	if (print->len == 2)
		*l = (unsigned char)va_arg(list_param, unsigned int);
	if (print->len == 3)
		*l = va_arg(list_param, unsigned long int);
	if (print->len == 4 || print->len == 5)
		*l = va_arg(list_param, unsigned long long int);
	print->printed = NULL;
	print->len_print = 0;
}

int		get_octet_numlen(unsigned int long long l)
{
	int len;

	len = 0;
	while (l >= 8)
	{
		l = l / 8;
		len = len + 1;
	}
	return (len + 1);
}

char	*itoa_oct(unsigned int long long l, int prec, int sign)
{
	int		len;
	char	*ans;

	if (!(l == 0 && prec == 0))
	{
		sign = (sign == 1 && l != 0) ? sign : 0;
		len = get_octet_numlen(l) + sign;
		len = (len < prec) ? (prec) : (len);
		if ((ans = ft_strnew(len)) == NULL)
			return (NULL);
		ft_memset(ans, '0', len);
		while (l >= 8)
		{
			ans[len - 1] = '0' + (int)(l % 8);
			l = l / 8;
			len--;
		}
		ans[len - 1] = '0' + (int)(l % 8);
	}
	else
		return ((sign == 1) ? ft_strdup("0") : ft_strnew(1));
	return (ans);
}

int		format_o(t_print *print, va_list list_param)
{
	unsigned int long long	l;
	char					*number;
	size_t					len;
	size_t					start_pos;

	set_o_sta(print, list_param, &l);
	if (!(number = itoa_oct(l, print->precision, print->sign)))
		return (-1);
	len = ft_strlen(number);
	print->len_print = (print->width > 0) ? print->width : 0;
	print->len_print = (print->len_print > len) ? print->len_print : len;
	if (!(print->printed = ft_strnew(print->len_print)))
	{
		ft_strdel(&number);
		print->len_print = 0;
		return (-1);
	}
	ft_memset(print->printed, ' ', print->len_print);
	start_pos = (print->minus == 1) ? 0 : print->len_print - len;
	ft_strncpy(&(print->printed[start_pos]), number, len);
	ft_strdel(&number);
	return (0);
}
