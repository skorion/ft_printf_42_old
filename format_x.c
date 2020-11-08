/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 03:06:12 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/04 03:03:25 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_h_sta(t_print *print, va_list list_param, unsigned int long long *l)
{
	set_stars(print, list_param);
	ft_strdel(&(print->printed));
	if (print->plus == 1 && print->white == 1)
		print->white = 0;
	if (print->minus == 1 && print->zero == 1)
		print->zero = 0;
	if (print->minus == 1 && print->zero == 1)
		print->zero = 0;
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
	print->sign = (print->sign == 1 && *l == 0) ? 0 : print->sign;
	if ((print->zero == 1) && (print->precision == -1))
		print->precision = print->width - ((print->sign == 1) ? 2 : 0);
	print->printed = NULL;
}

int		get_hex_numlen(unsigned int long long l)
{
	int len;

	len = 0;
	while (l >= 16)
	{
		l = l / 16;
		len = len + 1;
	}
	return (len + 1);
}

char	*itoa_hex(unsigned int long long l, int prec, int sign)
{
	int		len;
	char	*ans;

	if (!(l == 0 && prec == 0))
	{
		len = get_hex_numlen(l);
		len = (len < prec) ? (prec) : (len);
		len = len + ((sign == 1) ? sign : 0) * 2;
		if ((ans = ft_strnew(len)) == NULL)
			return (NULL);
		ft_memset(ans, '0', len);
		while (l >= 16)
		{
			ans[len - 1] = (l % 16 < 10) ? ('0' + l % 16) : ('a' + l % 16 - 10);
			l = l / 16;
			len--;
		}
		ans[len - 1] = (l % 16 < 10) ? ('0' + l % 16) : ('a' + l % 16 - 10);
		if (sign == 1)
			ans[1] = 'x';
	}
	else
		return (ft_strnew(1));
	return (ans);
}

char	*ft_strup(char *str)
{
	size_t index;

	index = 0;
	while (str[index])
	{
		str[index] = ft_toupper(str[index]);
		index++;
	}
	return (str);
}

int		format_x(t_print *print, va_list list_param)
{
	unsigned int long long	l;
	char					*number;
	size_t					len;
	size_t					start_pos;

	set_h_sta(print, list_param, &l);
	if (!(number = itoa_hex(l, print->precision, print->sign)))
		return (-1);
	len = ft_strlen(number);
	print->len_print = (print->width > 0) ? print->width : 0;
	print->len_print = (print->len_print > len) ? print->len_print : len;
	if (!(print->printed = ft_strnew(print->len_print)))
	{
		ft_strdel(&number);
		print->len_print = 0;
		return (0);
	}
	ft_memset(print->printed, ' ', print->len_print);
	start_pos = (print->minus == 1) ? 0 : print->len_print - len;
	ft_strncpy(&(print->printed[start_pos]), number, len);
	if (print->type == 'X')
		print->printed = ft_strup(print->printed);
	ft_strdel(&number);
	return (0);
}
