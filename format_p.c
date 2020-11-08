/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgeorge <xgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 03:13:28 by xgeorge           #+#    #+#             */
/*   Updated: 2020/08/07 06:56:30 by xgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_p_sta(t_print *print, va_list list_param, unsigned int long long *l)
{
	set_stars(print, list_param);
	ft_strdel(&(print->printed));
	print->sign = 1;
	print->plus = 0;
	print->white = 0;
	print->zero = 0;
	print->len = 4;
	*l = va_arg(list_param, unsigned long long);
}

int		get_hex_numlen_p(unsigned int long long l)
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

char	*itoa_hex_p(unsigned int long long l, int prec, int sign)
{
	int		len;
	char	*ans;

	len = get_hex_numlen_p(l);
	len = (len < prec) ? (prec) : (len);
	if (l == 0 && prec == 0)
		len = 0;
	len = len + ((sign == 1) ? sign : 0) * 2;
	if ((ans = ft_strnew(len)) == NULL)
		return (NULL);
	ft_memset(ans, '0', len);
	if (!(l == 0 && prec == 0))
	{
		while (l >= 16)
		{
			ans[len - 1] = (l % 16 < 10) ? ('0' + l % 16) : ('a' + l % 16 - 10);
			l = l / 16;
			len--;
		}
		ans[len - 1] = (l % 16 < 10) ? ('0' + l % 16) : ('a' + l % 16 - 10);
	}
	if (sign == 1)
		ans[1] = 'x';
	return (ans);
}

int		format_p(t_print *print, va_list list_param)
{
	unsigned int long long	l;
	char					*number;
	size_t					len;
	size_t					start_pos;

	set_p_sta(print, list_param, &l);
	if (!(number = itoa_hex_p(l, print->precision, print->sign)))
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
	ft_strdel(&number);
	return (0);
}
